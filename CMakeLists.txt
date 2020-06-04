if(${CMAKE_VERSION} VERSION_LESS "3.11")
	message("Build LibreTextus with a newer version")
	message("-- Download CMake source")
	execute_process(COMMAND "git" "clone" "https://github.com/Kitware/CMake"
									WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
	)
	message("-- Install OpenSSL")
	execute_process(COMMAND "apt" "install" "libssl-dev"
									WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/CMake/"
	)
	message("-- Execute CMake/bootstrap")
	execute_process(COMMAND "${CMAKE_BINARY_DIR}/CMake/bootstrap"
									WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/CMake/"
	)
	message("-- Build CMake")
	execute_process(COMMAND "make"
									WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/CMake/"
	)
	message("-- Create bin")
	execute_process(COMMAND "mkdir" "${CMAKE_BINARY_DIR}/bin"
									WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
	)
	message("-- Configure LibreTextus")
	execute_process(COMMAND "${CMAKE_BINARY_DIR}/CMake/bin/cmake" "${CMAKE_SOURCE_DIR}" "-DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}"
									WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	)
	message("Done. Do 'cd bin; make' to build LibreTextus")
else()
	cmake_policy(SET CMP0048 NEW)
	cmake_policy(SET CMP0077 NEW)
	project(LibreTextus VERSION 0.1)

	cmake_minimum_required(VERSION 3.11)

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

	include(FetchContent)
	FetchContent_Declare(
			yaml-cpp
			GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
			GIT_SHALLOW	ON
			GIT_TAG yaml-cpp-0.6.3
		)
	FetchContent_GetProperties(yaml-cpp)
	if(NOT yaml-cpp_POPULATED)
		message(STATUS "Populating yaml-cpp...")
		FetchContent_Populate(yaml-cpp)
		set(YAML_CPP_BUILD_TESTS OFF CACHE BOOL "disable yaml tests")
		add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
		message(STATUS "Done.")
	endif()

	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -w")

	include_directories(BEFORE SYSTEM ${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR}/include)
	target_link_libraries(libre_textus yaml-cpp)

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

	target_link_libraries(libre_textus ${GTKMM_LIBRARIES} ${X11_LIBRARIES} ${Boost_LIBRARIES} yaml-cpp stdc++fs)
	target_link_libraries(LibreTextus ${GTKMM_LIBRARIES} ${X11_LIBRARIES} ${Boost_LIBRARIES} libre_textus stdc++fs)

	enable_testing()
	add_executable(md_test test/md_test.cpp)
	target_link_libraries(md_test libre_textus)
	add_test(markdown_test md_test)
	add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS md_test)


	file(COPY data/ DESTINATION data/)
	file(COPY libretextus.desktop DESTINATION ./)

	install(TARGETS LibreTextus DESTINATION .)
	install(DIRECTORY data DESTINATION .)
	install(TARGETS libre_textus DESTINATION .)
	install(FILES libretextus.desktop DESTINATION .)
endif()
