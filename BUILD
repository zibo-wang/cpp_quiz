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
