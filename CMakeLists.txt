cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 11)
project(googletest_sample)
#get gtest
include(FetchContent)
FetchContent_Declare(googletest
            GIT_REPOSITORY https://github.com/google/googletest
            GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)

if(NOT gtest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletesttest_BUILD_DIR})
endif()

add_library(sumLibrary STATIC LibraryCode.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp sumLibrary)

add_executable(testRunner test.cpp)
target_link_libraries(testRunner sumLibrary gtest_main gmock_main)