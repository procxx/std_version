#include <algorithm>
#include <compare>
#include <memory>

#ifndef STD_VERSION_NS
#define STD_VERSION_NS lbstd
#endif

namespace STD_VERSION_NS {

template <typename Impl>
class version
{
	Impl value_;
public:
	using value_type = Impl;

	constexpr version(value_type && t) noexcept : value_{std::forward<value_type>(t)} {}

	constexpr auto operator <=> (const version<Impl> &ver_) const = default;

	constexpr decltype(auto) value() const noexcept
	{
		return value_;
	}
};


template <typename Version1, typename Version2>
constexpr auto operator <=> (const Version1 &ver_1, const Version2 &ver_2) noexcept
{
	return ver_1.value() <=> ver_2.value();
}

using simple_version = version<unsigned int>;

} // namespace STD_VERSION_NS

