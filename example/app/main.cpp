#include "App.h"

int main()
{
    lm::app::AutoDump();
    lm::app::ChangeWorkPath();
    lm::app::SetConsoleCharsetUTF8();
    lm::app::SingleApp();

    return 0;
}
