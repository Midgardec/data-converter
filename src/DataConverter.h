//
// Created by valie on 15.06.2023.
//

#pragma once

#include <atomic>
#include <thread>
#include "ISource.h"
#include "ISink.h"

class DataConverter {
public:
    DataConverter(ISource* source, ISink* sink);

    void start();
    void stop();

private:
    ISource* source_;
    ISink* sink_;
    std::atomic<bool> running_;
    std::thread thread_;

    void run();
};
