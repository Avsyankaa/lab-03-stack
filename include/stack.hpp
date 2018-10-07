// Copyright 2018 Vyacheslav Vershinin

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
