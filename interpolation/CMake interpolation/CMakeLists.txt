cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Main VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the MathFunctions library
add_subdirectory(Math)
list(APPEND EXTRA_LIBS Math)


# add the executable
add_executable(Main main.cpp)

target_link_libraries(Main PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
