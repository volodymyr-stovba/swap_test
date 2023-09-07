file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h*" "*.c*")  

add_executable(swap_test ${SOURCES}) 

target_include_directories(swap_test PUBLIC 
  ${SWAP_LIBRARY_INC}
)

target_link_libraries(swap_test LINK_PUBLIC 
  gtest_main
  swap
) 
    
include(GoogleTest)
gtest_discover_tests(swap_test)

set_target_properties(swap_test PROPERTIES FOLDER "Tests") 
install(TARGETS swap_test CONFIGURATIONS ${CMAKE_BUILD_TYPE} RUNTIME)
