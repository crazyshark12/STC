add_library(Math mymath.cpp)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(Math
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )