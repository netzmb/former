#
# Cmake build instructions for JSONCpp
#
# put this file to jsonCpp root directory
#
# author Netzmb <netzmb@gmail.com>
# Date: 2012-12-10
#

cmake_minimum_required("VERSION" "2.6")
project(jsoncpp)


include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB jsoncpp_HDRS "${PROJECT_SOURCE_DIR}/include/*.h")

aux_source_directory(src/lib_json jsoncpp_SRCS)

add_library(${PROJECT_NAME} STATIC ${jsoncpp_SRCS})

target_link_libraries(jsoncpp pthread)

#
# Install instructions
#

install(TARGETS jsoncpp DESTINATION lib)


install(FILES ${jsoncpp_HDRS} DESTINATION includes/${PROJECT_NAME} )

