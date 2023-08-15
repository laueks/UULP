#include "UULP/who/who.h"
#include <gtest/gtest.h>

TEST(UULPTest, Who) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  EXPECT_NO_FATAL_FAILURE(Who());
}
