if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Android")
    file(GLOB_RECURSE XCMDPARSER_TEST_SRC "*.c")

    add_executable(xcmdparser_test ${XCMDPARSER_TEST_SRC} "common.h")

    target_link_libraries(xcmdparser_test xcmdparser)
endif()
