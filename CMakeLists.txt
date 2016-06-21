# Copyright (c) 2016 Sebastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT) 
cmake_minimum_required(VERSION 2.6)
project(coveralls-test)

add_compile_options(-Wall -Wextra -fkeep-inline-functions)

message (STATUS "Using GCov instrumentation")
add_compile_options(-coverage)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    message (WARNING "GCov instrumentation works best in Debug mode")
endif ()

# Print CXX FLAGS
message (STATUS "CMAKE_CXX_FLAGS                '${CMAKE_CXX_FLAGS}'")
if (MSVC)
    message (STATUS "CMAKE_CXX_FLAGS_DEBUG          '${CMAKE_CXX_FLAGS_DEBUG}'")
    message (STATUS "CMAKE_CXX_FLAGS_RELEASE        '${CMAKE_CXX_FLAGS_RELEASE}'")
    message (STATUS "CMAKE_CXX_FLAGS_RELWITHDEBINFO '${CMAKE_CXX_FLAGS_RELWITHDEBINFO}'")
    message (STATUS "CMAKE_CXX_FLAGS_MINSIZEREL     '${CMAKE_CXX_FLAGS_MINSIZEREL}'")
else (NOT MSVC)
    if     (CMAKE_BUILD_TYPE STREQUAL Debug)
        message (STATUS "CMAKE_CXX_FLAGS_DEBUG          '${CMAKE_CXX_FLAGS_DEBUG}'")
    elseif (CMAKE_BUILD_TYPE STREQUAL RelWithDebInfo)
        message (STATUS "CMAKE_CXX_FLAGS_RELWITHDEBINFO '${CMAKE_CXX_FLAGS_RELWITHDEBINFO}'")
    elseif (CMAKE_BUILD_TYPE STREQUAL MinSizeRel)
        message (STATUS "CMAKE_CXX_FLAGS_MINSIZEREL     '${CMAKE_CXX_FLAGS_MINSIZEREL}'")
    else ()
        message (STATUS "CMAKE_CXX_FLAGS_RELEASE        '${CMAKE_CXX_FLAGS_RELEASE}'")
    endif ()
endif ()

# Print definitions
get_directory_property (DirDefs     COMPILE_DEFINITIONS)
message (STATUS "Definitions :                  '${DirDefs}'")
get_directory_property (DirOptions  COMPILE_OPTIONS)
message (STATUS "Options     :                  '${DirOptions}'")
get_directory_property (DirIncludes INCLUDE_DIRECTORIES)
message (STATUS "Includes    :                  '${DirIncludes}'")


# build the test app
add_executable(coveralls-test src/main.cpp src/obj.cpp src/obj.h)

# add a "test" target:
enable_testing()

# run the test
add_test(CoverageTest coveralls-test)

