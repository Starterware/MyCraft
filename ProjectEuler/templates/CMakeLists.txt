cmake_minimum_required (VERSION 3.0)
project (ProjectEuler)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11 -U__STRICT_ANSI__")

include_directories(../../includes)

add_executable(problem main.cpp)

if(EXISTS ../input.txt)

add_custom_target(run ALL
	COMMAND problem < ../input.txt
	DEPENDS problem
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

else()

add_custom_target(run ALL
	COMMAND problem
	DEPENDS problem
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
	
endif()

