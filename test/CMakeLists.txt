include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories("${CMAKE_SOURCE_DIR}/src/buffer")
include_directories("${CMAKE_SOURCE_DIR}/src/executer")

file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

file(GLOB_RECURSE TESTS "${CMAKE_SOURCE_DIR}/test/*.cpp")
list(REMOVE_ITEM TESTS "${CMAKE_SOURCE_DIR}/test/main.cpp")

foreach(file ${TESTS})
    set(name)
    get_filename_component(name ${file} NAME_WE)
    add_executable("${name}_tests"
            ${HEADERS}
            ${SOURCES}
            ${file}
            "${CMAKE_SOURCE_DIR}/test/main.cpp")
    target_link_libraries("${name}_tests" gtest_main)
    add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()