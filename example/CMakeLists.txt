# example config
file(
    GLOB
    example_src
    src/example.cpp
    src/GuiExample.cpp
    src/GuiExample.h
)

add_executable(
    example
    ${example_src}
)

target_link_libraries(
    example
    PUBLIC
    GuiBase
)

target_include_directories(
    example
    PUBLIC
    "${PROJECT_SOURCE_DIR}/lib/src/"
)
