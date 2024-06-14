#include "pcm.h"

#include <iostream>
#include <string>
#include <vector>

#include <ThreadPool.h>

#include <concurrentqueue/blockingconcurrentqueue.h>

namespace pcm {
/// @brief 数据
class Data
{
public:
    std::string msg;
};

Producer::Producer() {}

Data Producer::work()
{
    static unsigned long long count = 0;
    Data                      d;
    d.msg = std::to_string(count);
    ++count;
    return d;
}

Consumer::Consumer() {}

void Consumer::work(const Data& data)
{
    std::cout << std::this_thread::get_id() << ": " << data.msg << std::endl;
}

void run()
{
    std::vector<Producer*> vecProducer(3);
    std::vector<Consumer*> vecConsumer(3);

    for (int i = 0; i < vecProducer.size(); ++i) {
        vecProducer[i] = new Producer();
    }
    for (int i = 0; i < vecConsumer.size(); ++i) {
        vecConsumer[i] = new Consumer();
    }

    moodycamel::BlockingConcurrentQueue<Data> q;

    ThreadPool thpool(std::thread::hardware_concurrency() / 2);

    for (auto& c : vecConsumer) {
        thpool.enqueue([&q, &c]() {
            for (;;) {
                Data d;
                q.wait_dequeue(d);
                c->work(d);
            }
        });
    }

    for (;;) {
        for (auto& p : vecProducer) {
            q.enqueue(p->work());
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
}   // namespace pcm
