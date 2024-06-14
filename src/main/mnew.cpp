#include "mnew.h"

#include <mimalloc-override.h>
#include <mimalloc-new-delete.h>



namespace mnew {
constexpr int kNameSize = 256;

struct CName
{
    explicit CName()
        : name((char*)malloc(kNameSize))
        , size(kNameSize)
    {
        memset(name, '\0', kNameSize);
    }
    ~CName()
    {
        free(name);
        size = 0;
    }

    inline void print() const { printf("name: %s\n", name); }

    char* name;
    int   size;
};

struct CXXName
{
    explicit CXXName()
        : name(new char[kNameSize])
        , size(kNameSize)
    {
        memset(name, '\0', kNameSize);
    }
    ~CXXName()
    {
        delete[] name;
        size = 0;
    }

    inline void print() const { printf("name: %s\n", name); }

    char* name;
    int   size;
};

void run()
{
    for (int i = 0; i < 10000; ++i) {
        CName name;
        name.print();
    }
    for (int i = 0; i < 10000; ++i) {
        CXXName name;
        name.print();
    }
}
}   // namespace mnew
