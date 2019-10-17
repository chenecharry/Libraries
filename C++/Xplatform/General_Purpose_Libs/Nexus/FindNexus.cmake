cmake_minimum_required(VERSION 3.10)

set(LIB Nexus)

# -------------------------- ARGUMENTS ----------------------------------------
set(CMAKE_BUILD_TYPE "${BUILD_TYPE}")
if(MSVC)
    if("${BUILD_TYPE}" STREQUAL "Release")
        message("Buidling ${THIS} with -O2 ${BUILD_TYPE}")
        add_definitions( "-O2" )
    endif()
else()
    set(LINUX_ARGS "-std=c++17 -finput-charset=UTF-8 -fPIC -pthread")
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
set(NEXUS_DIR ${INSTALL_PREFIX}/code/${LIB})
# -------------------------- CONFIGURATION ------------------------------------
# -------------------------- BUILD --------------------------------------------
add_library(${LIB} 
    STATIC 
        ${NEXUS_DIR}/src/CPU_Threads.cpp
        ${NEXUS_DIR}/include/CPU_Threads.h

        ${NEXUS_DIR}/src/Task.cpp
        ${NEXUS_DIR}/include/Task.h

        ${NEXUS_DIR}/src/Job.cpp
        ${NEXUS_DIR}/include/Job.h

        ${NEXUS_DIR}/src/${LIB}.cpp
        ${NEXUS_DIR}/include/${LIB}.h

        ${NEXUS_DIR}/src/${LIB}_void.cpp
        ${NEXUS_DIR}/include/${LIB}_void.h

        ${NEXUS_DIR}/src/${LIB}_T.cpp
        ${NEXUS_DIR}/include/${LIB}_T.h
)
add_library(radical::${LIB} ALIAS ${LIB})

include_directories(${LIB}
    PRIVATE
        ${XVECTOR_DIR}/include
        ${XSTRING_DIR}/include
        ${XMAP_DIR}/include
        
        ${NEXUS_DIR}/include
)

target_link_libraries(${LIB} radical::xvector)
target_link_libraries(${LIB} radical::xstring)
target_link_libraries(${LIB} radical::xmap)
# -------------------------- BUILD --------------------------------------------
# -------------------------- END ----------------------------------------------
