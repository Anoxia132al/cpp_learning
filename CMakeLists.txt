cmake_minimum_required(VERSION 3.20)

project(Learning VERSION 0.1 LANGUAGES CXX)

# ---------------- 全局编译设置 ----------------
set(CMAKE_CXX_STANDARD 17)          # C++ 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 必须支持该标准
set(CMAKE_CXX_EXTENSIONS OFF)       # 不使用 g++ 私有扩展

# 生成 compile_commands.json, 供 VS Code IntelliSense / clangd 读取
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 默认使用 Debug 构建 (带调试信息, 可用 gdb 调试)
# 需要优化版本时: cmake -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# 可执行文件统一输出到项目根目录的 bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 多配置生成器 (VS / Ninja Multi-Config) 也输出到同一位置, 避免 bin/Debug/ 这类子目录
foreach(cfg IN ITEMS DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${cfg} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach()

# ---------------- 可执行目标 ----------------
# 源文件显式列出: 新增 .cpp 时在这里加一行, 不会意外把试验代码编进来
add_executable(Learning
    src/Main.cpp
    src/Sales_item.cpp
    src/else_random.cpp
    src/pointer_const.cpp
    src/string_vector.cpp
)

# 头文件目录: 这样 #include "Sales_item.h" 可以直接写, 不用 ../include/
target_include_directories(Learning PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 警告选项
if(MSVC)
    target_compile_options(Learning PRIVATE /W4)
else()
    target_compile_options(Learning PRIVATE -Wall -Wextra -Wpedantic)
endif()
