#pragma once

namespace pcm {
class Data;

/// @brief 生产者
class Producer
{
public:
    explicit Producer();

    Data work();
};

/// @brief 消费者
class Consumer
{
public:
    explicit Consumer();

    void work(const Data& data);
};

void run();
}   // namespace pcm

#define ENABLE_PCM
