#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest/doctest.h"
#include <string>
#include "Stack.h"
using namespace std;

TEST_CASE("Test basic stack operations on stack of ints") {
    Stack<int> stack;
    stack.push(9);
    CHECK(stack.top() == 9);
    stack.push(11);
    CHECK(stack.top() == 11);
    stack.push(42);
    CHECK(stack.top() == 42);
    CHECK(stack.pop() == 42);
    CHECK(stack.top() == 11);
    CHECK(stack.is_empty() == false);
    stack.pop();
    CHECK(stack.pop() == 9);
    CHECK(stack.is_empty() == true);
}

TEST_CASE("POST FIX"){
    string s = "3 3 +";
    CHECK(eval_postfix_expr(s) == 6);
    CHECK(eval_postfix_expr("2 5 4 + *") == 18);
}