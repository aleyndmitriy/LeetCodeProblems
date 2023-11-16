//
//  HttpSession.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 30.08.23.
//

#ifndef HttpSession_hpp
#define HttpSession_hpp

#include "BoostSessionHeader.hpp"

class HttpSession
{
public:
    HttpSession():uuid_(boost::uuids::random_generator()()){};
    HttpSession(const HttpSession& session) = delete;
    HttpSession& operator=(const HttpSession& session) = delete;
    HttpSession(HttpSession&& session):uuid_(std::move(session.uuid_)),buffer_(std::move(session.buffer_)),req_(std::move(session.req_)),res_(std::move(session.res_)){};
    HttpSession& operator=(HttpSession&& session);
    virtual void run(char const* host, char const* port, char const* path, std::initializer_list<boost::urls::param_view> params, boost::beast::http::verb type, int version) = 0;
    virtual void on_resolve(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type results) = 0;
    virtual void on_connect(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type::endpoint_type) = 0;
    virtual void on_handshake(boost::beast::error_code ec) = 0;
    virtual void on_write(boost::beast::error_code ec, std::size_t bytes_transferred) = 0;
    virtual void on_read(boost::beast::error_code ec, std::size_t bytes_transferred) = 0;
    virtual void on_shutdown(boost::beast::error_code ec) = 0;
    std::size_t hash() const {return boost::uuids::hash_value(uuid_);};
    std::string uuidString() const {return boost::uuids::to_string(uuid_);};
    boost::uuids::uuid uuid() const {return uuid_;};
    [[nodiscard]] bool operator==(const HttpSession& rhs) const { return this->uuid_ == rhs.uuid_;};
    [[nodiscard]] std::partial_ordering operator<=>(const HttpSession& rhs) const;
    virtual ~HttpSession(){};
protected:
    boost::uuids::uuid uuid_;
    boost::beast::flat_buffer buffer_; // (Must persist between reads)
    boost::beast::http::request<boost::beast::http::string_body> req_;
    boost::beast::http::response<boost::beast::http::dynamic_body> res_;
};

HttpSession& HttpSession::operator=(HttpSession&& session)
{
    if(this == &session) {
        return *this;
    }
    this->uuid_ = std::move(session.uuid_);
    this->buffer_ = std::move(session.buffer_);
    this->req_ = std::move(session.req_);
    this->res_ = std::move(session.res_);
    return *this;
}


std::partial_ordering HttpSession::operator<=>(const HttpSession& rhs) const
{
    if(this->uuid_ == rhs.uuid_) {
        return std::partial_ordering::equivalent;
    } else if(this->uuid_ < rhs.uuid_) {
        return std::partial_ordering::less;
    } else if(this->uuid_ > rhs.uuid_) {
        return std::partial_ordering::greater;
    } else {
        return std::partial_ordering::unordered;
    }
}

class HttpSessionHash {
public:
    std::size_t operator()(const HttpSession& session) const {
        return session.hash();
    };
};

#endif /* HttpSession_hpp */
