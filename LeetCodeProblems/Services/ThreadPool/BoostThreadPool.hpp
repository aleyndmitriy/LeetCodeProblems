//
//  BoostThreadPool.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.10.23.
//

#ifndef BoostThreadPool_hpp
#define BoostThreadPool_hpp

#include"ThreadPoolImpl.hpp"
#include "BoostSessionHeader.hpp"

class BoostThreadPoolImpl final : public ThreadPoolImpl
{
public:
    BoostThreadPoolImpl();
    BoostThreadPoolImpl(std::size_t num_threads);
    BoostThreadPoolImpl(const BoostThreadPoolImpl& src) = delete;
    BoostThreadPoolImpl& operator=(const BoostThreadPoolImpl& src) = delete;
    BoostThreadPoolImpl(BoostThreadPoolImpl&& src) = delete;
    BoostThreadPoolImpl& operator=(BoostThreadPoolImpl&& src) = delete;
    void Submit(FunctionWrapper&& func) override;
    void Stop() override;
    void Join() override;
    ~BoostThreadPoolImpl() override;
private:
    boost::asio::thread_pool threadPool;
};



#endif /* BoostThreadPool_hpp */
