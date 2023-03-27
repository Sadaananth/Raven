load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Raven",
    srcs = [
        "Application.cpp",
        "Raven/Engine.cpp",
        "Raven/Engine.hpp",
        "Raven/WindowManager.cpp",
        "Raven/WindowManager.hpp",
        "Raven/EntityManager.cpp",
        "Raven/EntityManager.hpp",
        "Raven/Entity.cpp",
        "Raven/Entity.hpp",
    ],
    hdrs = [
        "Application.hpp",
        "EntryPoint.hpp",
    ],
    deps = [
        "@SadaLogger",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
)
