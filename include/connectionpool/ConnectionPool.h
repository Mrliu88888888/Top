#pragma once

#include <map>
#include <shared_mutex>
#include <concurrentqueue/blockingconcurrentqueue.h>

template<typename T> class ConnectionPool
{
public:
    explicit ConnectionPool(const int timeoutSec)
        : timeoutSec_(timeoutSec)
    {}

    T* getConnection(const std::string& id = "")
    {
        std::shared_lock<std::shared_mutex> lck(mutConnectionMap_);

        const auto iter = connectionMap_.find(id);
        if (iter == connectionMap_.end()) {
            return nullptr;
        }
        T* conn = nullptr;
        return iter->second.wait_dequeue_timed(conn, std::chrono::seconds(timeoutSec_)) ? conn
                                                                                        : nullptr;
    }

    bool freeConnection(T* conn, const std::string& id = "")
    {
        std::shared_lock<std::shared_mutex> lck(mutConnectionMap_);

        const auto iter = connectionMap_.find(id);
        if (iter == connectionMap_.end()) {
            return false;
        }
        return iter->second.enqueue(conn);
    }

    size_t sizeApprox(const std::string& id = "")
    {
        std::shared_lock<std::shared_mutex> lck(mutConnectionMap_);

        const auto iter = connectionMap_.find(id);
        return (iter == connectionMap_.end()) ? (size_t)-1 : iter->second.size_approx();
    }

    bool addConnection(T* conn, const std::string& id = "")
    {
        std::unique_lock<std::shared_mutex> lck(mutConnectionMap_);

        return connectionMap_[id].enqueue(conn);
    }

private:
    std::map<std::string, moodycamel::BlockingConcurrentQueue<T*>> connectionMap_;
    std::shared_mutex                                              mutConnectionMap_;

private:
    const int timeoutSec_;
};
