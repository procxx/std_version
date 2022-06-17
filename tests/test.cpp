#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <version/version.hpp>

TEST_CASE("simple_version")
{
	STD_VERSION_NS ::simple_version sv1{1}, sv2{1};
	REQUIRE_EQ(sv1, sv2);
}
