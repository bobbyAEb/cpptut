#include <gtest/gtest.h>
#include "clever_name/randomization.h"

using namespace clever;

TEST(TestRandom, XkcdRandomNumber) {
  // Test our great randomization algorithm.
  EXPECT_EQ(4, GetXkcdRandomNumber());
  EXPECT_EQ(4, GetXkcdRandomNumber());
  EXPECT_EQ(4, GetXkcdRandomNumber());
}
