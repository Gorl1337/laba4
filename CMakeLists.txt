cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Test)
project(${PROJECT_NAME})

set(vector vector)
set(vectorlib vectorlib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vectorlib)

add_subdirectory(vector)
add_subdirectory(vectorlib)

#file(GLOB hdrs "${CMAKE_CURRENT_SOURCE_DIR}/*.h*")
#file(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
