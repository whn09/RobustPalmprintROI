########################################################################
# CMake build script for prdt.

option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." ON)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(PROJECT_NAME prdt)
PROJECT(${PROJECT_NAME})

SET(PROJECT_ROOT ${PROJECT_SOURCE_DIR})
SET(PRDT_ROOT ${PROJECT_SOURCE_DIR}/source)
SET(PRDT_PUB_HEADER ${PROJECT_SOURCE_DIR}/include)

FIND_PACKAGE(OpenCV REQUIRED)

MESSAGE(STATUS "——————————————————————————————————————")
MESSAGE(STATUS "PROJECT_NAME : " ${PROJECT_NAME})
MESSAGE(STATUS "DIR : " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "——————————————————————————————————————")

INCLUDE_DIRECTORIES(${PRDT_ROOT}/include/)
INCLUDE_DIRECTORIES(${PRDT_PUB_HEADER})
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

FILE(GLOB_RECURSE prdt_include_files
    ${PRDT_ROOT}/include/*.h
    ${PRDT_PUB_HEADER}/*.h
)

FILE(GLOB_RECURSE prdt_src_files
    ${PRDT_ROOT}/src/*.cc
    ${PRDT_ROOT}/src/*.cpp
    ${PRDT_ROOT}/src/*.c
)

SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/prdt_lib)
SET(srcs ${prdt_include_files} ${prdt_src_files})

ADD_LIBRARY(${PROJECT_NAME} ${srcs})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES VERSION 1.1 SOVERSION 1)

INSTALL(TARGETS prdt
        LIBRARY DESTINATION lib)
INSTALL(DIRECTORY ${PRDT_PUB_HEADER}/ DESTINATION include/prdt
        FILES_MATCHING PATTERN "*.h"
        PATTERN "apiInputsExample" EXCLUDE
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ)
INSTALL(FILES ${PROJECT_ROOT}/README.md RENAME AboutPRDT.md DESTINATION share/prdt)
INSTALL(FILES ${PROJECT_ROOT}/FindPRDT.cmake DESTINATION share/prdt)
EXECUTE_PROCESS(COMMAND touch /etc/ld.so.conf.d/prdt.conf
                COMMAND echo "${CMAKE_INSTALL_PREFIX}/lib"
                OUTPUT_FILE /etc/ld.so.conf.d/prdt.conf)
INSTALL(CODE "execute_process(COMMAND ldconfig)")
