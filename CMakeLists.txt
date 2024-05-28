cmake_minimum_required(VERSION 2.8)
project(sylar)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")
include_directories(.)
include_directories(/apps/sylar/include)
link_directories(/apps/sylar/lib)


find_library(YAMLCPP libyaml-cpp.a)

# 手动设置YAML-CPP库路径
set(YAMLCPP /apps/sylar/lib/libyaml-cpp.a)

# 确认YAML-CPP库路径正确
if (EXISTS ${YAMLCPP})
    message(STATUS "YAML-CPP library found: ${YAMLCPP}")
else()
    message(FATAL_ERROR "YAML-CPP library not found: ${YAMLCPP}")
endif()

set(LIB_SRC
    sylar/log.cc
    sylar/util.cc
    sylar/config.cc
    )

add_library(sylar SHARED ${LIB_SRC})
#add_library(sylar_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (sylar_static PROPERTIES OUTPUT_NAME "sylar")

add_executable(test tests/test.cc)
add_dependencies(test sylar)
target_link_libraries(test sylar ${YAMLCPP})

add_executable(test_config tests/test_config.cc)
add_dependencies(test_config sylar)
target_link_libraries(test_config sylar ${YAMLCPP})

# add_executable(test3 tests/test3.cc)
# add_dependencies(test3 sylar)
# target_link_libraries(test3 sylar -L/apps/sylar/lib -lyaml-cpp)



SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)