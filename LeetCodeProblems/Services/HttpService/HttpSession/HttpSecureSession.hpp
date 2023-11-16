//
//  HttpSecureSession.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 30.08.23.
//

#ifndef HttpSecureSession_hpp
#define HttpSecureSession_hpp

#include "HttpSession.hpp"

class HttpSecureSession final: public HttpSession, public std::enable_shared_from_this<HttpSecureSession> {
private:
    boost::asio::ip::tcp::resolver resolver_;
    boost::beast::ssl_stream<boost::beast::tcp_stream> stream_;
public:
    explicit HttpSecureSession(boost::asio::any_io_executor ex, boost::asio::ssl::context& ctx);
    HttpSecureSession() = delete;
    HttpSecureSession(const HttpSecureSession& session) = delete;
    HttpSecureSession& operator=(const HttpSecureSession& session) = delete;
    HttpSecureSession(HttpSecureSession&& session);
    HttpSecureSession& operator=(HttpSecureSession&& session);
    void run(char const* host, char const* port, char const* path, std::initializer_list<boost::urls::param_view> params, boost::beast::http::verb type, int version) override;
    void on_resolve(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type results) override;
    void on_connect(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type::endpoint_type) override;
    void on_handshake(boost::beast::error_code ec) override;
    void on_write(boost::beast::error_code ec, std::size_t bytes_transferred) override;
    void on_read(boost::beast::error_code ec, std::size_t bytes_transferred)override;
    void on_shutdown(boost::beast::error_code ec) override;
    ~HttpSecureSession() override;
};
#endif /* HttpSecureSession_hpp */
