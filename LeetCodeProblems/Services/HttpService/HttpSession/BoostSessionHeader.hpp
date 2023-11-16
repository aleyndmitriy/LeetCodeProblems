//
//  BoostSessionHeader.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 19.08.23.
//

#ifndef BoostSessionHeader_hpp
#define BoostSessionHeader_hpp

#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/certify/extensions.hpp>
#include <boost/certify/https_verification.hpp>
#include <boost/foreach.hpp>
#include <boost/url.hpp>
#include <openssl/ssl.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <future>

void fail(boost::beast::error_code ec, char const* what);

#endif /* BoostSessionHeader_h */
