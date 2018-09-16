cmake_minimum_required (VERSION 3.0)

set(TARGET_NAME "LevensteinDistanceInTries")

set (GTEST_DIR "D:/Code/BxMed/cots/gtest/win")
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

include_directories(${GTEST_INCLUDE_DIRS} sources)
add_executable(${TARGET_NAME} Main.cpp ${SOURCES} ${HEADERS} ${BENCHMARK_SOURCES} ${BENCHMARK_HEADERS} ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(${TARGET_NAME} ${GTEST_ALL_LIBS})

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/benchmarks/data/ $<TARGET_FILE_DIR:${TARGET_NAME}>/data/)

