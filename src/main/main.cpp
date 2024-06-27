#include "top/config/config.h"
#include "top/config/version.h"

#include "App.h"
#include "Log.h"

/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 *
 *
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *            佛祖保佑       永不宕机     永无BUG
 */
int main(int argc, char* argv[])
{
#ifdef _WIN32
    lm::app::AutoDump();
#endif   // _WIN32

    if (!lm::app::ChangeWorkPath()) {
        return 1;
    }

    if (lm::app::SingleApp() != 0) {
        return 2;
    }

    lm::log::Init(STRING_FORMAT("log/{}.log", TOP_NAME), lm::log::LOG_LEVEL_DEBUG, 0, 1);

    LOG_INFO("hello {} [{}]", TOP_NAME, TOP_VERSION);

    return 0;
}
