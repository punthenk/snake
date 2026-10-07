cmake_minimum_required(VERSION 4.1)
project(snake CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH /opt/homebrew)
endif()

find_package(raylib 5.5 REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(snake ${SOURCES})

target_include_directories(snake PRIVATE src)
target_link_libraries(snake PRIVATE raylib)

if(APPLE)
    target_link_libraries(snake PRIVATE
        "-framework IOKit"
        "-framework Cocoa"
        "-framework OpenGL"
    )
endif()

add_custom_target(run
    COMMAND snake
    DEPENDS snake
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
