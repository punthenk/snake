cmake_minimum_required(VERSION 3.16)
project(snake CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH /opt/homebrew)
endif()

if(DEFINED ENV{RAYLIB_ROOT})
    list(APPEND CMAKE_PREFIX_PATH $ENV{RAYLIB_ROOT})
endif()

find_package(raylib 5.5 REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(snake ${SOURCES})

target_include_directories(snake PRIVATE src)
target_link_libraries(snake PRIVATE raylib)

add_custom_target(run
    COMMAND snake
    DEPENDS snake
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
