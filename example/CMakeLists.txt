# example config
file(
    GLOB
    example_src
    src/example.cpp
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
