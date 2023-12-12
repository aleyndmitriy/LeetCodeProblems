//
//  ThreadPool.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 23.11.23.
//

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(std::unique_ptr<ThreadPoolImpl>&& threadPool_) : threadPool{ std::move(threadPool_) } {

}

ThreadPool::~ThreadPool() {
    threadPool->Stop();
    threadPool->Join();
}

/*template<typename Arg, std::invocable<Arg> Func> std::future<typename std::invoke_result<Func, Arg>::type> ThreadPool::Submit(Func&& f, Arg&& arg)
{
    std::packaged_task<typename std::invoke_result<Func, Arg>::type()> task{ std::bind(f,std::forward<Arg>(arg))};
    std::future<typename std::invoke_result<Func, Arg>::type> res{ task.get_future() };
    threadPool->Submit(FunctionWrapper{ std::move(task) });
    return res;
}*/

template<typename... Arguments, std::invocable<Arguments...> Func> std::future<typename std::invoke_result_t<Func, Arguments...>> ThreadPool::Submit(Func&& f, Arguments&&... args)
{
    /*std::packaged_task<typename std::invoke_result<Func, Arguments...>::type()> task{ std::bind_front(f,std::forward<Arguments>(args)...)};
    std::future<typename std::invoke_result<Func, Arguments...>::type> res{ task.get_future() };
    threadPool->Submit(FunctionWrapper{ std::move(task) });*/
    std::future<typename std::invoke_result<Func, Arguments...>::type> res;
    return res;
}

