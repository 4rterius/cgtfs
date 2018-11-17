## Project setup
## -----------------------------------------------------------------

cmake_minimum_required(VERSION 3.0)
project(cgtfs VERSION 0.1.0)


## Flags and settings
## -----------------------------------------------------------------

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(sources
  "src/haversine.c"
  "src/reading.c"
)

set(include_dirs
  "includes/"
  "tests/"
)

include_directories(${include_dirs})


## Library
## -----------------------------------------------------------------

add_library(cgtfs STATIC ${sources})
set_target_properties(cgtfs PROPERTIES VERSION ${PROJECT_VERSION})


## Tests
## -----------------------------------------------------------------

add_executable(tests tests/_all.c)
add_dependencies(tests cgtfs)
target_link_libraries(tests cgtfs)
