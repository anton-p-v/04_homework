cc_library(
    name = "print_ip",
    hdrs = ["print_ip.h"],
    # srcs = ["print_ip.cpp"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "print_ip_test",
    size = "small",
    srcs = [
        "print_ip_test.cpp",
    ],
    deps = [
        "@googletest//:gtest_main",
        ":print_ip",
    ],
)
