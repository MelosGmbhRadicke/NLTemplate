cmake_minimum_required (VERSION 2.6)

project("export-generator")

set (ExportGenerator_VERSION_MAJOR 1)
set (ExportGenerator_VERSION_MINOR 0)

include_directories("/usr/local/include/nltemplate/")
link_directories(/usr/local/lib/nltemplate)

add_executable(
    export-generator src/main.cpp
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++11 -lnlpemplate ")

# add the install targets
install (TARGETS export-generator DESTINATION bin)



