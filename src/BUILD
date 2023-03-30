load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Raven",
    srcs = [
        "Application.cpp",
        "Raven/Engine.cpp",
        "Raven/Engine.hpp",
        "Raven/EntityManager.cpp",
        "Raven/EntityManager.hpp",
        "Raven/Entity.cpp",
        "Raven/Entity.hpp",
        "Raven/EntityRenderable.hpp",
        "Raven/EntityRenderable.cpp",
        "Raven/Renderer.hpp",
        "Raven/Renderer.cpp",
        "Raven/WidgetManager.cpp",
        "Raven/WidgetManager.hpp",
    ],
    hdrs = [
        "Application.hpp",
        "EntryPoint.hpp",
        "Raven/Entity.hpp",
    ],
    deps = [
        "@SadaLogger",
        "//src/Raven/Widgets:Widgets",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
)
