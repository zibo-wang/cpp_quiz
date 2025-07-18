# BUILD file for C++ components
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

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
