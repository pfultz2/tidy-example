cmake_minimum_required(VERSION 3.5)
project(tidy-example)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(ClangTidy)

enable_clang_tidy(
    CHECKS 
        *
    ERRORS
        *
    HEADER_FILTER
        ".*hpp"
    ANALYZE_TEMPORARY_DTORS ON
)

include(CppCheck)
enable_cppcheck(
    CHECKS 
        all
    SUPPRESS 
        ConfigurationNotChecked
        unmatchedSuppression
    FORCE
    SOURCES
        ./
)

add_executable(example example.cpp)
target_compile_options(example PUBLIC -std=c++11)
clang_tidy_check(example)
