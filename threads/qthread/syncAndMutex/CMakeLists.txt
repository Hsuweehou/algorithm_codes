cmake_minimum_required(VERSION 3.10)
SET(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")

project(syncAndMutex)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)##get "unreference to vtable" error if missing out this line
########         !!!!!!!         ########
########double click mouse to run########
set(CMAKE_CXX_FLAGS   "-no-pie")
set(CMAKE_C_FLAGS   "-no-pie")
########         !!!!!!!         ########

# Find the QtWidgets library
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
file(GLOB project_SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${project_SOURCES})

target_link_libraries(${PROJECT_NAME} 
Qt5::Core 
Qt5::Gui 
Qt5::Widgets
)
