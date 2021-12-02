/* Copyright (c) 2017-2022, Hans Erik Thrane */

#include <gtest/gtest.h>

#include "roq/utils/common.h"

using namespace roq;
using namespace std::literals;

TEST(request_status, compare_requests) {
  EXPECT_EQ(utils::compare_requests(RequestStatus::TIMEOUT, RequestStatus::ACCEPTED), -1);
}
