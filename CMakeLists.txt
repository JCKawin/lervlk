cmake_minimum_required(VERSION 3.20)
project(VulkanApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Prefer Clang if you want to match the Makefile (CLion can also set this in Settings → Toolchains)
if(NOT CMAKE_CXX_COMPILER)
    find_program(CLANGXX clang++)
    if(CLANGXX)
        set(CMAKE_CXX_COMPILER ${CLANGXX})
    endif()
endif()

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Makefile used $(wildcard *.cc) but compiled %.cpp — include both
file(GLOB SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Vulkan_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        Vulkan::Vulkan
        dl
        pthread
        X11
        Xxf86vm
        Xrandr
        Xi
)

# Optional: match a “make run” target
add_custom_target(run
        COMMAND ${PROJECT_NAME}
        DEPENDS ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)