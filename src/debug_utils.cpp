#include "debug_utils.h"
#include <sstream>
#include <iomanip>
#include <cxxabi.h>

namespace debug_utils
{

    std::vector<std::string> get_stack_trace(int max_frames)
    {
        std::vector<std::string> stack_trace;

#if defined(__APPLE__) || defined(__linux__)
        // Use dynamic allocation to avoid VLA
        std::vector<void *> buffer(max_frames);
        int num_frames = backtrace(buffer.data(), max_frames);
        char **symbols = backtrace_symbols(buffer.data(), num_frames);

        if (symbols == nullptr)
        {
            stack_trace.push_back("Failed to get stack trace symbols");
            return stack_trace;
        }

        for (int i = 0; i < num_frames; ++i)
        {
            std::string frame = symbols[i];

            // Try to demangle the symbol
            std::string demangled = demangle_symbol(symbols[i]);
            if (!demangled.empty() && demangled != symbols[i])
            {
                frame = demangled;
            }

            // Add frame number
            std::ostringstream oss;
            oss << "#" << std::setw(2) << i << " " << frame;
            stack_trace.push_back(oss.str());
        }

        free(symbols);
#else
        stack_trace.push_back("Stack trace not supported on this platform");
#endif

        return stack_trace;
    }

    void print_stack_trace(int max_frames)
    {
        std::cerr << "\n=== STACK TRACE ===" << std::endl;
        auto stack_trace = get_stack_trace(max_frames);

        for (const auto &frame : stack_trace)
        {
            std::cerr << frame << std::endl;
        }
        std::cerr << "===================" << std::endl;
    }

    std::string demangle_symbol(const char *mangled_name)
    {
        if (!mangled_name)
        {
            return "";
        }

#ifdef __linux__
        // On Linux, use abi::__cxa_demangle
        int status = 0;
        char *demangled = abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status);

        if (status == 0 && demangled)
        {
            std::string result(demangled);
            free(demangled);
            return result;
        }
#elif defined(__APPLE__)
        // On macOS, the symbol format is different
        // Try to extract the mangled name from the symbol string
        std::string symbol_str(mangled_name);

        // Look for patterns like "0   program   0x... _ZN..."
        size_t start = symbol_str.find("_Z");
        if (start != std::string::npos)
        {
            size_t end = symbol_str.find(" ", start);
            if (end == std::string::npos)
            {
                end = symbol_str.length();
            }

            std::string mangled_part = symbol_str.substr(start, end - start);

            int status = 0;
            char *demangled = abi::__cxa_demangle(mangled_part.c_str(), nullptr, nullptr, &status);

            if (status == 0 && demangled)
            {
                std::string result = symbol_str.substr(0, start) + demangled;
                free(demangled);
                return result;
            }
        }
#endif

        return mangled_name;
    }

    void crash_handler(int signal)
    {
        std::cerr << "\n=== CRASH DETECTED ===" << std::endl;
        std::cerr << "Signal: " << signal;

        switch (signal)
        {
        case SIGSEGV:
            std::cerr << " (SIGSEGV - Segmentation fault)";
            break;
        case SIGABRT:
            std::cerr << " (SIGABRT - Abort)";
            break;
        case SIGFPE:
            std::cerr << " (SIGFPE - Floating point exception)";
            break;
        case SIGILL:
            std::cerr << " (SIGILL - Illegal instruction)";
            break;
        default:
            std::cerr << " (Unknown signal)";
            break;
        }
        std::cerr << std::endl;

        print_stack_trace();

        // Reset signal handler and re-raise to get core dump
        std::signal(signal, SIG_DFL);
        std::raise(signal);
    }

    void install_crash_handlers()
    {
        std::signal(SIGSEGV, crash_handler);
        std::signal(SIGABRT, crash_handler);
        std::signal(SIGFPE, crash_handler);
        std::signal(SIGILL, crash_handler);

        std::cerr << "[DEBUG] Crash handlers installed" << std::endl;
    }

} // namespace debug_utils
