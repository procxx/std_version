# SPDX-License-Identifier: BSL-1.0+ OR BlueOak-1.0.0+

cmake_minimum_required(VERSION 3.20)
project(lbstd_version VERSION 0.0.1 LANGUAGES CXX)

option(LBSTD_VERSION_NS_NAME "The enclosing namespace for all classes of std_version" "lbstd")
option(LBSTD_VERSION_ENABLE_FMTLIB "Enable fmtlib formatters integration" ON)
option(LBSTD_VERSION_ENABLE_STDFORMAT "Enable std::format integration")
option(LBSTD_VERSION_ENABLE_TESTS "Enable tests" ON)

if (LBSTD_VERSION_ENABLE_FMTLIB)
  find_package(fmt REQUIRED)
endif()

add_library(lbstd_version INTERFACE)
target_include_directories(lbstd_version INTERFACE "${CMAKE_SOURCE_DIR}/include")
target_compile_features(lbstd_version INTERFACE cxx_std_20)

if (LBSTD_VERSION_ENABLE_TESTS)
  enable_testing()
  add_subdirectory("tests")
endif()

