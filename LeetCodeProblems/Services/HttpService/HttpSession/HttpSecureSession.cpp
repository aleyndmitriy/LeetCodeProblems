//
//  HttpSecureSession.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 30.08.23.
//

#include "HttpSecureSession.hpp"

HttpSecureSession::HttpSecureSession(boost::asio::any_io_executor ex, boost::asio::ssl::context& ctx):HttpSession(),resolver_(ex), stream_(ex, ctx)
{
    
}

void HttpSecureSession::run(char const* host, char const* port, char const* path, std::initializer_list<boost::urls::param_view> params, boost::beast::http::verb type, int version)
{
    // Set SNI Hostname (many hosts need this to handshake successfully)
    if (!SSL_set_tlsext_host_name(stream_.native_handle(), host))
    {
        boost::beast::error_code ec{ static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category() };
        std::cerr << ec.message() << "\n";
        return;
    }
    req_.version(version);
    req_.method(type);
    boost::url url;
    
    url.set_port(boost::core::string_view(port));
    url.set_host(boost::core::string_view(host));
    url.set_path(boost::core::string_view(path));
    url.set_params(params);
    req_.target(url.c_str());
    //req_.set(boost::beast::http::field::host, host);
    req_.set(boost::beast::http::field::accept, "application/json");
    req_.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req_.prepare_payload();
    // Look up the domain name
    resolver_.async_resolve(host, port, boost::beast::bind_front_handler(&HttpSecureSession::on_resolve,
            shared_from_this()));
}

void HttpSecureSession::on_resolve(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type results)
{
    if (ec)
        return fail(ec, "resolve");
    // Set a timeout on the operation
    boost::beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));
    // Make the connection on the IP address we get from a lookup
    boost::beast::get_lowest_layer(stream_).async_connect(results, boost::beast::bind_front_handler(&HttpSecureSession::on_connect,shared_from_this()));
}

void HttpSecureSession::on_connect(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type::endpoint_type)
{
    if (ec)
        return fail(ec, "connect");
    // Perform the SSL handshake
    stream_.async_handshake(boost::asio::ssl::stream_base::client, boost::beast::bind_front_handler(&HttpSecureSession::on_handshake,shared_from_this()));
}

void HttpSecureSession::on_handshake(boost::beast::error_code ec)
{
    if (ec)
        return fail(ec, "handshake");
    // Set a timeout on the operation
    boost::beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));
    // Send the HTTP request to the remote host
    boost::beast::http::async_write(stream_, req_, boost::beast::bind_front_handler(&HttpSecureSession::on_write, shared_from_this()));
}

void HttpSecureSession::on_write(boost::beast::error_code ec, std::size_t bytes_transferred)
{
    boost::ignore_unused(bytes_transferred);
    if (ec)
        return fail(ec, "write");
    // Receive the HTTP response
    boost::beast::http::async_read(stream_, buffer_, res_, boost::beast::bind_front_handler(&HttpSecureSession::on_read, shared_from_this()));
}

void HttpSecureSession::on_read(boost::beast::error_code ec, std::size_t bytes_transferred)
{
    boost::ignore_unused(bytes_transferred);
    if (ec)
        return fail(ec, "read");
    // Write the message to standard out
    std::cout << boost::beast::buffers_to_string(res_.body().data()) << std::endl;
    std::string str{ boost::beast::buffers_to_string(res_.body().data()) };
        boost::property_tree::ptree jsontree;
        //https://stackoverflow.com/questions/43725302/reading-json-with-boost-property-tree
        //https://www.cochoy.fr/boost-property-tree/
        std::basic_istringstream<typename boost::property_tree::ptree::key_type::value_type> stream{ str };
        boost::property_tree::read_json(stream, jsontree);
        BOOST_FOREACH(boost::property_tree::ptree::value_type & v, jsontree) {
            std::string data = v.second.get_value<std::string>();
            std::cout << data << " ";
        }
        std::cout << std::endl;
    // Set a timeout on the operation
    boost::beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));
    // Gracefully close the stream
    stream_.async_shutdown(boost::beast::bind_front_handler(&HttpSecureSession::on_shutdown, shared_from_this()));
}

void HttpSecureSession::on_shutdown(boost::beast::error_code ec)
{
    if (ec == boost::asio::error::eof)
    {
        // Rationale:
        // http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error
        ec = {};
    }
    if (ec)
        return fail(ec, "shutdown");

    // If we get here then the connection is closed gracefully
}

HttpSecureSession::HttpSecureSession(HttpSecureSession&& session):HttpSession(std::move(session)),resolver_(std::move(session.resolver_)),stream_(std::move(session.stream_))
{
   
}

HttpSecureSession& HttpSecureSession::operator=(HttpSecureSession&& session)
{
    if(this==&session) {
        return *this;
    }
    this->resolver_ = std::move(session.resolver_);
    this->stream_ = std::move(session.stream_);
    this->HttpSession::operator=(std::move(session));
    return *this;
}

HttpSecureSession::~HttpSecureSession() {
    
}
