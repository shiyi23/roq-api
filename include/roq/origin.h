/* Copyright (c) 2017-2022, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/format.h>

#include <cassert>
#include <string_view>
#include <type_traits>

#include <magic_enum.hpp>

#include "roq/compat.h"

namespace roq {

//! Enumeration of origin types
struct ROQ_PACKED Origin final {
  //! helper
  enum type_t : uint8_t {
    UNDEFINED = 0,
    CLIENT,
    GATEWAY,
    BROKER,
    EXCHANGE,
  };

  constexpr Origin() = default;

  // cppcheck-suppress noExplicitConstructor
  constexpr Origin(type_t type)  // NOLINT (allow implicit)
      : type_(type) {}

  explicit constexpr Origin(uint8_t value) : type_(magic_enum::enum_cast<type_t>(value).value_or(type_t::UNDEFINED)) {}

  explicit constexpr Origin(const std::string_view &value)
      : type_(magic_enum::enum_cast<type_t>(value).value_or(type_t::UNDEFINED)) {}

  constexpr operator type_t() const { return type_; }

  constexpr std::string_view name() const { return magic_enum::enum_name(type_); }

  constexpr operator std::string_view() const { return name(); }

  static constexpr auto values() { return magic_enum::enum_values<type_t>(); }

  static constexpr size_t count() { return magic_enum::enum_count<type_t>(); }

  static constexpr Origin from_index(size_t index) { return magic_enum::enum_value<type_t>(index); }

  constexpr size_t to_index() const {
    auto result = magic_enum::enum_index(type_);  // std::optional
    return result.value();                        // note! could throw
  }

 private:
  type_t type_ = type_t::UNDEFINED;
};

}  // namespace roq

template <>
struct std::is_enum<roq::Origin> : std::true_type {};

template <>
struct std::underlying_type<roq::Origin> {
  using type = uint8_t;
};

template <>
struct fmt::formatter<roq::Origin> {
  template <typename Context>
  constexpr auto parse(Context &ctx) {
    return std::begin(ctx);
  }
  template <typename Context>
  auto format(const roq::Origin &value, Context &ctx) {
    using namespace std::literals;
    return fmt::format_to(ctx.out(), "{}"sv, value.name());
  }
};
