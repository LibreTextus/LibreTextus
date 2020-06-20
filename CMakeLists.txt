project(LibreTextus)

cmake_minimum_required(VERSION 3.7)

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
	src/log.hpp
	src/log.cpp
	src/history_button.hpp
	src/history_button.cpp
	)

# BUILD LOCALES

add_definitions(-DGETTEXT_PACKAGE="libretextus")

if (NOT EXISTS "${CMAKE_BINARY_DIR}/locale")
	execute_process(COMMAND "mkdir" "${CMAKE_BINARY_DIR}/locale")
endif()

file(GLOB PO_FILES "${CMAKE_SOURCE_DIR}/po/*.po")

foreach(PO_FILE ${PO_FILES})
	get_filename_component(PO_NAME ${PO_FILE} NAME_WE)

	if (NOT EXISTS "${CMAKE_BINARY_DIR}/locale/${PO_NAME}/LC_MESSAGES/")
		execute_process(COMMAND "mkdir" "-p" "${CMAKE_BINARY_DIR}/locale/${PO_NAME}/LC_MESSAGES")
	endif()

	execute_process(COMMAND "msgfmt" "--check" "--verbose" "--output-file" "${CMAKE_BINARY_DIR}/locale/${PO_NAME}/LC_MESSAGES/libretextus.mo" "${PO_FILE}")
endforeach()

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS regex)

include_directories(${Boost_INCLUDE_DIRS})

include_directories(include/)

add_executable(LibreTextus src/main.cpp)

target_link_libraries(libre_textus ${GTKMM_LIBRARIES} ${X11_LIBRARIES} ${Boost_LIBRARIES} stdc++fs)
target_link_libraries(LibreTextus ${GTKMM_LIBRARIES} ${X11_LIBRARIES} ${Boost_LIBRARIES} libre_textus stdc++fs)

enable_testing()
add_executable(md_test test/md_test.cpp)
target_link_libraries(md_test libre_textus)
add_test(markdown_test md_test)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS md_test)


file(COPY data/ DESTINATION data/)

install(TARGETS LibreTextus DESTINATION .)
install(DIRECTORY ${CMAKE_BINARY_DIR}/data DESTINATION .)
install(DIRECTORY ${CMAKE_BINARY_DIR}/locale DESTINATION .)
install(TARGETS libre_textus DESTINATION .)
install(FILES libretextus.desktop DESTINATION .)
