#
#
cmake_minimum_required("VERSION" "2.6")
project(former)
#add_definitions("-Wall -pedantic")


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)



#
# Build options
#

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose type of build: Debug Build Release")
endif()

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g -g3 -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -g3 -Wall")
endif()

if(${CMAKE_BUILD_TYPE} MATCHES "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -pedantic")
endif()

# FIXME
message("CXX ${CMAKE_CXX_FLAGS}")
message("BTYPE ${CMAKE_BUILD_TYPE}")

#add_subdirectory(src)

#
# Find libraries
#
find_package(Lua51 REQUIRED)
find_package(Irrlicht REQUIRED)
find_package(Bullet REQUIRED)
find_package(JsonCpp REQUIRED)

message("JsonCpp includes: ${JSONCPP_INCLUDE_DIR}")
message("JsonCpp libs:     ${JSONCPP_LIBRARIES}")



# for irrlicht
find_package(JPEG REQUIRED)
find_package(BZip2 REQUIRED)
find_package(PNG REQUIRED)
find_package(OpenGL REQUIRED)   # for GL
find_package(X11 REQUIRED)      # for Xxf86vm

#
# connecting libs
#
include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${LUA_INCLUDE_DIRS}
    ${IRRLICHT_INCLUDE_DIRS}
    ${JPEG_INCLUDE_DIRS}
    ${BZIP2_INCLUDE_DIRS}
    ${PNG_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${X11_INCLUDE_DIRS}
    ${BULLET_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIR}
    )


aux_source_directory(src former_SRCS)
add_executable(${PROJECT_NAME} ${former_SRCS})


target_link_libraries(${PROJECT_NAME}
    ${LUA_LIBRARIES}
    ${IRRLICHT_LIBRARIES}
    ${JPEG_LIBRARIES}
    ${BZIP2_LIBRARIES}
    ${PNG_LIBRARIES}
    ${OPENGL_LIBRARIES}
    #${X11_X11_LIB}
    ${X11_Xxf86vm_LIB}
    ${BULLET_LIBRARIES}
    ${JSONCPP_LIBRARIES}
    )

