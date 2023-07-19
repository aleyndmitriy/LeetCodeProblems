//
//  ThreadPool.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 19.05.23.
//

#ifndef ThreadPool_hpp
#define ThreadPool_hpp
#import <thread>
#import <array>
#import <queue>
#import <shared_mutex>

namespace LeetCodeProblems {

template <std::size_t MaxThreads> class ThreadPool {
private:
    mutable std::shared_mutex mutex;
    std::array<std::thread, MaxThreads> threads;
};

};

#endif /* ThreadPool_hpp */
