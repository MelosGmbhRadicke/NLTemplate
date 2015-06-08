cmake_minimum_required (VERSION 2.6)
project (NLTemplate)
set(CMAKE_BUILD_TYPE Release)

set (NLTemplate_VERSION_MAJOR 1)
set (NLTemplate_VERSION_MINOR 0)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall ")

add_library (core OBJECT NLTemplate/NLTemplate.cpp)
add_library(nlpemplatestatic STATIC NLTemplate/NLTemplate.cpp)
add_library(nlpemplate SHARED NLTemplate/NLTemplate.cpp)


# add the install targets
install (TARGETS nlpemplate DESTINATION lib/nltemplate)

install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/NLTemplate/NLTemplate.h"
         DESTINATION include/nltemplate)


# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${NLTemplate_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${NLTemplate_VERSION_MINOR}")
include (CPack)
