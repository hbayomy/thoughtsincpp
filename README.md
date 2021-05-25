# Thoughts In CPP
Is a code under Apacje License for beginners to learn how to write code for data structures in high quality manner.


### First you have to install the following: 
git   (https://git-scm.com/downloads) \
cmake (https://cmake.org/download/) \
conan (https://conan.io/downloads.html)



### Then to Compile the Code (OSX, Linux, Windows):

git clone https://github.com/hbayomy/thoughtsincpp.git \
cd thoughtsincpp \
conan install . -s build_type=Debug --remote=conan-center \
mkdir build \
cd build \
cmake .. \
cmake --build .

### To run tests

ctest -V
