# Project name
project(DT018G)

# Minimum required cmake version
cmake_minimum_required(VERSION 3.2)

# Compile with c++ 11 support
set(CMAKE_CXX_STANDARD 11)

# Static inclusion of dependencies required for the executables to be independent
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# Add executables for all run configurations, but delegate the details to subscripts
add_subdirectory(Laboration_1)
add_subdirectory(Laboration_2)
add_subdirectory(Laboration_3)
add_subdirectory(Project)