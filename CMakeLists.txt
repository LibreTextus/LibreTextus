project(LibreTextus)

cmake_minimum_required(VERSION 2.6)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(libre_textus SHARED
	src/window.hpp
	src/window.cpp
	src/signal_handler.hpp
	src/signal_handler.cpp
)

add_library(search_engine SHARED
	include/SearchEngine/SearchEngine.hpp
	include/SearchEngine/SearchEngine.cpp
)

include_directories(include/)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

include(FindPkgConfig)
pkg_search_module(YAMLCPP REQUIRED yaml-cpp)

add_executable(LibreTextus src/main.cpp)

target_link_libraries(libre_textus ${GTKMM_LIBRARIES})
target_link_libraries(LibreTextus ${GTKMM_LIBRARIES} libre_textus search_engine)
target_link_libraries(search_engine ${YAMLCPP_LIBRARIES})

file(COPY data/ DESTINATION data/)
