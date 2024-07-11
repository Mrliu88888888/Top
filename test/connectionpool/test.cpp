#include <gtest/gtest.h>
#include "ConnectionPool.h"

class Conn
{};

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
    ConnectionPool<Conn> connPool(0);

    std::thread([&connPool]() {
        for (int i = 0; i < 100; ++i) {
            connPool.addConnection(new Conn());
        }
    }).detach();

    std::thread([&connPool]() {
        bool flag = false;
        for (;;) {
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
    }).detach();

    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        const auto size = connPool.sizeApprox();
        std::cout << size << std::endl;
        if (size == 0) {
            break;
        }
    }

    ASSERT_TRUE(true);
}
