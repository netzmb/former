#
#
cmake_minimum_required("VERSION" "2.6")
project(former)
add_definitions("-Wall -pedantic")


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)



#
# Build options
#

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose type of build: None Build Release")
endif()

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
endif()

#add_subdirectory(src)

#
# Find libraries
#
find_package(Lua51 REQUIRED)
find_package(Irrlicht REQUIRED)
find_package(Bullet REQUIRED)

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
    ${IRRLICHT_INCLUDE_DIR}
    ${JPEG_INCLUDE_DIR}
    ${BZIP2_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${X11_INCLUDE_DIR}
    ${BULLET_INCLUDE_DIR}
    )


aux_source_directory(src former_SRCS)
add_executable(${PROJECT_NAME} ${former_SRCS})


target_link_libraries(${PROJECT_NAME}
    ${IRRLICHT_LIBRARIES}
    ${JPEG_LIBRARIES}
    ${BZIP2_LIBRARIES}
    ${PNG_LIBRARIES}
    ${OPENGL_LIBRARIES}
    #    ${X11_LIBRARIES}
    ${X11_X11_LIB}
    ${X11_Xxf86vm_LIB}
    ${BULLET_LIBRARIES}
    )

