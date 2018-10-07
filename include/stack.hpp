// Copyright 2018 Vyacheslav Vershinin

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <stack>

template <typename T>
class stack
{
public:
  void push(T&& value) { stack.push(value); }
  void push(T value) { stack.push(value); }
  void pop() { stack.pop(); }
  const T& head() const { return stack.top(); }
private:
  std::stack<T> stack;
};

#endif // INCLUDE_STACK_HPP_
