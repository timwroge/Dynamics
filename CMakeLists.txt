#
# CMakeLists.txt
# Copyright Tim Wroge 202020

cmake_minimum_required (VERSION 3.5 FATAL_ERROR)
include(ExternalProject)

project (Dynamics
    VERSION 1.0.0
    LANGUAGES CXX
)
set(PRECOMPILED_README ${CMAKE_SOURCE_DIR}/PRECOMPILED_README.md)
set(OUTPUT_README ${CMAKE_SOURCE_DIR}/README.md)

if (CMAKE_GENERATOR STREQUAL "Unix Makefiles")

    add_custom_target (readme_depends
        COMMAND pip3 install --user readme2tex
    )

    add_custom_target (readme
        DEPENDS ${PRECOMPILEDREADME} ${OUTPUT_README} readme_depends eigen
        COMMAND python3 -m readme2tex  --svgdir doc/equations --nocdn --output README.md PRECOMPILED_README.md
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )

    add_custom_target (tests
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif ()
# add some compiler flags
set (CMAKE_CXX_FLAGS " -std=c++20 -fexceptions -Werror -Wall")
# makes teh binaries go to release within the cmake binary directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release)
#include(${CMAKE_SOURCE_DIR}/include/)

ExternalProject_Add(eigen
    TMP_DIR ${CMAKE_BINARY_DIR}/eigen
    DOWNLOAD_DIR ${CMAKE_SOURCE_DIR}/external/
    STAMP_DIR ${CMAKE_SOURCE_DIR}/external/
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG tags/3.3.4)


#add subdirectories for the rest of the project

#add_subdirectory(C++-Specifics)
