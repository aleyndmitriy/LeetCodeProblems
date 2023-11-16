//
//  ThreadPoolImpl.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 14.11.23.
//

#ifndef ThreadPoolImpl_hpp
#define ThreadPoolImpl_hpp
#include <functional>
#include <memory>

class FunctionWrapper
{
    class ImplBase {
    public:
        virtual void call() = 0;
        virtual ~ImplBase() {};
    };

    std::unique_ptr<ImplBase> _impl;
    template<typename F> class ImplType : public ImplBase {
        F f;
    public:
        ImplType(F&& f_) : f{ std::move(f_) } {};
        void call() override { f(); };
    };
public:
    template<typename T> FunctionWrapper(T&& t) :_impl{ std::make_unique<ImplType<T>>(std::move(t)) } {};
    void operator()() { _impl->call(); };
    FunctionWrapper() = default;
    FunctionWrapper(FunctionWrapper&& rhs) noexcept :_impl{ std::move(rhs._impl) } {} ;
    FunctionWrapper& operator=(FunctionWrapper&& rhs) noexcept { _impl = std::move(rhs._impl); return *this; };
    FunctionWrapper(const FunctionWrapper& rhs) = delete;
    FunctionWrapper& operator=(const FunctionWrapper& rhs) = delete;
};

class ThreadPoolImpl {
public:
    ThreadPoolImpl() {};
    ThreadPoolImpl(std::size_t num_threads) {};
    ThreadPoolImpl(const ThreadPoolImpl& src) = delete;
    ThreadPoolImpl& operator=(const ThreadPoolImpl& src) = delete;
    ThreadPoolImpl(ThreadPoolImpl&& src) = delete;
    ThreadPoolImpl& operator=(ThreadPoolImpl&& src) = delete;
    virtual ~ThreadPoolImpl() {};
    virtual void Submit(FunctionWrapper&& func) = 0;
};

#endif /* ThreadPoolImpl_hpp */
