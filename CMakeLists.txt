# global config
cmake_minimum_required(
    VERSION
    3.21
)

project(
    GuiBase
    LANGUAGES CXX
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(buildGuiBaseExample "should the example be build?" false)

if(currentPreset STREQUAL "Debug")
	add_definitions(-DDEBUG)
elseif(currentPreset STREQUAL "Release")
	add_definitions(-DRELEASE)
elseif(currentPreset STREQUAL "MinSizeRel")
	add_definitions(-DDIST)
endif()

find_package(Vulkan REQUIRED)

set(vendorPath "${PROJECT_SOURCE_DIR}/vendor")

add_subdirectory(vendor)

add_compile_options(
    -Wall
    -Werror
    -Wextra
    #-Wconversion
    -Wunused
)

add_subdirectory(lib)

if  (buildGuiBaseExample)
    add_subdirectory(example)
endif  (buildGuiBaseExample)

add_subdirectory(tests)
