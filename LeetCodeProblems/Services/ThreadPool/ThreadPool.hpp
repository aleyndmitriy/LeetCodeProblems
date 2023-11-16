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
    template<typename Arg, std::invocable<Arg> Func> std::future<typename std::invoke_result<Func, Arg>::type> Submit(Func&& f, Arg&& arg);
    template<typename... Arguments, std::invocable<Arguments...> Func> std::future<typename std::invoke_result<Func, Arguments...>::type> Submit1(Func&& f, Arguments&&... args);
private:
    std::unique_ptr<ThreadPoolImpl> threadPool;
};

ThreadPool::ThreadPool(std::unique_ptr<ThreadPoolImpl>&& threadPool_) : threadPool{ std::move(threadPool_) } {

}

ThreadPool::~ThreadPool() {
    threadPool.reset();
}

template<typename Arg, std::invocable<Arg> Func> std::future<typename std::invoke_result<Func, Arg>::type> ThreadPool::Submit(Func&& f, Arg&& arg)
{
    std::packaged_task<typename std::invoke_result<Func, Arg>::type()> task{ std::bind(f,std::forward<Arg>(arg))};
    std::future<typename std::invoke_result<Func, Arg>::type> res{ task.get_future() };
    threadPool->Submit(FunctionWrapper{ std::move(task) });
    return res;
}

template<typename... Arguments, std::invocable<Arguments...> Func> std::future<typename std::invoke_result<Func, Arguments...>::type> ThreadPool::Submit1(Func&& f, Arguments&&... args)
{
    std::packaged_task<typename std::invoke_result<Func, Arguments...>::type()> task{ std::bind_front(f,std::forward<Arguments>(args)...)};
    std::future<typename std::invoke_result<Func, Arguments...>::type> res{ task.get_future() };
    threadPool->Submit(FunctionWrapper{ std::move(task) });
    return res;
}


#endif /* ThreadPool_hpp */
