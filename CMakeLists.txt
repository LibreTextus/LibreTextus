project(LibreTextus)

cmake_minimum_required(VERSION 2.6)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(libre_textus SHARED
	src/window.hpp
	src/window.cpp
)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(LibreTextus src/main.cpp)

target_link_libraries(libre_textus ${GTKMM_LIBRARIES})
target_link_libraries(LibreTextus ${GTKMM_LIBRARIES} libre_textus)

file(COPY data/ DESTINATION data/)
