#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <csignal>
#include <cstdlib>

#ifdef __APPLE__
#include <execinfo.h>
#include <dlfcn.h>
#elif __linux__
#include <execinfo.h>
#include <cxxabi.h>
#endif

namespace debug_utils {

/**
 * @brief Captures and returns the current stack trace
 * @param max_frames Maximum number of stack frames to capture
 * @return Vector of strings representing the stack trace
 */
std::vector<std::string> get_stack_trace(int max_frames = 64);

/**
 * @brief Prints the current stack trace to stderr
 * @param max_frames Maximum number of stack frames to print
 */
void print_stack_trace(int max_frames = 64);

/**
 * @brief Demangles a C++ symbol name
 * @param mangled_name The mangled symbol name
 * @return Demangled name or original name if demangling fails
 */
std::string demangle_symbol(const char* mangled_name);

/**
 * @brief Signal handler for crash debugging
 * @param signal The signal number
 */
void crash_handler(int signal);

/**
 * @brief Installs crash handlers for common signals
 */
void install_crash_handlers();

/**
 * @brief Debug assertion macro that prints stack trace on failure
 */
#ifdef DEBUG
#define DEBUG_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "DEBUG ASSERTION FAILED: " << message << std::endl; \
            std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; \
            debug_utils::print_stack_trace(); \
            std::abort(); \
        } \
    } while (0)
#else
#define DEBUG_ASSERT(condition, message) ((void)0)
#endif

/**
 * @brief Debug logging macro
 */
#ifdef DEBUG
#define DEBUG_LOG(message) \
    std::cerr << "[DEBUG] " << __FILE__ << ":" << __LINE__ << " - " << message << std::endl
#else
#define DEBUG_LOG(message) ((void)0)
#endif

/**
 * @brief Trace function entry/exit
 */
#ifdef DEBUG
class FunctionTracer {
public:
    explicit FunctionTracer(const char* func_name) : func_name_(func_name) {
        std::cerr << "[TRACE] Entering " << func_name_ << std::endl;
    }
    
    ~FunctionTracer() {
        std::cerr << "[TRACE] Exiting " << func_name_ << std::endl;
    }
    
private:
    const char* func_name_;
};

#define TRACE_FUNCTION() debug_utils::FunctionTracer _tracer(__FUNCTION__)
#else
#define TRACE_FUNCTION() ((void)0)
#endif

} // namespace debug_utils
