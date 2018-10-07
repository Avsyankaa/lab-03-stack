// Copyright 2018 Vyacheslav Vershinin

#include <gtest/gtest.h>

#include <stack.hpp>

TEST(StackTest, InitWithDefaultCtor) {
  EXPECT_NO_THROW(stack<unsigned>{});
}
