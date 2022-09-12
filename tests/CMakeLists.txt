# SPDX-FileCopyrightText: 2022 leha-bot and contributors
#
# SPDX-License-Identifier: BSL-1.0 OR BlueOak-1.0.0

find_package(doctest REQUIRED)

include(doctest)

add_executable(lbstd_version_tests test.cpp)
target_link_libraries(lbstd_version_tests doctest::doctest lbstd_version)

doctest_discover_tests(lbstd_version_tests)

