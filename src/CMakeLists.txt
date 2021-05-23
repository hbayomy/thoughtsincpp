# CMakeList.txt : CMake project for ThoughtsInCPP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

add_subdirectory ("riddle_tree")

# Add source to this project's executable.
add_executable (ThoughtsInCPP "ThoughtsInCPP.cpp" "ThoughtsInCPP.h")
target_link_libraries (ThoughtsInCPP riddle_tree ${CONAN_LIBS})
# TODO: Add tests and install targets if needed.
