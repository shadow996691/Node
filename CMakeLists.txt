cmake_minimum_required(VERSION 3.10)
project(EPlusPlus VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_GRAPHICS "Enable SDL2 Graphics Module" OFF)

add_executable(eplusplus eplusplus.cpp)

if(ENABLE_GRAPHICS)
    target_compile_definitions(eplusplus PRIVATE EPLUSPLUS_GRAPHICS)
    find_package(SDL2 REQUIRED)
    target_include_directories(eplusplus PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(eplusplus PRIVATE ${SDL2_LIBRARIES})

    if(ANDROID)
        target_link_libraries(eplusplus PRIVATE GLESv1_CM GLESv2 log android)
    endif()
endif()
