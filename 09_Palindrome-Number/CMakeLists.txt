cmake_minimum_required(VERSION 3.10.0)
project(09_Palindrome-Number VERSION 0.1.0 LANGUAGES C CXX)

add_executable(09_Palindrome-Number main.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
