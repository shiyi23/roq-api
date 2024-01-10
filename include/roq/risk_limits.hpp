/* Copyright (c) 2017-2024, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include "roq/compat.hpp"

#include <fmt/compile.h>
#include <fmt/format.h>

#include <span>
#include <string_view>

#include "roq/event.hpp"
#include "roq/name.hpp"
#include "roq/risk_limit.hpp"
#include "roq/trace.hpp"
#include "roq/uuid.hpp"

namespace roq {

//! Risk limits (receive) !!! EXPERIMENTAL !!!
struct ROQ_PUBLIC RiskLimits final {
  std::string_view user;              //!< User name (optional)
  uint32_t strategy_id = {};          //!< Strategy identifier (optional)
  std::string_view account;           //!< Account name (optional)
  std::span<RiskLimit const> limits;  //!< Risk limits per {exchange, symbol}
  UUID session_id;                    //!< Reference (UUID)
  uint64_t seqno = {};                //!< Reference (sequencing)
};

template <>
inline constexpr std::string_view get_name<RiskLimits>() {
  using namespace std::literals;
  return "risk_limits"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::RiskLimits> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::RiskLimits const &value, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(user="{}", )"
        R"(strategy_id={}, )"
        R"(account="{}", )"
        R"(limits=[{}], )"
        R"(session_id="{}", )"
        R"(seqno={})"
        R"(}})"sv,
        value.user,
        value.strategy_id,
        value.account,
        fmt::join(value.limits, ", "sv),
        value.session_id,
        value.seqno);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::RiskLimits>> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::Event<roq::RiskLimits> const &event, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(risk_limits={}, )"
        R"(message_info={})"
        R"(}})"sv,
        event.value,
        event.message_info);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::RiskLimits>> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::Trace<roq::RiskLimits> const &event, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(risk_limits={}, )"
        R"(trace_info={})"
        R"(}})"sv,
        event.value,
        event.trace_info);
  }
};
