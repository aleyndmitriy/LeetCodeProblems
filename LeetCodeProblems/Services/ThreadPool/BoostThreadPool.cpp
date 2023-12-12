//
//  BoostThreadPool.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 23.11.23.
//

#include "BoostThreadPool.hpp"
BoostThreadPoolImpl::BoostThreadPoolImpl():ThreadPoolImpl{}, threadPool{}
{

}

BoostThreadPoolImpl::BoostThreadPoolImpl(std::size_t num_threads):ThreadPoolImpl{ num_threads }, threadPool{ num_threads }
{

}

BoostThreadPoolImpl::~BoostThreadPoolImpl()
{
    threadPool.stop();
    threadPool.join();
}

void BoostThreadPoolImpl::Submit(FunctionWrapper&& func)
{
    boost::asio::post(threadPool, std::move(func));
}

void BoostThreadPoolImpl::Stop() {
    threadPool.stop();
}

void BoostThreadPoolImpl::Join() {
    threadPool.join();
}
