cmake_minimum_required (VERSION 3.0)
project (ProjectEuler)

include_directories(../../includes)

add_executable(problem main.cpp)

add_custom_target(run ALL
	COMMAND problem
	DEPENDS problem
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})