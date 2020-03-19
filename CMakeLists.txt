project(LibreTextus)

cmake_minimum_required(VERSION 2.6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(libre_textus SHARED
	src/framework.hpp
	src/framework.cpp
	src/signal_handler.hpp
	src/signal_handler.cpp
	src/search_engine.hpp
	src/search_engine.cpp
	src/settings.hpp
	src/window.hpp
	src/window.cpp
	src/source_handler.hpp
	src/source_handler.cpp
)

include_directories(include/)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

include(FindPkgConfig)
pkg_search_module(YAMLCPP REQUIRED yaml-cpp)

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

add_executable(LibreTextus src/main.cpp)

target_link_libraries(libre_textus ${GTKMM_LIBRARIES} ${YAMLCPP_LIBRARIES} ${X11_LIBRARIES})
target_link_libraries(LibreTextus ${GTKMM_LIBRARIES} ${X11_LIBRARIES} libre_textus)

file(COPY data/ DESTINATION data/)
