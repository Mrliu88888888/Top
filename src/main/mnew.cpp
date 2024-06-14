#include "mnew.h"

#include <string>
#include <thread>

#include <mimalloc-override.h>
#include <mimalloc-new-delete.h>


// #define ENABLE_PRINT

namespace mnew {
constexpr int kNameSize = 256;

struct CName
{
    explicit CName(const std::string_view& n)
        : name((char*)malloc(kNameSize))
        , size(kNameSize)
    {
        memset(name, '\0', kNameSize);

        strcpy_s(name, n.length() + 1, n.data());
    }
    ~CName()
    {
        free(name);
        size = 0;
    }

#ifdef ENABLE_PRINT
    inline void print() const { printf("name: %s\n", name); }
#else
    inline void print() const {}
#endif

    char* name;
    int   size;
};

struct CXXName
{
    explicit CXXName(const std::string_view& n)
        : name(new char[kNameSize])
        , size(kNameSize)
    {
        memset(name, '\0', kNameSize);

        strcpy_s(name, n.length() + 1, n.data());
    }
    ~CXXName()
    {
        delete[] name;
        size = 0;
    }

#ifdef ENABLE_PRINT
    inline void print() const { printf("name: %s\n", name); }
#else
    inline void print() const {}
#endif

    char* name;
    int   size;
};

void run()
{
    printf("start\n");
    getchar();

    std::thread([]() {
        for (int i = 0; i < 10000; ++i) {
            CXXName(std::to_string(i)).print();
        }
    }).join();

    for (int i = 0; i < 10000; ++i) {
        CName name(std::to_string(i));
        name.print();
    }

    printf("end\n");
    getchar();
}
}   // namespace mnew
