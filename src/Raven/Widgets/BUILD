load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Widgets",
    srcs = [
        "Widget.cpp",
        "Widget.hpp",
        "FpsWidget.hpp",
        "FpsWidget.cpp",
    ],
    hdrs = [
        "Widget.hpp",
        "FpsWidget.hpp",
    ],
    deps = [
        "@SadaLogger",
    ],
    data = [
        "//src/Raven/assets:assets",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
)
