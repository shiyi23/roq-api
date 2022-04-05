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
#include "roq/numbers.hpp"
#include "roq/string_types.hpp"

#include "roq/execution_instruction.hpp"
#include "roq/order_type.hpp"
#include "roq/position_effect.hpp"
#include "roq/side.hpp"
#include "roq/time_in_force.hpp"

namespace roq {

//! Fields required to create an order
struct ROQ_PUBLIC CreateOrder final {
  std::string_view account;                           //!< Account name
  uint32_t order_id = {};                             //!< Order identifier
  std::string_view exchange;                          //!< Exchange
  std::string_view symbol;                            //!< Symbol
  Side side = {};                                     //!< Order side
  PositionEffect position_effect = {};                //!< Position effect
  double max_show_quantity = NaN;                     //!< Quantity visible to market (requires exchange support)
  OrderType order_type = {};                          //!< Order type
  TimeInForce time_in_force = {};                     //!< Time in force
  Mask<ExecutionInstruction> execution_instructions;  //!< Execution instructions
  std::string_view order_template;                    //!< Order template
  double quantity = NaN;                              //!< Order quantity
  double price = NaN;                                 //!< Limit price (depends on order_type)
  double stop_price = NaN;                            //!< Stop price (depends on order_type and time_in_force)
  std::string_view routing_id;                        //!< Routing identifier
};

}  // namespace roq

template <>
struct fmt::formatter<roq::CreateOrder> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::CreateOrder &value, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(account="{}", )"
        R"(order_id={}, )"
        R"(exchange="{}", )"
        R"(symbol="{}", )"
        R"(side={}, )"
        R"(position_effect={}, )"
        R"(max_show_quantity={}, )"
        R"(order_type={}, )"
        R"(time_in_force={}, )"
        R"(execution_instructions={}, )"
        R"(order_template="{}", )"
        R"(quantity={}, )"
        R"(price={}, )"
        R"(stop_price={}, )"
        R"(routing_id="{}")"
        R"(}})"sv,
        value.account,
        value.order_id,
        value.exchange,
        value.symbol,
        value.side,
        value.position_effect,
        value.max_show_quantity,
        value.order_type,
        value.time_in_force,
        value.execution_instructions,
        value.order_template,
        value.quantity,
        value.price,
        value.stop_price,
        value.routing_id);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::CreateOrder> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::Event<roq::CreateOrder> &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(create_order={})"
        R"(}})"sv,
        event.message_info,
        event.value);
  }
};
