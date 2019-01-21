## Project setup
## -----------------------------------------------------------------

include(ExternalProject)

cmake_minimum_required(VERSION 3.0)
project(cgtfs VERSION 0.2.0)


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

ExternalProject_Add(sqlite3_dep 
  TMP_DIR "build/tmp/deps/sqlite3"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/third_party/sqlite3/sqlite3"
  SOURCE_SUBDIR "../"

  URL "https://www.sqlite.org/2018/sqlite-amalgamation-3260000.zip"
  URL_HASH SHA1=a7405b6a3e59287db589fc0efcc72ccf46ae7ed0

  INSTALL_COMMAND cmake -E echo "Skipping install step..."
)


## Library
## -----------------------------------------------------------------

add_library(cgtfs STATIC ${sources})
add_dependencies(cgtfs sqlite3_dep)
set_target_properties(cgtfs PROPERTIES VERSION ${PROJECT_VERSION})

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  target_link_libraries(cgtfs m)
endif()

## Tests
## -----------------------------------------------------------------

add_executable(tests tests/_all.c)
add_dependencies(tests cgtfs)
target_link_libraries(tests cgtfs)

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