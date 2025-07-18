#include "debug_utils.h"
#include <iostream>
#include <vector>
#include <memory>

// Function to demonstrate stack trace
void function_c() {
    TRACE_FUNCTION();
    DEBUG_LOG("Inside function_c");
    
    // Print current stack trace
    debug_utils::print_stack_trace();
}

void function_b() {
    TRACE_FUNCTION();
    DEBUG_LOG("Inside function_b, calling function_c");
    function_c();
}

void function_a() {
    TRACE_FUNCTION();
    DEBUG_LOG("Inside function_a, calling function_b");
    function_b();
}

// Function to demonstrate crash handling
void crash_test() {
    DEBUG_LOG("Testing crash handler...");
    
    // This will cause a segmentation fault
    int* null_ptr = nullptr;
    *null_ptr = 42;  // This should trigger the crash handler
}

// Function to demonstrate assertion
void assertion_test() {
    DEBUG_LOG("Testing debug assertion...");
    
    int value = 10;
    DEBUG_ASSERT(value > 0, "Value should be positive");
    DEBUG_ASSERT(value < 5, "This assertion should fail!");
}

// Function to demonstrate memory debugging
void memory_test() {
    TRACE_FUNCTION();
    DEBUG_LOG("Testing memory operations...");
    
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        DEBUG_LOG("Added element: " << i);
    }
    
    // Access valid element
    DEBUG_LOG("Element at index 5: " << vec[5]);
    
    // This would be an out-of-bounds access (commented out for safety)
    // DEBUG_LOG("Element at index 100: " << vec[100]);
}

int main(int argc, char* argv[]) {
    std::cout << "=== Debug Test Program ===" << std::endl;
    std::cout << "This program demonstrates debugging features:" << std::endl;
    std::cout << "1. Stack trace capture" << std::endl;
    std::cout << "2. Function tracing" << std::endl;
    std::cout << "3. Debug logging" << std::endl;
    std::cout << "4. Crash handling" << std::endl;
    std::cout << "5. Debug assertions" << std::endl;
    std::cout << std::endl;
    
    // Install crash handlers
    debug_utils::install_crash_handlers();
    
    if (argc > 1) {
        std::string test_type = argv[1];
        
        if (test_type == "stack") {
            std::cout << "Running stack trace test..." << std::endl;
            function_a();
        }
        else if (test_type == "crash") {
            std::cout << "Running crash test (this will crash!)..." << std::endl;
            crash_test();
        }
        else if (test_type == "assert") {
            std::cout << "Running assertion test..." << std::endl;
            assertion_test();
        }
        else if (test_type == "memory") {
            std::cout << "Running memory test..." << std::endl;
            memory_test();
        }
        else {
            std::cout << "Unknown test type: " << test_type << std::endl;
            std::cout << "Available tests: stack, crash, assert, memory" << std::endl;
            return 1;
        }
    }
    else {
        std::cout << "Running all safe tests..." << std::endl;
        
        std::cout << "\n--- Stack Trace Test ---" << std::endl;
        function_a();
        
        std::cout << "\n--- Memory Test ---" << std::endl;
        memory_test();
        
        std::cout << "\nTo run specific tests:" << std::endl;
        std::cout << "./debug_test stack   - Stack trace demo" << std::endl;
        std::cout << "./debug_test crash   - Crash handler demo (will crash!)" << std::endl;
        std::cout << "./debug_test assert  - Assertion demo (will abort!)" << std::endl;
        std::cout << "./debug_test memory  - Memory operations demo" << std::endl;
    }
    
    std::cout << "\n=== Debug Test Complete ===" << std::endl;
    return 0;
}
