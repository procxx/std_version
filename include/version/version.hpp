#include <algorithm>
#include <compare>
#include <cstddef>
#include <memory>

#ifndef STD_VERSION_NS
#  define STD_VERSION_NS lbstd
#endif

namespace STD_VERSION_NS {

template <typename Impl>
class version {
public:
  Impl value_p; // intentionally public for constexprness
  using value_type = Impl;

  constexpr version(value_type&& t) noexcept : value_p{std::forward<value_type>(t)} {}

  constexpr auto operator<=>(const version<Impl>& ver_) const = default;

  constexpr decltype(auto) value() const noexcept { return value_p; }
};

template <typename Version>
struct version_traits {
  using value_type = typename Version::value_type;
};

template <typename Version1, typename Version2>
constexpr auto operator<=>(const Version1& ver_1, const Version2& ver_2) noexcept {
  return ver_1.value() <=> ver_2.value();
}

using simple_version = version<std::size_t>;

} // namespace STD_VERSION_NS

namespace std {

template <>
struct tuple_size<::STD_VERSION_NS::simple_version> : std::integral_constant<std::size_t, 1> {};

template <std::size_t I>
struct tuple_element<I, ::STD_VERSION_NS::simple_version> {
  static_assert(I < 2, "simple_version contains only one component");
  using type = ::STD_VERSION_NS::version_traits<::STD_VERSION_NS::simple_version>::value_type;
};

template <std::size_t I>
constexpr std::size_t get(const ::STD_VERSION_NS::simple_version& ver) noexcept {
  static_assert(I < std::tuple_size_v<::STD_VERSION_NS::simple_version>, "simple_version contains only one component");
  return ver.value();
}

} // namespace std
