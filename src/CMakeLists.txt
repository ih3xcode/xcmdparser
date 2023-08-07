file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${xcmdparser_SOURCE_DIR}/include/*.h")

add_library(xcmdparser STATIC
    cmdparser.c
    ${HEADER_LIST}
)

# check if isatty function exists
include(CheckSymbolExists)
check_symbol_exists(isatty "unistd.h" HAVE_ISATTY_UNISTD)
check_symbol_exists(isatty "io.h" HAVE_ISATTY_IO)
if(HAVE_ISATTY_UNISTD)
    target_compile_definitions(xcmdparser PRIVATE HAVE_ISATTY)
elseif(HAVE_ISATTY_IO)
    target_compile_definitions(xcmdparser PRIVATE HAVE_ISATTY)
endif()

target_include_directories(xcmdparser PUBLIC ../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
