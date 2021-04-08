cmake_minimum_required(VERSION 3.0)
project(ModArchiver VERSION 2.0.0 LANGUAGES CXX)

file(GLOB CPPS_Abstract "src/Abstract/*.cpp")
file(GLOB CPPS_Stat "src/Stat/*.cpp")
file(GLOB CPPS_simp "src/*.cpp")
file(GLOB CPPS ${CPPS_Abstract} ${CPPS_Stat} ${CPPS_simp})

add_executable(${PROJECT_NAME} ${CPPS})
include_directories(headers)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
