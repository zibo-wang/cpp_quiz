#include "src/calculator.h"
#include "src/string_utils.h"
#include "src/simple_stack.h"
#include "src/debug_utils.h"
#include <iostream>
#include <cassert>

using namespace cpp_quiz;

void test_calculator()
{
    TRACE_FUNCTION();
    DEBUG_LOG("Starting calculator tests");
    
    std::cout << "Testing Calculator..." << std::endl;

    Calculator calc;

    // Test basic arithmetic
    DEBUG_LOG("Testing basic arithmetic operations");
    DEBUG_ASSERT(calc.add(2.0, 3.0) == 5.0, "Addition test failed");
    DEBUG_ASSERT(calc.subtract(5.0, 3.0) == 2.0, "Subtraction test failed");
    DEBUG_ASSERT(calc.multiply(4.0, 3.0) == 12.0, "Multiplication test failed");
    DEBUG_ASSERT(calc.divide(10.0, 2.0) == 5.0, "Division test failed");

    // Test memory operations
    DEBUG_LOG("Testing memory operations");
    calc.store_in_memory(42.0);
    DEBUG_ASSERT(calc.recall_from_memory() == 42.0, "Memory recall test failed");

    std::cout << "Calculator tests passed!" << std::endl;
    DEBUG_LOG("Calculator tests completed successfully");
}

void test_string_utils()
{
    TRACE_FUNCTION();
    DEBUG_LOG("Starting string utils tests");
    
    std::cout << "Testing StringUtils..." << std::endl;

    // Test case conversion
    DEBUG_LOG("Testing case conversion");
    DEBUG_ASSERT(StringUtils::to_upper("hello") == "HELLO", "to_upper test failed");
    DEBUG_ASSERT(StringUtils::to_lower("WORLD") == "world", "to_lower test failed");

    // Test palindrome
    DEBUG_LOG("Testing palindrome detection");
    DEBUG_ASSERT(StringUtils::is_palindrome("racecar") == true, "Palindrome test failed");
    DEBUG_ASSERT(StringUtils::is_palindrome("hello") == false, "Non-palindrome test failed");

    // Test word count
    DEBUG_LOG("Testing word count");
    DEBUG_ASSERT(StringUtils::count_words("hello world") == 2, "Word count test failed");

    std::cout << "StringUtils tests passed!" << std::endl;
    DEBUG_LOG("String utils tests completed successfully");
}

void test_simple_stack()
{
    TRACE_FUNCTION();
    DEBUG_LOG("Starting simple stack tests");
    
    std::cout << "Testing SimpleStack..." << std::endl;

    SimpleStack<int> stack;

    // Test empty stack
    DEBUG_LOG("Testing empty stack");
    DEBUG_ASSERT(stack.empty() == true, "Empty stack test failed");
    DEBUG_ASSERT(stack.size() == 0, "Stack size test failed");

    // Test push and pop
    DEBUG_LOG("Testing push and pop operations");
    stack.push(42);
    DEBUG_ASSERT(stack.empty() == false, "Non-empty stack test failed");
    DEBUG_ASSERT(stack.size() == 1, "Stack size after push test failed");
    DEBUG_ASSERT(stack.top() == 42, "Stack top test failed");

    int value = stack.pop();
    DEBUG_ASSERT(value == 42, "Stack pop value test failed");
    DEBUG_ASSERT(stack.empty() == true, "Stack empty after pop test failed");

    std::cout << "SimpleStack tests passed!" << std::endl;
    DEBUG_LOG("Simple stack tests completed successfully");
}

void demonstrate_debugging_features()
{
    TRACE_FUNCTION();
    DEBUG_LOG("Demonstrating debugging features");
    
    std::cout << "\n=== Debugging Features Demo ===" << std::endl;
    
    // Show current stack trace
    std::cout << "Current stack trace:" << std::endl;
    debug_utils::print_stack_trace(10);
    
    // Demonstrate debug logging
    DEBUG_LOG("This is a debug log message");
    
    // Demonstrate successful assertion
    int test_value = 100;
    DEBUG_ASSERT(test_value > 0, "Test value should be positive");
    
    std::cout << "Debugging features demonstrated!" << std::endl;
}

int main(int argc, char* argv[])
{
    TRACE_FUNCTION();
    
    // Install crash handlers for better debugging
    debug_utils::install_crash_handlers();
    
    std::cout << "Running C++ Quiz Component Tests (Debug Version)" << std::endl;
    std::cout << "=================================================" << std::endl;
    
    DEBUG_LOG("Starting main function with " << argc << " arguments");

    try
    {
        test_calculator();
        test_string_utils();
        test_simple_stack();
        
        // Only run debugging demo if requested
        if (argc > 1 && std::string(argv[1]) == "--debug-demo") {
            demonstrate_debugging_features();
        }

        std::cout << std::endl;
        std::cout << "All tests passed successfully!" << std::endl;
        DEBUG_LOG("All tests completed successfully");
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        DEBUG_LOG("Exception caught: " << e.what());
        debug_utils::print_stack_trace();
        return 1;
    }
    catch (...)
    {
        std::cerr << "Test failed with unknown exception" << std::endl;
        DEBUG_LOG("Unknown exception caught");
        debug_utils::print_stack_trace();
        return 1;
    }
}
