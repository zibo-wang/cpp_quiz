# BUILD file for C++ components
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "q132",
    srcs = ["q132.cpp"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

cc_binary(
    name = "q31",
    srcs = ["q31.cpp"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

cc_binary(
    name = "q140",
    srcs = ["q140.cpp"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

cc_binary(
    name = "q365",
    srcs = ["q365.cpp"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

# Question 350
cc_binary(
    name = "q350",
    srcs = ["q350.cpp"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

# Debug version of q350 with stacktrace support
cc_binary(
    name = "q350_debug",
    srcs = ["q350.cpp"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g3",
        "-O0",
        "-DDEBUG",
        "-fno-omit-frame-pointer",
        "-fno-optimize-sibling-calls",
    ],
    linkopts = [
        "-g",
        "-rdynamic",  # Export symbols for better stack traces
    ],
    deps = [
        "//:debug_flags",
    ],
)

# Calculator component
cc_library(
    name = "calculator",
    srcs = ["calculator.cpp"],
    hdrs = ["calculator.h"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

# Debug version of calculator
cc_library(
    name = "calculator_debug",
    srcs = ["calculator.cpp"],
    hdrs = ["calculator.h"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g3",
        "-O0",
        "-DDEBUG",
        "-fno-omit-frame-pointer",
    ],
    linkopts = ["-g"],
    deps = ["//:debug_flags"],
)

cc_test(
    name = "calculator_test",
    srcs = ["calculator_test.cpp"],
    copts = [
        "-std=c++23",
    ],
    deps = [
        ":calculator",
        "@googletest//:gtest_main",
    ],
)

# String utilities component
cc_library(
    name = "string_utils",
    srcs = ["string_utils.cpp"],
    hdrs = ["string_utils.h"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

# Debug version of string_utils
cc_library(
    name = "string_utils_debug",
    srcs = ["string_utils.cpp"],
    hdrs = ["string_utils.h"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g3",
        "-O0",
        "-DDEBUG",
        "-fno-omit-frame-pointer",
    ],
    linkopts = ["-g"],
    deps = ["//:debug_flags"],
)

cc_test(
    name = "string_utils_test",
    srcs = ["string_utils_test.cpp"],
    copts = [
        "-std=c++23",
    ],
    deps = [
        ":string_utils",
        "@googletest//:gtest_main",
    ],
)

# Simple stack component (header-only)
cc_library(
    name = "simple_stack",
    hdrs = ["simple_stack.h"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
    ],
)

# Debug version of simple_stack
cc_library(
    name = "simple_stack_debug",
    hdrs = ["simple_stack.h"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g3",
        "-O0",
        "-DDEBUG",
        "-fno-omit-frame-pointer",
    ],
    deps = ["//:debug_flags"],
)

# Debug utilities library with stacktrace support
cc_library(
    name = "debug_utils",
    srcs = ["debug_utils.cpp"],
    hdrs = ["debug_utils.h"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g3",
        "-O0",
        "-DDEBUG",
        "-fno-omit-frame-pointer",
    ],
    linkopts = [
        "-g",
        "-rdynamic",
    ],
    deps = ["//:debug_flags"],
)

# Debug test program to demonstrate debugging features
cc_binary(
    name = "debug_test",
    srcs = ["debug_test.cpp"],
    copts = [
        "-std=c++23",
        "-Wall",
        "-Wextra",
        "-g3",
        "-O0",
        "-DDEBUG",
        "-fno-omit-frame-pointer",
        "-fno-optimize-sibling-calls",
    ],
    linkopts = [
        "-g",
        "-rdynamic",
    ],
    deps = [
        ":debug_utils",
        "//:debug_flags",
    ],
)

cc_test(
    name = "simple_stack_test",
    srcs = ["simple_stack_test.cpp"],
    copts = [
        "-std=c++23",
    ],
    deps = [
        ":simple_stack",
        "@googletest//:gtest_main",
    ],
)

# Demo executable to test all components
cc_binary(
    name = "demo",
    srcs = ["demo_main.cpp"],
    copts = [
        "-std=c++23",
    ],
    deps = [
        ":calculator",
        ":simple_stack",
        ":string_utils",
    ],
)

# Debug version of demo with stacktrace support
cc_binary(
    name = "demo_debug",
    srcs = ["demo_main_debug.cpp"],
    copts = [
        "-std=c++23",
        "-g3",
        "-O0",
        "-DDEBUG",
        "-fno-omit-frame-pointer",
        "-fno-optimize-sibling-calls",
    ],
    linkopts = [
        "-g",
        "-rdynamic",
    ],
    deps = [
        ":calculator_debug",
        ":debug_utils",
        ":simple_stack_debug",
        ":string_utils_debug",
        "//:debug_flags",
    ],
)

# Aggregate targets for convenience
filegroup(
    name = "all",
    srcs = [
        ":calculator",
        ":simple_stack",
        ":string_utils",
    ],
)

test_suite(
    name = "all_tests",
    tests = [
        ":calculator_test",
        ":simple_stack_test",
        ":string_utils_test",
    ],
)

# Optional: benchmark targets (if you want to add performance tests later)
test_suite(
    name = "all_benchmarks",
    tests = [
        # Add benchmark targets here when created
    ],
)
