// SPDX-FileCopyrightText: 2022 leha-bot and contributors
//
// SPDX-License-Identifier: BSL-1.0 OR BlueOak-1.0.0
//
// This executable is a smoke test for checking the proper namespace customizing via CMake's
// -DLBSTD_VERSION_NS="namespace_name" configure parameter. The main() function just prints the
// actual namespace which will be used in CMake's test check.
#include <iostream>

#include <version/version.hpp>

#define MAKE_STRING(q) #q
#define UNPACK_MACRO(q) q
#define MAKE_STRING_FROM_MACRO(q) MAKE_STRING(q)

int main()
{
	std::cout << MAKE_STRING_FROM_MACRO(LB_STD_VERSION_NS);
	return 0;
}
