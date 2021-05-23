# CMakeList.txt : CMake project for ThoughtsInCPP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

enable_testing()



# Add source to this project's executable.
add_executable (ThoughtsInCPPTest "RiddleTreeTest.cpp" "RiddleTreeTest.h")

# TODO: Add tests and install targets if needed.
target_link_libraries(ThoughtsInCPPTest riddle_tree ${CONAN_LIBS_GTEST})
