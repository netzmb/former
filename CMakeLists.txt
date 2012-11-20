#
#
cmake_minimum_required("VERSION" "2.6")
project(former)
add_definitions("-Wall -pedantic")


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose type of build: None Build Release")
endif()

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
endif()

#add_subdirectory(src)


aux_source_directory(src former_SRCS)
add_executable(${PROJECT_NAME} ${former_SRCS})

