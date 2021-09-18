cmake_minimum_required(VERSION 3.20)

project(templates_test LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

add_subdirectory(src/common)

file(GLOB SRC_LIST CONFIGURE_DEPENDS "src/*.cpp")

foreach(srcfile ${SRC_LIST})
	get_filename_component(target "${srcfile}" NAME_WE)
	add_executable(${target} ${srcfile})

	target_compile_features(${target} PRIVATE cxx_std_17)
	set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)

	if (MSVC)
		target_compile_options(${target} PRIVATE /W4)
	else()
		target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
	endif()

	target_link_libraries(${target} common)
endforeach()