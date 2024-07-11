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
