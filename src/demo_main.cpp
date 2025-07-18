#include "src/calculator.h"
#include "src/string_utils.h"
#include "src/simple_stack.h"
#include <iostream>
#include <cassert>

using namespace cpp_quiz;

void test_calculator()
{
    std::cout << "Testing Calculator..." << std::endl;

    Calculator calc;

    // Test basic arithmetic
    assert(calc.add(2.0, 3.0) == 5.0);
    assert(calc.subtract(5.0, 3.0) == 2.0);
    assert(calc.multiply(4.0, 3.0) == 12.0);
    assert(calc.divide(10.0, 2.0) == 5.0);

    // Test memory operations
    calc.store_in_memory(42.0);
    assert(calc.recall_from_memory() == 42.0);

    std::cout << "Calculator tests passed!" << std::endl;
}

void test_string_utils()
{
    std::cout << "Testing StringUtils..." << std::endl;

    // Test case conversion
    assert(StringUtils::to_upper("hello") == "HELLO");
    assert(StringUtils::to_lower("WORLD") == "world");

    // Test palindrome
    assert(StringUtils::is_palindrome("racecar") == true);
    assert(StringUtils::is_palindrome("hello") == false);

    // Test word count
    assert(StringUtils::count_words("hello world") == 2);

    std::cout << "StringUtils tests passed!" << std::endl;
}

void test_simple_stack()
{
    std::cout << "Testing SimpleStack..." << std::endl;

    SimpleStack<int> stack;

    // Test empty stack
    assert(stack.empty() == true);
    assert(stack.size() == 0);

    // Test push and pop
    stack.push(42);
    assert(stack.empty() == false);
    assert(stack.size() == 1);
    assert(stack.top() == 42);

    int value = stack.pop();
    assert(value == 42);
    assert(stack.empty() == true);

    std::cout << "SimpleStack tests passed!" << std::endl;
}

int main()
{
    std::cout << "Running C++ Quiz Component Tests" << std::endl;
    std::cout << "=================================" << std::endl;

    try
    {
        test_calculator();
        test_string_utils();
        test_simple_stack();

        std::cout << std::endl;
        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Test failed with unknown exception" << std::endl;
        return 1;
    }
}
