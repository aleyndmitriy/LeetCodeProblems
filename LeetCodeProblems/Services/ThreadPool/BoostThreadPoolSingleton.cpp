//
//  BoostThreadPoolSingleton.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 23.11.23.
//

#include "BoostThreadPoolSingleton.hpp"
#include "BoostThreadPool.hpp"


std::unique_ptr<ThreadPool> pool_ = std::make_unique<ThreadPool>(std::make_unique<BoostThreadPoolImpl>());
