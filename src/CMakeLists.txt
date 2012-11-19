#
#

set(SRCS main.cpp part.h material.h unit.h player.h instruction.h)


#message(STATUS "project: ${PROJECT_NAME} srcs: ${SRCS}")
add_executable(${PROJECT_NAME} ${SRCS})


