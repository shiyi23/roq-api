/* Copyright (c) 2017-2022, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/format.h>

#include <cassert>
#include <string_view>
#include <type_traits>

#include "roq/compat.h"

namespace roq {

//! Enumeration of execution types
struct ROQ_PACKED ExecutionInstruction final {
  //! helper
  enum type_t : uint8_t {
    UNDEFINED = 0x0,
    PARTICIPATE_DO_NOT_INITIATE = 0x1,  //!< Cancel if order would have executed on placement (i.e. not as maker)
    CANCEL_IF_NOT_BEST = 0x2,           //!< Cancel if order can not be placed at best price
    DO_NOT_INCREASE =
        0x4,  //!< Order may only reduce net position, order quantity can automatically be reduced by exchange
    DO_NOT_REDUCE = 0x8,  //!< Order can not be partially filled, aka. all-or-none (AON) orders
  };

  constexpr ExecutionInstruction() = default;

  // cppcheck-suppress noExplicitConstructor
  constexpr ExecutionInstruction(type_t type)  // NOLINT (allow implicit)
      : type_(type) {}

  explicit constexpr ExecutionInstruction(uint8_t type) : type_(validate(type)) {}

  constexpr operator type_t() const { return type_; }

  constexpr std::string_view name() const {
    using namespace std::literals;
    switch (type_) {
      case type_t::UNDEFINED:
        break;
      case type_t::PARTICIPATE_DO_NOT_INITIATE:
        return "PARTICIPATE_DO_NOT_INITIATE"sv;
      case type_t::CANCEL_IF_NOT_BEST:
        return "CANCEL_IF_NOT_BEST"sv;
      case type_t::DO_NOT_INCREASE:
        return "DO_NOT_INCREASE"sv;
      case type_t::DO_NOT_REDUCE:
        return "DO_NOT_REDUCE"sv;
      default:
        assert(false);
    }
    return "UNDEFINED"sv;
  }

  constexpr operator std::string_view() const { return name(); }

 protected:
  constexpr type_t validate(uint8_t type) {
    auto result = static_cast<type_t>(type);
    switch (result) {
      case type_t::UNDEFINED:
      case type_t::PARTICIPATE_DO_NOT_INITIATE:
      case type_t::CANCEL_IF_NOT_BEST:
      case type_t::DO_NOT_INCREASE:
      case type_t::DO_NOT_REDUCE:
        return result;
      default:
        assert(false);
        return type_t::UNDEFINED;
    }
  }

 private:
  type_t type_ = type_t::UNDEFINED;
};

}  // namespace roq

template <>
struct std::is_enum<roq::ExecutionInstruction> : std::true_type {};

template <>
struct std::underlying_type<roq::ExecutionInstruction> {
  using type = uint8_t;
};

template <>
struct fmt::formatter<roq::ExecutionInstruction> {
  template <typename Context>
  constexpr auto parse(Context &ctx) {
    return std::begin(ctx);
  }
  template <typename Context>
  auto format(const roq::ExecutionInstruction &value, Context &ctx) {
    using namespace std::literals;
    return fmt::format_to(ctx.out(), "{}"sv, value.name());
  }
};
