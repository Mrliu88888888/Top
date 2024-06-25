#pragma once

#include <string>

#ifdef _WIN32
#    ifdef SQLITERPC_EXPORTS
#        define SQLITERPC_API __declspec(dllexport)
#    else
#        define SQLITERPC_API __declspec(dllimport)
#    endif
#else
define SQLITERPC_API
#endif

class SQLITERPC_API LiteRPC
{
public:
    explicit LiteRPC();
    ~LiteRPC();

    int  connect(const std::string_view& url);
    void close();

    int exec(const std::string_view& sql, std::string* output);
};
