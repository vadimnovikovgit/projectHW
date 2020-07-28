cmake_minimum_required(VERSION 3.12)
project(HomeNetworkProject)
include_directories(headers)

set(HEADERS "headers/*.h")
FILE(GLOB SOURCES src/*.cpp)
add_executable(HomeNetworkProject ${SOURCES})

set(CMAKE_CXX_STANDARD 17)
set (BOOST_ROOT "/usr/include/boost")

set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)


find_package (Boost)
#cmake toolchain

include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

target_link_libraries(HomeNetworkProject -lcurl -lboost_system -lboost_thread -lpthread -lboost_regex)
