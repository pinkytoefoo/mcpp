cmake_minimum_required(VERSION 3.15)

project(mcpp CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE
    SOURCE_FILES
    src/*.cpp
    src/*.h
    thirdparty/glad/src/glad.c
    thirdparty/imgui/backends/imgui_impl_glfw.cpp
    thirdparty/imgui/backends/imgui_impl_opengl3.cpp
    thirdparty/imgui/imgui.cpp
    thirdparty/imgui/imgui_widgets.cpp
    thirdparty/imgui/imgui_tables.cpp
    thirdparty/imgui/imgui_draw.cpp
    thirdparty/imgui/imgui_demo.cpp
)

add_executable(mcpp ${SOURCE_FILES})

find_package (Vulkan REQUIRED)

# set(GLFW_BUILD_WAYLAND "Build for wayland" ON)
add_subdirectory(thirdparty/glfw)
include_directories(src)
include_directories(thirdparty/glad)
include_directories(thirdparty/glfw/include)
include_directories(thirdparty/imgui)
include_directories("${Vulkan_INCLUDE_DIR}")
# include_directories(thirdparty/imgui/backends)

if(MINGW)
    target_link_libraries(mcpp stdc++exp)
endif()

target_link_libraries(mcpp glfw Vulkan::Vulkan)