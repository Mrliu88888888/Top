#include "App.h"

#include <locale>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include "top/config/config.h"
#include "top/config/version.h"

namespace lm {
namespace app {
int SingleApp()
{
    int fd = -1;
    {
        char filename[128] = {0};
        sprintf(filename, "/tmp/%s.pid", APP_NAME);
        fd = open(filename, O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
        if (fd < 0) {
            return -200;
        }
    }

    {
        struct flock fl = {0};
        fl.l_type       = F_WRLCK;
        fl.l_start      = 0;
        fl.l_whence     = SEEK_SET;
        fl.l_len        = 0;

        if (fcntl(fd, F_SETLK, &fl) == -1) {
            close(fd);
            return 1;
        }
        else {
            char buf[16] = {0};
            if (ftruncate(fd, 0) == -1) {
                return -201;
            }
            sprintf(buf, "%ld", (long)getpid());
            if (write(fd, buf, strlen(buf)) == -1) {
                return -202;
            }
            return 0;
        }
    }
}

bool ChangeWorkPath()
{
    char       path[1024] = {0};
    const auto len        = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len == -1) {
        return false;
    }
    path[len] = '\0';
    auto ch   = strrchr(path, '/');
    if (ch == NULL) {
        return false;
    }
    *ch = '\0';
    return chdir(path) == 0;
}
}   // namespace app
}   // namespace lm
