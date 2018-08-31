cmake_minimum_required (VERSION 3.0)

set(TARGET_NAME "KataTests")

set (GTEST_DIR "D:/Code/BxMed/cots/gtest/win")
set (GTEST_ALL_LIBS 
		${GTEST_DIR}/lib/gtest.lib
		${GTEST_DIR}/lib/gtest_main.lib
		${GTEST_DIR}/lib/gmock.lib
		${GTEST_DIR}/lib/gmock_main.lib)
set (GTEST_INCLUDE_DIRS ${GTEST_DIR}/include/)


# === Compilation & Linking ===

project(${TARGET_NAME} CXX)

file(GLOB HEADERS *.hpp)
file(GLOB SOURCES *.cpp)

include_directories(${GTEST_INCLUDE_DIRS} header)
add_executable(${TARGET_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${TARGET_NAME} ${GTEST_ALL_LIBS})

