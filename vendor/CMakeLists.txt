# vendor config

## glfw
set(GLFW_BUILD_DOCKS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")

add_subdirectory(glfw)

## imgui
file(
    GLOB
    ImGui_src
	"imgui/*.cpp"
	"imgui/*.h"
	"imgui/backends/imgui_impl_glfw.cpp"
	"imgui/backends/imgui_impl_glfw.h"
    "imgui/backends/imgui_impl_vulkan.cpp"
    "imgui/backends/imgui_impl_vulkan.h"
)

add_library(
    ImGui
    STATIC
    "${ImGui_src}"
)

target_link_libraries(
    ImGui
    PUBLIC
    "${Vulkan_LIBRARIES}"
)

target_include_directories(
    ImGui
    PUBLIC
    "${vendorPath}/imgui"
    "${vendorPath}/glfw/include"
    "${Vulkan_INCLUDE_DIRS}"
)

set_target_properties(
    ImGui
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
