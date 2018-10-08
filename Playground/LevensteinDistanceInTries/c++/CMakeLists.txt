cmake_minimum_required (VERSION 3.0)

set(TARGET_NAME "LevensteinDistanceInTries")

set (GTEST_DIR "C:/Program Files/googletest-distribution")
set (GTEST_ALL_LIBS 
		${GTEST_DIR}/lib/gtest.lib
		${GTEST_DIR}/lib/gtest_main.lib
		${GTEST_DIR}/lib/gmock.lib
		${GTEST_DIR}/lib/gmock_main.lib)
set (GTEST_INCLUDE_DIRS ${GTEST_DIR}/include/)

# === Compilation & Linking ===

project(${TARGET_NAME} CXX)

file(GLOB HEADERS sources/*.hpp)
file(GLOB SOURCES sources/*.cpp)

file(GLOB BENCHMARK_HEADERS benchmarks/*.hpp)
file(GLOB BENCHMARK_SOURCES benchmarks/*.cpp)

file(GLOB TEST_HEADERS tests/*.hpp)
file(GLOB TEST_SOURCES tests/*.cpp)

add_library(${TARGET_NAME} SHARED ${SOURCES} ${HEADERS})
target_compile_definitions(${TARGET_NAME} PRIVATE LevensteinDistanceInTries_EXPORTS)
set_target_properties(${TARGET_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BUILD_DIRECTORY}/bin")

add_executable(${TARGET_NAME}Tests ${TEST_SOURCES} ${TEST_HEADERS})
target_include_directories(${TARGET_NAME}Tests PUBLIC ${GTEST_INCLUDE_DIRS} sources)
target_link_libraries(${TARGET_NAME}Tests ${GTEST_ALL_LIBS} ${TARGET_NAME})
set_target_properties(${TARGET_NAME}Tests PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY  $<TARGET_FILE_DIR:${TARGET_NAME}Tests>)

add_executable(${TARGET_NAME}Benchmarks ${BENCHMARK_SOURCES} ${BENCHMARK_HEADERS})
target_include_directories(${TARGET_NAME}Benchmarks PUBLIC sources)
target_link_libraries(${TARGET_NAME}Benchmarks ${TARGET_NAME})
set_target_properties(${TARGET_NAME}Benchmarks PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY  $<TARGET_FILE_DIR:${TARGET_NAME}Benchmarks>)

add_custom_command(TARGET ${TARGET_NAME}Benchmarks POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/benchmarks/data/ $<TARGET_FILE_DIR:${TARGET_NAME}Benchmarks>/data/)
