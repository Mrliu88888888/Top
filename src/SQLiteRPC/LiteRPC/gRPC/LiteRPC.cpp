#include "LiteRPC.h"
#include "lite.pb.h"
#include <iostream>
using std::cout;
using std::endl;

LiteRPC::LiteRPC()
{
    cout << "LiteRPC::LiteRPC()" << endl;
}

LiteRPC::~LiteRPC()
{
    cout << "LiteRPC::~LiteRPC()" << endl;
    close();
}

int LiteRPC::connect(const std::string_view& url)
{
    cout << "LiteRPC::connect(" << url << ")" << endl;
    return 0;
}

void LiteRPC::close()
{
    cout << "LiteRPC::close()" << endl;
}

int LiteRPC::exec(const std::string_view& sql, std::string* output)
{
    cout << "LiteRPC::exec(" << sql << ", " << output << ")" << endl;
    *output = sql;
    return 0;
}
