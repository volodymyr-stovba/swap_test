file(GLOB_RECURSE EVAL_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h*" "*.c*")  

add_library(swap STATIC ${EVAL_SOURCES})

target_compile_definitions(swap PUBLIC 
  _CRT_SECURE_NO_WARNINGS 
)

target_include_directories(swap PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
