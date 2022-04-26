/* Copyright (c) 2017-2022, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>
#include <fmt/format.h>

#include <chrono>
#include <span>
#include <string_view>

#include "roq/compat.hpp"
#include "roq/event.hpp"
#include "roq/mask.hpp"
#include "roq/message_info.hpp"
#include "roq/name.hpp"
#include "roq/numbers.hpp"
#include "roq/string_types.hpp"
#include "roq/trace.hpp"

#include "roq/support_type.hpp"

namespace roq {

//! Update relating to current gateway service status
struct ROQ_PUBLIC GatewayStatus final {
  std::string_view account;       //!< Account name
  Mask<SupportType> supported;    //!< Supported update types
  Mask<SupportType> available;    //!< Available update types (union of all streams, one or more available)
  Mask<SupportType> unavailable;  //!< Unavailable update types (union of all streams, one or more unavailable)
};

template <>
inline constexpr std::string_view get_name<GatewayStatus>() {
  using namespace std::literals;
  return "gateway_status"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::GatewayStatus> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::GatewayStatus &value, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(account="{}", )"
        R"(supported={}, )"
        R"(available={}, )"
        R"(unavailable={})"
        R"(}})"sv,
        value.account,
        value.supported,
        value.available,
        value.unavailable);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::GatewayStatus> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::Event<roq::GatewayStatus> &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(gateway_status={})"
        R"(}})"sv,
        event.message_info,
        event.value);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::GatewayStatus const> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::Trace<roq::GatewayStatus const> &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(trace_info={}, )"
        R"(gateway_status={})"
        R"(}})"sv,
        event.trace_info,
        event.value);
  }
};
