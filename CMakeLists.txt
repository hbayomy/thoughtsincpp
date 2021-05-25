# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)

project ("ThoughtsInCPP")

set(CMAKE_CXX_STANDARD 14)

include(./conanbuildinfo.cmake)
conan_basic_setup()

enable_testing()

include(GoogleTest)

add_library (riddle_tree STATIC "src/riddle_tree/RiddleTree.cpp" "src/riddle_tree/RiddleTree.h")
target_link_libraries (riddle_tree ${CONAN_LIBS})

add_executable (RiddleTreeTest "test/RiddleTreeTest.cpp" "test/RiddleTreeTest.h")
target_link_libraries(RiddleTreeTest riddle_tree ${CONAN_LIBS_GTEST})

add_test(RiddleTreeTest bin/RiddleTreeTest)
