file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${xcmdparser_SOURCE_DIR}/include/*.h")

add_library(xcmdparser STATIC
    cmdparser.c
    ${HEADER_LIST}
)

# check if isatty function exists
include(CheckSymbolExists)
check_symbol_exists(isatty "unistd.h" HAVE_UNISTD_ISATTY)
if(HAVE_UNISTD_ISATTY)
    target_compile_definitions(xcmdparser PRIVATE HAVE_UNISTD_ISATTY)
else()
    check_symbol_exists(_isatty "io.h" HAVE_IO_ISATTY)
    if(HAVE_IO_ISATTY)
        target_compile_definitions(xcmdparser PRIVATE HAVE_IO_ISATTY)
    endif()
endif()
target_include_directories(xcmdparser PUBLIC ../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
