load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "Cricket",
    srcs = [
        "Cricket.cpp",
    ],
    data = [
        "//app/assets:assets",
    ],
    deps = [
        "//src:Raven",
        "@SadaLogger",
    ],
    linkstatic = 1,
)
