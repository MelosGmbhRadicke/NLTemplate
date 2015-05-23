cmake_minimum_required (VERSION 2.6)

project("export-generator")

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)



# configure a header file to pass some of the CMake settings
# to the source code
#configure_file (
#  "${PROJECT_SOURCE_DIR}/src/NLTemplate.h.in"
#  "${PROJECT_SOURCE_DIR}/src/NLTemplate.h"
#)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}/src/")


add_executable(
    export-generator src/main.cpp
    src/NLTemplate.cpp
)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

# add the install targets
install (TARGETS export-generator DESTINATION bin)

# install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
#         DESTINATION include)

