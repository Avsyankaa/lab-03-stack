set(GOOGLETEST_ROOT gtest/googletest CACHE STRING "Google Test source root")

include_directories(SYSTEM
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gtest ${GOOGLETEST_SOURCES})
