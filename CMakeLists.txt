cmake_minimum_required(VERSION 3.1)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PATCH_VERSION 0.0.${PATCH_VERSION})

project(finder VERSION ${PATCH_VERSION})

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(finder
        main.c
        ${SOURCES}
        ${HEADERS}
        )

target_include_directories(finder PRIVATE "${CMAKE_SOURCE_DIR}/src/buffer")
target_include_directories(finder PRIVATE "${CMAKE_SOURCE_DIR}/src/executer")

set_target_properties(finder PROPERTIES COMPILE_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
set_target_properties(finder PROPERTIES LINK_FLAGS "-fsanitize=address -fno-omit-frame-pointer")


##
### Test definitions ###
##
configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)

set(install_destination "bin")
install(TARGETS finder DESTINATION "${install_destination}")

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT mesamsonov@mail.ru)

include(CPack)