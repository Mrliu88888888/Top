#include "connpool.h"
#include <iostream>
#include "ConnectionPool.h"

using std::cout;
using std::endl;

class Light
{
public:
    explicit Light() {}

    inline std::string status() { return "ok"; }
};

namespace connpool {
void run()
{
    ConnectionPool<Light> connPool(3);

    cout << "addConnection: " << connPool.addConnection(new Light()) << endl;
    auto conn = connPool.getConnection();
    conn      = connPool.getConnection();
    if (nullptr == conn) {
        cout << "nullptr" << endl;
    }
    else {
        cout << "status: " << conn->status() << endl;
    }
    cout << "freeConnection: " << connPool.freeConnection(conn) << endl;
}
}   // namespace connpool
