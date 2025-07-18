# Root BUILD file for cpp_quiz project

# Package declaration
package(default_visibility = ["//visibility:public"])

# Common C++ compiler flags that can be used across components
cc_library(
    name = "common_flags",
    hdrs = [],
    copts = [
        "-std=c++17",
        "-Wall",
        "-Wextra",
        "-O2",
    ],
    visibility = ["//visibility:public"],
)

# Debug build configuration with debugging symbols and no optimization
cc_library(
    name = "debug_flags",
    hdrs = [],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g3",  # Maximum debug information
        "-O0",  # No optimization for better debugging
        "-DDEBUG",  # Debug macro
        "-fno-omit-frame-pointer",  # Keep frame pointers for better stack traces
        "-fno-optimize-sibling-calls",  # Better stack traces
    ],
    linkopts = [
        "-g",  # Debug symbols in linker
    ],
    visibility = ["//visibility:public"],
)

# Release build with debug symbols (for production debugging)
cc_library(
    name = "release_debug_flags",
    hdrs = [],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g1",  # Minimal debug information
        "-O2",  # Optimized but with debug info
        "-DNDEBUG",  # Release macro
        "-fno-omit-frame-pointer",  # Keep frame pointers for stack traces
    ],
    linkopts = [
        "-g",
    ],
    visibility = ["//visibility:public"],
)

# Alias for all components (will be populated as we add components)
filegroup(
    name = "all_components",
    srcs = [
        "//src:all",
    ],
    visibility = ["//visibility:public"],
)

# Test suite for all components
test_suite(
    name = "all_tests",
    tests = [
        "//src:all_tests",
    ],
)

# Benchmark suite for all components (optional)
test_suite(
    name = "all_benchmarks",
    tests = [
        "//src:all_benchmarks",
    ],
)
