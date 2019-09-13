﻿cmake_minimum_required(VERSION 3.10)

set(LIB xvector)

# -------------------------- ARGUMENTS ----------------------------------------
set(CMAKE_BUILD_TYPE "${BUILD_TYPE}")
if(MSVC)
    if("${BUILD_TYPE}" STREQUAL "Release")
        message("Buidling with -O2 ${BUILD_TYPE}")
        add_definitions( "-O2" )
    endif()
else()
    set(LINUX_ARGS "-std=c++17 -finput-charset=UTF-8 -fPIC")
    if("${BUILD_TYPE}" STREQUAL "Release")
        message("Buidling with -O2 ${BUILD_TYPE}")
        set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS_INIT}  ${LINUX_ARGS} -O2")
        set(CMAKE_C_FLAGS "-O2")
    else()
        set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS_INIT}  ${LINUX_ARGS} -g2")
        set(CMAKE_C_FLAGS "-g2")
    endif()
endif()
# -------------------------- ARGUMENTS ----------------------------------------
# -------------------------- CONFIGURATION ------------------------------------
set(XVECTOR_DIR ${INSTALL_PREFIX}/code/${LIB})
# -------------------------- CONFIGURATION ------------------------------------
# -------------------------- BUILD --------------------------------------------
add_library(${LIB} 
    STATIC
        ${XVECTOR_DIR}/include/${LIB}.h
        ${XVECTOR_DIR}/src/${LIB}.cpp

        ${XVECTOR_DIR}/include/const_${LIB}.h
        ${XVECTOR_DIR}/src/const_${LIB}.cpp

        ${XVECTOR_DIR}/include/val_${LIB}.h
        ${XVECTOR_DIR}/src/val_${LIB}.cpp
)

add_library(radical::${LIB} ALIAS ${LIB})

include_directories(${LIB}
    PRIVATE
        ${XVECTOR_DIR}/include
)
# -------------------------- BUILD --------------------------------------------
# -------------------------- END ----------------------------------------------