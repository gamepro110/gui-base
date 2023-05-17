# lib config
file(
    GLOB_RECURSE
    lib_src
    "src/*.cpp"
    "src/*.h"
)

add_library(
    GuiBase
    STATIC
    ${lib_src}
)

target_link_libraries(
    GuiBase
    PUBLIC
    glfw
    ImGui
)

target_include_directories(
    GuiBase
    PUBLIC
    "src"
    "${vendorPath}/imgui"
    "${vendorPath}/glfw/include"
    "${Vulkan_INCLUDE_DIRS}"
)

set_target_properties(
    GuiBase
    PROPERTIES
    VERSION 1.0
    POSITION_INDEPENDENT_CODE ON
)
