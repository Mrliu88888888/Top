# Top
我的奇思妙想

# 起源
关于我为什么启动这个项目，因某晚觉得c++新建一个项目真的好麻烦，也没有好用的脚手架，linux和windows项目差别也是巨大，还得去找各种第三方工具库等等麻烦事儿
所以我准备在这个项目里使用cmake作为跨平台，收录我自己认为比较好的代码风格，编译模板，第三方库，以及自己常用的工具类

# 项目结构
```txt
Top
├── cmake
├── doc
├── example
├── include
├── script
├── src
├── test
├── ThirdParty
├── .clang-format
├── .clang-tidy
├── .editorconfig
├── CMakeLists.txt
├── CMakePresets.json
├── LICENSE
├── README.md
└── vcpkg.json
```

# 开发环境
* [Qt](https://www.qt.io/)
* [CMake](https://cmake.org/)
* [ninja](https://github.com/ninja-build/ninja)
* [vcpkg](https://github.com/microsoft/vcpkg)
## Linux代理
```bash
export proxy="http://192.168.80.1:7890"
export http_proxy=$proxy
export https_proxy=$proxy
```
## Ubuntu
```bash
sudo apt install build-essential cmake ninja-build pkg-config
```

# 使用
## 下载
```bash
git clone --recursive https://github.com/Mrliu88888888/Top.git
# or
git clone https://github.com/Mrliu88888888/Top.git
cd Top
git submodule update --init --recursive
```
## 编译
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
## 测试
```bash
ctest
```
## 打包
```bash
cpack
```
## 自动化脚本
Windows编译脚本: [build.bat](script/build.bat)<br>
Linux编译脚本: [build.sh](script/build.sh)

# 致谢
* [Visual Studio 2022](https://visualstudio.microsoft.com/zh-hans/vs/)
* [Qt](https://www.qt.io/)
* [CMake](https://cmake.org/)
* [ninja](https://github.com/ninja-build/ninja)
* [vcpkg](https://github.com/microsoft/vcpkg)
* [Git](https://www.git-scm.com/)
* [LLVM](https://clang.llvm.org/)
* [GoogleTest](https://github.com/google/googletest)
* [spdlog](https://github.com/gabime/spdlog)
* [fmt](https://github.com/fmtlib/fmt)
* [concurrentqueue](https://github.com/cameron314/concurrentqueue)
* [ThreadPool](https://github.com/progschj/ThreadPool)
* [simpleini](https://github.com/brofield/simpleini)
* [mimalloc](https://github.com/microsoft/mimalloc)
* [libiconv](https://www.gnu.org/software/libiconv/)
* [QtCipherSqlitePlugin](https://github.com/devbean/QtCipherSqlitePlugin)
* [grpc](https://github.com/grpc/grpc)
* [protobuf](https://github.com/protocolbuffers/protobuf)
* [nlohmann_json](https://github.com/nlohmann/json)
* [opencv](https://github.com/opencv/opencv)
