/* Copyright (c) 2017-2023, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include "roq/compat.hpp"

#include <fmt/compile.h>
#include <fmt/format.h>

#include <span>
#include <string_view>

#include "roq/event.hpp"
#include "roq/name.hpp"
#include "roq/position.hpp"
#include "roq/trace.hpp"
#include "roq/update_type.hpp"

namespace roq {

//! Portfolio update  !!! EXPERIMENTAL !!!
struct ROQ_PUBLIC PortfolioUpdate final {
  std::string_view user;          //!< User
  std::span<Position> positions;  //!< Position updates
  UpdateType update_type = {};    //!< Update type
};

template <>
inline constexpr std::string_view get_name<PortfolioUpdate>() {
  using namespace std::literals;
  return "portfolio_update"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::PortfolioUpdate> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::PortfolioUpdate const &value, Context &context) const {
    using namespace std::literals;
    using namespace fmt::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(user="{}", )"
        R"(positions=[{}], )"
        R"(update_type={})"
        R"(}})"_cf,
        value.user,
        fmt::join(value.positions, ", "sv),
        value.update_type);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::PortfolioUpdate>> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Event<roq::PortfolioUpdate> const &event, Context &context) const {
    using namespace fmt::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(portfolio_update={}, )"
        R"(message_info={})"
        R"(}})"_cf,
        event.value,
        event.message_info);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::PortfolioUpdate>> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Trace<roq::PortfolioUpdate> const &event, Context &context) const {
    using namespace std::literals;
    using namespace fmt::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(portfolio_update={}, )"
        R"(trace_info={})"
        R"(}})"_cf,
        event.value,
        event.trace_info);
  }
};
