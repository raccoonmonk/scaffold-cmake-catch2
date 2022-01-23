cmake_minimum_required(VERSION 3.4)

project(scaffold LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

add_library(scaffold_library
	src/Library.h
	src/Library.cpp
)

set_target_properties(scaffold_library PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(scaffold_library PUBLIC src)

add_executable(${PROJECT_NAME}
	src/main.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE scaffold_library)

option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
	# Path to Catch2 CMake module
	list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/third_party/catch2/cmake")

	include(CTest)
	enable_testing()

	add_library(Catch INTERFACE)
	target_include_directories(Catch
		INTERFACE
			${PROJECT_SOURCE_DIR}/third_party/catch2
	)

	add_executable(tests
		tests/test_case.cpp
	)

	target_link_libraries(tests
		Catch
		scaffold_library
	)

	include(ParseAndAddCatchTests)
	ParseAndAddCatchTests(tests)
endif()
