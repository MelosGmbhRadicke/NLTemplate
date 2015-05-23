cmake_minimum_required (VERSION 2.6)

project("export-generator")

set (ExportGenerator_VERSION_MAJOR 1)
set (ExportGenerator_VERSION_MINOR 0)

include_directories("/usr/local/include/nltemplate/")
target_link_libraries(libnlpemplate)

#link_directories(/usr/local/bin/nltemplate)

#LINK_DIRECTORIES(/usr/local/bin/nltemplate)
#TARGET_LINK_LIBRARIES(nltpemplate nltpemplate)

#FIND_LIBRARY(NLTEMPLATE_LIBRARY libnlpemplate /usr/local/bin/nltemplate)
#TARGET_LINK_LIBRARIES(libnltpemplate ${NLTEMPLATE_LIBRARY})


add_executable(
    export-generator src/main.cpp
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

# add the install targets
install (TARGETS export-generator DESTINATION bin)



