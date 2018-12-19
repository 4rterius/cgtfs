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
  "src/dataset.c"
  "src/fare_attributes.c"
  "src/fare_rule.c"
  "src/feed_info.c"
  "src/frequency.c"
  "src/haversine.c"
  "src/reading.c"
  "src/reading_utils.c"
  "src/route.c"
  "src/shape.c"
  "src/stop_time.c"
  "src/stop.c"
  "src/transfers.c"
  "src/trip.c"
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

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  target_link_libraries(cgtfs m)
endif()

## Tests
## -----------------------------------------------------------------

add_executable(tests tests/_all.c)
add_dependencies(tests cgtfs)
target_link_libraries(tests cgtfs)
