#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <version/version.hpp>

#include <type_traits>

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

static_assert(std::is_same_v<::STD_VERSION_NS::version_traits<::STD_VERSION_NS::simple_version>::value_type, std::size_t>);

TEST_CASE("Testing tuple interface of simple_version")
{
	using namespace STD_VERSION_NS;
	constexpr simple_version ver{43};
	static_assert(ver.value() == 43);
	static_assert(std::get<0>(ver) == 43);
	static_assert(std::tuple_size_v<simple_version> == 1);
	static_assert(std::is_same_v<std::tuple_element_t<0, simple_version>, simple_version::value_type>);
}
