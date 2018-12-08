## Project setup
## -----------------------------------------------------------------

cmake_minimum_required(VERSION 3.0)
project(cgtfs VERSION 0.1.0)


## Flags and settings
## -----------------------------------------------------------------

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(sources
  "src/agency.c"
  "src/calendar_dates.c"
  "src/calendar.c"
  "src/fare_attributes.c"
  "src/fare_rule.c"
  "src/haversine.c"
  "src/reading.c"
  "src/reading_utils.c"
)

set(include_dirs
  "includes/"
  "tests/"
)

set(libraries
  m
)

include_directories(${include_dirs})


## Library
## -----------------------------------------------------------------

add_library(cgtfs STATIC ${sources})
target_link_libraries(cgtfs ${libraries})
set_target_properties(cgtfs PROPERTIES VERSION ${PROJECT_VERSION})


## Tests
## -----------------------------------------------------------------

add_executable(tests tests/_all.c)
add_dependencies(tests cgtfs)
target_link_libraries(tests cgtfs)
