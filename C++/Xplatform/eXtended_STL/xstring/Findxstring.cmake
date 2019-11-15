﻿cmake_minimum_required(VERSION 3.10)

set(LIB xstring)

# -------------------------- ARGUMENTS ----------------------------------------
set(CMAKE_BUILD_TYPE "${BUILD_TYPE}")
if(MSVC)
    if("${BUILD_TYPE}" STREQUAL "Release")
        add_definitions( "-O2" )
    endif()
else()
    set(LINUX_ARGS "-std=c++17 -finput-charset=UTF-8 -fPIC -pthread")
    if("${BUILD_TYPE}" STREQUAL "Release")
        set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS_INIT}  ${LINUX_ARGS} -O2")
        set(CMAKE_C_FLAGS "-O2")
    else()
        set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS_INIT}  ${LINUX_ARGS} -g2")
        set(CMAKE_C_FLAGS "-g2")
    endif()
endif()
# -------------------------- ARGUMENTS ----------------------------------------
# -------------------------- CONFIGURATION ------------------------------------
set(LIB_DIR     ${INSTALL_PREFIX}/Projects/${LIB})
set(INC         ${LIB_DIR}/include)
set(SRC         ${LIB_DIR}/src)

set(XSTRING_DIR ${INSTALL_PREFIX}/Projects/${LIB})
# -------------------------- CONFIGURATION ------------------------------------
# -------------------------- BUILD --------------------------------------------
add_library(${LIB} STATIC 

    ${INC}/${LIB}.h
    ${SRC}/${LIB}.cpp

    ${INC}/std_xstring.h
    ${SRC}/std_xstring.cpp
)
add_library(radical::${LIB} ALIAS ${LIB})

include_directories(${LIB}
    PRIVATE
        ${NEXUS_DIR}/include
        ${XVECTOR_DIR}/include
        
        ${XSTRING_DIR}/include
)

target_link_libraries(${LIB} radical::Nexus)
target_link_libraries(${LIB} radical::xvector)
# -------------------------- BUILD --------------------------------------------
# -------------------------- END ----------------------------------------------
