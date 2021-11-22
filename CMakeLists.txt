cmake_minimum_required(VERSION 3.16)

project(base64 VERSION 0.2.0 LANGUAGES CXX)

option(BUILD_STATIC "Build a static library" ON)

set(LIBRARY_NAME "base64")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)

add_executable(app ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_compile_options(app PRIVATE "-Wall")

if(BUILD_STATIC)
    add_library(${LIBRARY_NAME} STATIC ${CMAKE_SOURCE_DIR}/src/base64.cpp)
else()
    set(LIBRARY_NAME "${LIBRARY_NAME}_shared")
    add_library(${LIBRARY_NAME} SHARED ${CMAKE_SOURCE_DIR}/src/base64.cpp)
endif()

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(app PRIVATE ${LIBRARY_NAME})

# Include directories for the chosen lib
target_include_directories(${LIBRARY_NAME} PUBLIC
$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Write CMake package config files
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
  ${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}-${PROJECT_VERSION}
)

write_basic_package_version_file(
  ${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

set(EXPORT_NAME ${PROJECT_NAME}_Exports)

## Installation ##
## Install targets(lib) ##
install(TARGETS
  ${LIBRARY_NAME}
  EXPORT ${EXPORT_NAME}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

## Install headers ##

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING
  PATTERN *.h
  PATTERN *.hpp
)

## Install export ##
install(EXPORT
  ${EXPORT_NAME}
  NAMESPACE
  base_six_four::
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}-${PROJECT_VERSION}
)

## Install config and version files ##
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}-${PROJECT_VERSION}
)

