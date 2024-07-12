#include <gtest/gtest.h>
#include "ConnectionPool.h"

using Conn = int;

TEST(connectionpool, all_no_thread)
{
    ConnectionPool<Conn> connPool(0);

    const auto add = connPool.addConnection(new Conn());
    ASSERT_TRUE(add);

    const auto conn = connPool.getConnection();
    ASSERT_TRUE(conn != nullptr);

    const auto conn2 = connPool.getConnection();
    ASSERT_TRUE(conn2 == nullptr);

    const auto free = connPool.freeConnection(conn);
    ASSERT_TRUE(free);
}

TEST(connectionpool, multi_thread)
{
    ConnectionPool<Conn>     connPool(0);
    std::vector<std::thread> thpool;
    std::atomic<bool>        stop  = false;
    const int                thnum = 3;

    for (int i = 0; i < thnum; ++i)
        thpool.emplace_back(std::thread([&connPool, &stop]() {
            for (;;) {
                if (stop) {
                    break;
                }

                connPool.addConnection(new Conn());
            }
        }));

    for (int i = 0; i < thnum; ++i)
        thpool.emplace_back(std::thread([&connPool, &stop]() {
            bool flag = false;
            for (;;) {
                if (stop) {
                    break;
                }

                auto conn = connPool.getConnection();
                if (conn == nullptr) {
                    continue;
                }
                if (flag) {
                    connPool.freeConnection(conn);
                }
                else {
                    delete conn;
                }

                flag = !flag;
            }
        }));

    thpool.emplace_back(std::thread([&connPool, &stop]() {
        for (;;) {
            if (stop) {
                break;
            }

            const auto size = connPool.sizeApprox();
            // printf("conn pool size: %lld\n", size);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }));

    // printf("th pool size: %lld\n", thpool.size());

    std::this_thread::sleep_for(std::chrono::seconds(10));
    stop = true;
    for (auto& th : thpool) {
        th.join();
    }
    for (;;) {
        auto conn = connPool.getConnection();
        if (conn == nullptr) {
            break;
        }
        delete conn;
    }

    ASSERT_TRUE(true);
}

TEST(connectionpool, auto_release)
{
    ConnectionPool<Conn> connPool(0);
    connPool.addConnection(new Conn(10086));

    {
        auto conn = connPool.getConnectionAndAutoRelease();
        ASSERT_EQ(conn.use_count(), 1);

        auto p = conn.get();
        ASSERT_EQ(*p, 10086);

        ASSERT_EQ(connPool.sizeApprox(), 0);
    }
    ASSERT_EQ(connPool.sizeApprox(), 1);
}
