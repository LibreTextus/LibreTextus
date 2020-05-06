project(LibreTextus_0.1)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(libre_textus STATIC
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
	src/package_manager.cpp
	src/package_manager.hpp
	src/text_view.hpp
	src/text_view.cpp
	src/path.hpp
	src/path.cpp
	src/notebook.hpp
	src/notebook.cpp
)

file(GLOB YAML_FILES
	include/yaml-cpp/*
)

add_library(yaml-cpp STATIC ${YAML_FILES})

include_directories(include/)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

add_executable(LibreTextus src/main.cpp)

target_link_libraries(libre_textus ${GTKMM_LIBRARIES} yaml-cpp ${X11_LIBRARIES} stdc++fs)
target_link_libraries(LibreTextus ${GTKMM_LIBRARIES} ${X11_LIBRARIES} libre_textus yaml-cpp stdc++fs)

file(COPY data/ DESTINATION data/)
file(COPY libretextus.desktop DESTINATION ./)

install(TARGETS LibreTextus DESTINATION .)
install(DIRECTORY data DESTINATION .)
install(TARGETS libre_textus DESTINATION .)
install(TARGETS yaml-cpp DESTINATION .)
install(FILES libretextus.desktop DESTINATION .)
