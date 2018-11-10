## Project setup
## -----------------------------------------------------------------

cmake_minimum_required(VERSION 3.0)
project(cgtfs VERSION 0.1.0)


## Flags and settings
## -----------------------------------------------------------------

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(sources
  "src/haversine.c"
)

set(include_dirs
  "includes/"
)

include_directories(${include_dirs})


## Library
## -----------------------------------------------------------------

add_library(cgtfs SHARED ${sources})
set_target_properties(cgtfs PROPERTIES VERSION ${PROJECT_VERSION})
