# SPDX-License-Identifier: BSL-1.0+ OR BlueOak-1.0.0+

enable_testing()
find_package(doctest REQUIRED)

add_executable(std_version_tests test.cpp)
target_link_libraries(std_version_tests doctest::doctest std_version)

doctest_discover_tests(std_version_tests)

