cmake_minimum_required (VERSION 3.14)

add_library (riddle_tree STATIC "RiddleTree.cpp" "RiddleTree.h")
target_link_libraries (riddle_tree ${CONAN_LIBS})