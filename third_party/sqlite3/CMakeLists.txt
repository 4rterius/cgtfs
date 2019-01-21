## Unofficial CMakeLists for the sqlite3 library
## -----------------------------------------------------------------

# Note: the library itself is downloaded by CMake
# for the CGTFS project.

cmake_minimum_required(VERSION 3.0)
project(sqlite3 VERSION 3.26.0)

add_library(sqlite3 "sqlite3/sqlite3.c")
include_directories("sqlite3/")
target_link_libraries(sqlite3 pthread dl)