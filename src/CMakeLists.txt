file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${xcmdparser_SOURCE_DIR}/include/*.h")

add_library(xcmdparser STATIC
    cmdparser.c
    ${HEADER_LIST}
)

target_include_directories(xcmdparser PUBLIC ../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
