cmake_minimum_required(VERSION 3.5)

project(speech-synthesis LANGUAGES CXX)

add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenMP REQUIRED)

# Espeak library
if (WIN32)
	find_library(ESPEAK_LIBRARY libespeak-ng HINTS lib)
elseif(UNIX)
	find_library(ESPEAK_LIBRARY espeak-ng REQUIRED)
endif()

# Inclusion of code
set(VIEWS_DIR "${CMAKE_SOURCE_DIR}/views")
set(SOURCES_DIR "${CMAKE_SOURCE_DIR}/sources")
set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")
set(ESPEAK_INTERFACE_DIR "${SOURCES_DIR}/espeak-interface")

include_directories(${VIEWS_DIR})
include_directories(${SOURCES_DIR})
include_directories(${ESPEAK_INTERFACE_DIR})


file(GLOB_RECURSE SOURCES
  "${VIEWS_DIR}/*.ui"
  "${SOURCES_DIR}/*.h"
  "${SOURCES_DIR}/*.cpp"
  "${ESPEAK_INTERFACE_DIR}/*.h"
  "${ESPEAK_INTERFACE_DIR}/*.cpp"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${VIEWS_DIR})

if (WIN32)
	add_executable(speech-synthesis WIN32 ${SOURCES})
elseif(UNIX)
	add_executable(speech-synthesis ${SOURCES})
endif()

# Include QT libraries
target_link_libraries(speech-synthesis PRIVATE Qt5::Widgets)
target_link_libraries(speech-synthesis PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(speech-synthesis PRIVATE ${ESPEAK_LIBRARY})

# Add the target includes
target_include_directories(speech-synthesis PRIVATE ${VIEWS_DIR})
target_include_directories(speech-synthesis PRIVATE ${SOURCES_DIR})
target_include_directories(speech-synthesis PRIVATE ${ESPEAK_INTERFACE_DIR})
