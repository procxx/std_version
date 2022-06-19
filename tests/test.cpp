#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <version/version.hpp>

#define GENERATE_COMPARISON_TEST_CASES(classname, val_less, val_eq, val_greater) \
TEST_CASE("Comparison tests for " #classname) \
{\
	classname ver{(val_eq)}, ver_eq{(val_eq)}, ver_less{(val_less)}, ver_greater{(val_greater)}; \
	SUBCASE("equal") \
	{ \
		REQUIRE_EQ(ver, ver_eq); \
	} \
	\
	SUBCASE("not equal") \
	{ \
		REQUIRE_NE(ver, ver_greater); \
	} \
	\
	SUBCASE("greater") \
	{ \
		REQUIRE(ver_greater > ver); \
	} \
	\
	SUBCASE("less") \
	{ \
		REQUIRE(ver_less < ver); \
	} \
	\
	SUBCASE("greater or equal") \
	{ \
		REQUIRE(ver >= ver_eq); \
		REQUIRE(ver_greater >= ver); \
	} \
	\
	SUBCASE("less or equal") \
	{ \
		REQUIRE(ver >= ver_less); \
		REQUIRE(ver <= ver_eq); \
	} \
}

GENERATE_COMPARISON_TEST_CASES(STD_VERSION_NS ::simple_version, 1, 2, 3)

