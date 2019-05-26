## Project setup
## -----------------------------------------------------------------

include(ExternalProject)

cmake_minimum_required(VERSION 3.0)
project(cgtfs VERSION 0.2.0 LANGUAGES C)


## Flags and settings
## -----------------------------------------------------------------

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

set(sources
  "src/helpers/filenames.c"
  "src/helpers/haversine.c"

  "src/records/agency.c"
  "src/records/calendar_dates.c"
  "src/records/calendar.c"
  "src/records/fare_attributes.c"
  "src/records/fare_rule.c"
  "src/records/feed_info.c"
  "src/records/frequency.c"
  "src/records/route.c"
  "src/records/shape.c"
  "src/records/stop_time.c"
  "src/records/stop.c"
  "src/records/transfers.c"
  "src/records/trip.c"

  "src/database/database.c"
  "src/database/database_utils.c"
  "src/database/fetching.c"
  "src/database/storing.c"
  
  "src/database/records/agency.c"
  "src/database/records/calendar_dates.c"
  "src/database/records/calendar.c"
  "src/database/records/fare_attributes.c"

  "src/feed.c"
  "src/reading.c"
  "src/file_utils.c"
  "src/mem_utils.c"
)

set(include_dirs
  "includes/"
  "tests/"
  "third_party/"
)

include_directories(${include_dirs})


## sqlite3 dependency
## -----------------------------------------------------------------

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/sqlite3")


## Library
## -----------------------------------------------------------------

add_library(cgtfs STATIC ${sources})
add_dependencies(cgtfs sqlite3)
set_target_properties(cgtfs PROPERTIES VERSION ${PROJECT_VERSION})

target_link_libraries(sqlite3)

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  target_link_libraries(cgtfs m)
endif()

## Tests
## -----------------------------------------------------------------

add_executable(tests tests/_all.c)
add_dependencies(tests cgtfs)
target_link_libraries(tests cgtfs sqlite3)

## Benchmark
## -----------------------------------------------------------------

add_executable(bench tests/_bench.c)
add_dependencies(bench tests)
target_link_libraries(bench cgtfs)

## Examples
## -----------------------------------------------------------------

add_executable(example_0 examples/example_0.c)
add_dependencies(example_0 tests)
target_link_libraries(example_0 cgtfs)

add_executable(example_1 examples/example_1.c)
add_dependencies(example_1 tests)
target_link_libraries(example_1 cgtfs)



## Some more settings
## -----------------------------------------------------------------

set_target_properties(cgtfs tests bench example_0 example_1 PROPERTIES C_STANDARD 99)