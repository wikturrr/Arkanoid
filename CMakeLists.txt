cmake_minimum_required(VERSION 3.10)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
set(ALL_SOURCES "main.cpp" ${SRC_FILES})


include_directories(include)
include_directories("C:/SFML/include")

add_executable(Arkanoid ${ALL_SOURCES})

target_link_libraries(Arkanoid SFML::Graphics SFML::Window SFML::System)
target_include_directories(Arkanoid PUBLIC include "C:/SFML/include")

add_custom_command(TARGET Arkanoid POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "C:/SFML/bin/sfml-graphics-d-3.dll"
    "C:/SFML/bin/sfml-window-d-3.dll"
    "C:/SFML/bin/sfml-system-d-3.dll"
    $<TARGET_FILE_DIR:Arkanoid>)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
)