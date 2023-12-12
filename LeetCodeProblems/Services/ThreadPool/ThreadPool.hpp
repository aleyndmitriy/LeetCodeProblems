//
//  ThreadPool.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.10.23.
//

#ifndef ThreadPool_hpp
#define ThreadPool_hpp
#include "ThreadPoolImpl.hpp"
#import <concepts>
#import <future>


class ThreadPool final {
public:
    ThreadPool(std::unique_ptr<ThreadPoolImpl>&& threadPool_);
    ThreadPool(const ThreadPool& src) = delete;
    ThreadPool& operator=(const ThreadPool& src) = delete;
    ThreadPool(ThreadPool&& src) = delete;
    ThreadPool& operator=(ThreadPool&& src) = delete;
    ~ThreadPool();
    /*template<typename Arg, std::invocable<Arg> Func> std::future<typename std::invoke_result<Func, Arg>::type> Submit(Func&& f, Arg&& arg);*/
    template<typename... Arguments, std::invocable<Arguments...> Func> std::future<typename std::invoke_result<Func, Arguments...>::type> Submit(Func&& f, Arguments&&... args);
private:
    std::unique_ptr<ThreadPoolImpl> threadPool;
};



#endif /* ThreadPool_hpp */
