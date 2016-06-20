# Copyright (c) 2016 Sebastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT) 
cmake_minimum_required(VERSION 2.6)
project(coveralls-test)

add_compile_options(-Wall -Wextra)

message (STATUS "Using GCov instrumentation")
add_compile_options(-fprofile-arcs -ftest-coverage)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    message (WARNING "GCov instrumentation works best in Debug mode")
endif ()

# build the test app
add_executable(coveralls-test src/main.cpp)

# add a "test" target:
enable_testing()

# run the test
add_test(CoverageTest coveralls-test)

