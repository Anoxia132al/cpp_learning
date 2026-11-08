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

# 跨章节共用的头文件放这里; 章节私有头文件与源文件同目录, 无需额外 include 路径
set(COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/common)

# ---------------- 目标辅助函数 ----------------
# 创建学习用可执行目标, 并统一加上公共头文件目录和警告选项
function(add_lesson_target name)
    add_executable(${name} ${ARGN})
    target_include_directories(${name} PRIVATE ${COMMON_INCLUDE_DIR})
    if(MSVC)
        target_compile_options(${name} PRIVATE /W4)
    else()
        target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

# stl 章节: 一个练习就是一个带 main() 的 .cpp, 对应一个独立可执行文件
function(add_stl_exercise name)
    add_lesson_target(stl_${name} src/stl/${name}.cpp)
endfunction()

# ---------------- 可执行目标 ----------------
# basics: 一个 Main.cpp 调用各模块
add_lesson_target(Learning
    src/basics/Main.cpp
    src/basics/Sales_item.cpp
    src/basics/else_random.cpp
    src/basics/pointer_const.cpp
    src/basics/string_vector_arry.cpp
    src/basics/lk_expression.cpp
    src/basics/bt_statement.cpp
    src/basics/pt_function.cpp
)

# basics 的私有头文件统一放在章节内的 include/ 下
target_include_directories(Learning PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/basics/include
)

# stl: 新增练习时, 新建 src/stl/<name>.cpp 后在这里加一行
add_stl_exercise(hello_stl)
# add_stl_exercise(vector_basics)
