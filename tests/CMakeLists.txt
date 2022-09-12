# SPDX-FileCopyrightText: 2022 leha-bot and contributors
#
# SPDX-License-Identifier: BSL-1.0 OR BlueOak-1.0.0

find_package(doctest REQUIRED)

include(doctest)

add_executable(lbstd_version_tests test.cpp)
target_link_libraries(lbstd_version_tests doctest::doctest lbstd_version)

add_executable(lbstd_version_print_ns print_ns.cpp)
target_link_libraries(lbstd_version_print_ns lbstd_version)

# The manual test for namespace passthrough.
set(LBSTD_VERSION_CMAKE_NS_PASSTHROUGH "CMake custom library namespace (\"${LBSTD_VERSION_NS}::\") passthrough in C++ code")
add_test(NAME "${LBSTD_VERSION_CMAKE_NS_PASSTHROUGH}" COMMAND lbstd_version_print_ns)
set_tests_properties("${LBSTD_VERSION_CMAKE_NS_PASSTHROUGH}" PROPERTIES
  PASS_REGULAR_EXPRESSION "${LBSTD_VERSION_NS}"
  LABELS "buildsystem"
)

# Auto-discoverable doctest unit tests
doctest_discover_tests(lbstd_version_tests ADD_LABELS ON)

