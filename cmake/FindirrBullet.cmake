# - Try to find irrBullet
# Once done this will define
#
#  IRRBULLET_FOUND - system has Irrlicht
#  IRRBULLET_INCLUDE_DIRS - the Irrlicht include directory
#  IRRBULLET_LIBRARIES - Link these to use Irrlicht
#  IRRBULLET_DEFINITIONS - Compiler switches required for using Irrlicht
#

set(LOCAL_IRRBULLET_BASE "/home/moss/src/libs/irrBullet")

if (IRRBULLET_LIBRARIES AND IRRBULLET_INCLUDE_DIRS)
  # in cache already
  set(IRRBULLET_FOUND TRUE)
else (IRRBULLET_LIBRARIES AND IRRBULLET_INCLUDE_DIRS)
  find_path(IRRBULLET_INCLUDE_DIR
    NAMES
      irrbullet.h
    PATHS
      ${LOCAL_IRRBULLET_BASE}
      /usr/include
      /usr/local/include
      /opt/local/include
    PATH_SUFFIXES
      source
  )

  find_library(IRRBULLET_LIBRARY
    NAMES
      irrBullet
    PATHS
      ${LOCAL_IRRBULLET_BASE}/build
      /usr/lib
      /usr/local/lib
      /opt/local/lib
  )

  set(IRRBULLET_INCLUDE_DIRS
    ${IRRBULLET_INCLUDE_DIR}
  )
  set(IRRBULLET_LIBRARIES
    ${IRRBULLET_LIBRARY}
)

  if (IRRBULLET_INCLUDE_DIRS AND IRRBULLET_LIBRARIES)
     set(IRRBULLET_FOUND TRUE)
  endif (IRRBULLET_INCLUDE_DIRS AND IRRBULLET_LIBRARIES)

  if (IRRBULLET_FOUND)
    if (NOT Irrlicht_FIND_QUIETLY)
      message(STATUS "Found Irrlicht: ${IRRBULLET_LIBRARIES}")
    endif (NOT Irrlicht_FIND_QUIETLY)
  else (IRRBULLET_FOUND)
    if (Irrlicht_FIND_REQUIRED)
      message(FATAL_ERROR "Could not find Irrlicht")
    endif (Irrlicht_FIND_REQUIRED)
  endif (IRRBULLET_FOUND)

  # show the IRRBULLET_INCLUDE_DIRS and IRRBULLET_LIBRARIES variables only in the advanced view
  mark_as_advanced(IRRBULLET_INCLUDE_DIRS IRRBULLET_LIBRARIES)

endif (IRRBULLET_LIBRARIES AND IRRBULLET_INCLUDE_DIRS)




