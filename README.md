# CGTFS - C library to read static GTFS feeds

![Release version plate](https://img.shields.io/github/release-pre/rakhack/cgtfs.svg)
![Build Status](https://travis-ci.com/rakhack/cgtfs.svg?branch=master)
![License: MIT plate](https://img.shields.io/github/license/rakhack/cgtfs.svg)

A thin and fast low-level library which reads GTFS static feeds. This library provides a readable and intuitive C interface for parsing data provided in the Google's [General Transit Feed Specification](https://developers.google.com/transit/gtfs/) format.

## Table of contents

- [CGTFS - C library to read static GTFS feeds](#cgtfs---c-library-to-read-static-gtfs-feeds)
  - [Table of contents](#table-of-contents)
  - [Examples](#examples)
  - [Build process and dependencies](#build-process-and-dependencies)
    - [Dependencies](#dependencies)
    - [Build process](#build-process)
    - [Documentation](#documentation)
  - [API overview](#api-overview)
    - [Structures](#structures)
      - [Record structures](#record-structures)
      - [feed_t structure](#feedt-structure)
      - [Other structures](#other-structures)
    - [Enumerations](#enumerations)
    - [Functions](#functions)
      - [Reading utilities](#reading-utilities)
      - [Enumeration parsers](#enumeration-parsers)
      - [Record reading and initialization functions](#record-reading-and-initialization-functions)
      - [File readers](#file-readers)
      - [Helpers](#helpers)
        - [In filenames.h](#in-filenamesh)
        - [In haversine.h](#in-haversineh)
  - [Useful links](#useful-links)
  - [License and attribution](#license-and-attribution)

## Examples

```c
#include <stdio.h>
#include "feed.h"

// Example 0: read all feed data into memory
void some_function(void) {
    feed_t amazing_feed;
    
    init_feed(&amazing_feed);
    read_feed(&amazing_feed, "/path/to/unpacked/gtfs/");

    if (amazing_feed.agency_count > 0)
        printf("The agency's name is: %s \n", amazing_feed.agencies[0].name);
    else
        perror("Failed to open agency.txt or the file has no records");
    
    free_feed(&amazing_feed);
}
```

```c
#include <stdio.h>
#include "helpers/filenames.h"
#include "reading.h"

// Example 1: read all bus stops into memory
void another_function(void) {
    char *stops_filename;
    make_filepath(&stops_filename, "/path/to/unpacked/gtfs/", "stops.txt");

    int stops_count = 0;
    stop_t *stops;

    FILE *fp = fopen(stops_filename, "r");
    if (fp) {
        stops_count = read_all_stops(fp, &stops);
        fclose(fp);
    }

    for (int i = 0; i < stops_count; i++) {
        printf("=== Stop %i:\n", i + 1);
        printf(" -> stop_id == %s\n", stops[i].id);
        printf(" -> stop_name == %s\n", stops[i].name);
        printf(" -> stop_lat == %Lf\n", stops[i].lat);
        printf(" -> stop_lon == %Lf\n", stops[i].lon);
        printf("\n");
    }

    free(stops_filename);
    free(stops);
}
```

## Build process and dependencies

### Dependencies

As of the last README update, the library has no dependencies, as was the development goal. However, it means that extraction of GTFS .zip needs to be done separately.

### Build process

The library should compile on `gcc >= 4.8.4`, `clang >= 5.0.0` and latest Microsoft's C/C++ compiler.

```
$ cd /path/to/cgtfs/
$ mkdir build && cd build/
$ cmake .. && cmake --build .

$ ./tests    # on Linux; tests executable location on Windows may vary
```

### Documentation

The library is heavily documented via code comments. To compile them into HTML, just run `doxygen`. The following section provides a brief overview of the API.

*However, this file is guaranteed to contain up-to-date information only on releases, so it is advised to download the latest relase from Releases page and read README.md of the release's latest commit.*

## API overview

This library tries to provide a semantic and readable interface. Before release 1.0.0, the library's API is a subject to change without backwards-compatibility concerns.

### Structures

#### Record structures

Each of the following structs has fields according to its respective specification.

Additionally, they all have `is_null` integer field set to 1 unless all *required* fields have been parsed by their `read_*` function (structs have been designed for use with reader functions, for instance, `read_agency(..)` parses data into an `agency_t` structure).

It is recommended to instantiate them with `init_*(..)` function return value.

*Note 1: All IDs are stored as strings.*

*Note 2: If member/field name starts with the name of the entity (for instance, `agency_id` of the `agency_t` struct), the entity name is omitted, to make naming semantic and avoid duplicity. Otherwise, struct member names correspond with the field names.*

Struct | Contents
------ | --------
`agency_t` | A record of the [agency.txt](https://developers.google.com/transit/gtfs/reference/#agencytxt) file
`calendar_date_t` | A record of the [calendar_dates.txt](https://developers.google.com/transit/gtfs/reference/#calendar_datestxt) file
`calendar_record_t` | A record of the [calendar.txt](https://developers.google.com/transit/gtfs/reference/#calendartxt) file
`fare_attributes_t` | A record of the [fare_attributes.txt](https://developers.google.com/transit/gtfs/reference/#fare_attributestxt) file
`fare_rule_t` | A record of the [fare_rules.txt](https://developers.google.com/transit/gtfs/reference/#fare_rulestxt) file
`feed_info_t` | A record of the [feed_info.txt](https://developers.google.com/transit/gtfs/reference/#feed_infotxt) file
`frequency_t` | A record of the [frequencies.txt](https://developers.google.com/transit/gtfs/reference/#frequenciestxt) file
`route_t` | A record of the [routes.txt](https://developers.google.com/transit/gtfs/reference/#routestxt) file
`shape_t` | A record of the [shapes.txt](https://developers.google.com/transit/gtfs/reference/#shapestxt) file
`stop_time_t` | A record of the [stop_times.txt](https://developers.google.com/transit/gtfs/reference/#stop_timestxt) file
`stop_t` | A record of the [stops.txt](https://developers.google.com/transit/gtfs/reference/#stopstxt) file
`transfer_t` | A record of the [transfers.txt](https://developers.google.com/transit/gtfs/reference/#transferstxt) file
`trip_t` | A record of the [trips.txt](https://developers.google.com/transit/gtfs/reference/#tripstxt) file

#### feed_t structure

`feed_t` is the compound structure which holds pointers to all of the aforementioned structs, and for each of them an integer field with the number of parsed records. `feed_t` is designed to be used with `read_feed(..)` (see [example 0](#examples)).

It is recommended to instantiate it with `init_feed(..)`. When an instance of the structure is no longer necessary, function `free_feed(..)` can handle freeing the memory.

#### Other structures

Additionally, this library defines `geo_location_t` structure with `latitude` and `longitude` fields of type `long double`.


### Enumerations

Enumerations are used in this library as a semantic and somewhat restricting method of storing data about fields which only allow specific values and define their own meaning behind every possible value.

Each of these enumerations has values according to the specification, and an obligatory `*_NOT_SET` field.

Names of enum values start with two capital letters (first letters of each word in the enum's name) and an underscore. For instance, `service_availability_t` has values `SA_UNAVAILABLE`, `SA_AVAILABLE` and `SA_NOT_SET`.

Enum | Contents
---- | --------
`service_availability_t` | Whether or not a [calendar record day](https://developers.google.com/transit/gtfs/reference/#calendartxt) has service available.
`exception_type_t` | What kind of an exception a [calendar date](https://developers.google.com/transit/gtfs/reference/#calendar_datestxt) presents.
`payment_method_t` | How do passangers pay [fare](https://developers.google.com/transit/gtfs/reference/#fare_attributestxt).
`transfers_state_t` | Whether [transfers](https://developers.google.com/transit/gtfs/reference/#fare_attributestxt) are permitted and how many times.
`time_exactness_t` | If time fields specified for a [frequency record](https://developers.google.com/transit/gtfs/reference/#frequenciestxt) are exact.
`route_type_t` | What kind of transport a [route](https://developers.google.com/transit/gtfs/reference/#routestxt) serves.
`location_type_t` | What kind of location a [stop](https://developers.google.com/transit/gtfs/reference/#stopstxt) represents.
`wheelchair_boarding_t` | Whether wheelchair boardings are possible on a particular [stop](https://developers.google.com/transit/gtfs/reference/#stopstxt).
`stop_type_t` | How passangers are picked up or dropped off at a stop at a particular [stop time](https://developers.google.com/transit/gtfs/reference/#stop_timestxt).
`timepoint_precision_t` | Whether timepoint of a particular [stop time](https://developers.google.com/transit/gtfs/reference/#stop_timestxt) is precise.
`transfer_type_t` | Whether [transfers](https://developers.google.com/transit/gtfs/reference/#transferstxt) are possible between two stops.
`wheelchair_accessible_t` | Whether wheelchairs are allowed on a particular [trip](https://developers.google.com/transit/gtfs/reference/#tripstxt).
`bikes_allowed_t` | Whether bikes are allowed on a particualr [trip](https://developers.google.com/transit/gtfs/reference/#tripstxt).


### Functions

#### Reading utilities

Low-level functions for reading CSV files. Declarations in `reading_utils.h`.

Function | Arguments | Returns
-------- | --------- | -------
`int read_header(FILE *fp, char ***field_names)` | `fp` - opened file stream to read header from; `field_names` - pointer to an array of c-strings, to write field names into | Number of fields on success, 0 on file reading error
`int read_record(FILE *fp, int fields_number, char ***record_values)` | `fp` - opened file stream to read a row from; `fields_number` - number of fields to parse; `record_values` - pointer to an array of c-strings, to write row values into | 1 on success, -1 on file reading error
`int count_lines(FILE *fp)` | `fp` - opened file stream to count lines in | Number of lines in the file, -1 on file reading error

#### Enumeration parsers

For each of the aforementioned [enumerations](#enumerations), a parser exists that takes a c-string argument and returns an enum value. These parsers also ensure default values correctness (according to the GTFS spec). The list of these parsers is as following:

```c
service_availability_t parse_service_availability(const char *value);
exception_type_t parse_exception_type(const char *value);
payment_method_t parse_payment_method(const char *value);
transfers_state_t parse_transfer_state(const char *value);
time_exactness_t parse_time_exactness(const char *value);
route_type_t parse_route_type(const char *value);
location_type_t parse_location_type(const char *value);
wheelchair_boarding_t parse_wheelchair_boarding(const char *value);
stop_type_t parse_stop_type(const char *value);
timepoint_precision_t parse_timepoint_precision(const char *value);
transfer_type_t parse_transfer_type(const char *value);
wheelchair_accessible_t parse_wheelchair_accessibility(const char *value);
bikes_allowed_t parse_bike_allowance(const char *value);
```

#### Record reading and initialization functions

For each of the aforementioned [record structs](#record-structures), an initialization function `init_*(* *record)` and a reader `read_*(int field_count, char **field_names, char **field_values)` exist. Initialization functions take nothing and return an empty struct (with default values set and initialized). Readers take a number of fields, an array of c-strings with names of the fields, and an array of field values of a single row (record).

All of these functions are given in the following list:

```c
void init_agency(agency_t *record);
void read_agency(agency_t *record, int field_count, const char **field_names, const char **field_values);

void init_calendar_record(calendar_record_t *record);
void read_calendar_record(calendar_record_t *record, int field_count, const char **field_names, const char **field_values);

void init_calendar_date(calendar_date_t *record);
void read_calendar_date(calendar_date_t *record, int field_count, char **field_names, char **field_values);

void init_fare_attributes(fare_attributes_t *record);
void read_fare_attributes(fare_attributes_t *record, int field_count, char **field_names, char **field_values);

void init_fare_rule(fare_rule_t *record);
void read_fare_rule(fare_rule_t *record, int field_count, char **field_names, char **field_values);

void init_feed_info(feed_info_t *record);
void read_feed_info(feed_info_t *record, int field_count, char **field_names, char **field_values);

void init_frequency(frequency_t *record);
void read_frequency(frequency_t *record, int field_count, char **field_names, char **field_values);

void init_route(route_t *record);
void read_route(route_t *record, int field_count, char **field_names, char **field_values);

void init_shape(shape_t *record);
void read_shape(shape_t *record, int field_count, char **field_names, char **field_values);

void init_stop(stop_t *record);
void read_stop(stop_t *record, int field_count, char **field_names, char **field_values);

void init_stop_time(stop_time_t *record);
void read_stop_time(stop_time_t *record, int field_count, char **field_names, char **field_values);

void init_transfer(transfer_t *record);
void read_transfer(transfer_t *record, int field_count, char **field_names, char **field_values);

void init_trip(trip_t *record);
void read_trip(trip_t *record, int field_count, char **field_names, char **field_values);
```


#### File readers

File readers are functions that handle reading entire files, e.g. `routes.txt`. They are convenient wrappers around [record readers](#record-reading-and-initialization-functions) which:

- read file headers;
- count records and allocate sufficient memory for the resulting record structs;
- loop through the file lines and read each of them using record readers;
- free their own memory.

Each file reader takes an opened `FILE` stream (from where it reads) and a pointer to an array of structs (where the results are put).

The declarations of file readers are as follows:

```c
int read_all_agencies(FILE *fp, agency_t **records);
int read_all_calendar_dates(FILE *fp, calendar_date_t **records);
int read_all_calendar_records(FILE *fp, calendar_record_t **records);
int read_all_fare_attributes(FILE *fp, fare_attributes_t **records);
int read_all_fare_rules(FILE *fp, fare_rule_t **records);
int read_all_feed_info(FILE *fp, feed_info_t **records);
int read_all_frequencies(FILE *fp, frequency_t **records);
int read_all_routes(FILE *fp, route_t **records);
int read_all_shapes(FILE *fp, shape_t **records);
int read_all_stop_times(FILE *fp, stop_time_t **records);
int read_all_stops(FILE *fp, stop_t **records);
int read_all_transfers(FILE *fp, transfer_t **records);
int read_all_trips(FILE *fp, trip_t **records);
```


#### Helpers

Other useful functions, implemented for the library itself or potential future use.

##### In filenames.h

Function | Arguments
-------- | ---------
`void make_filepath(char **out, const char *dirname, const char *filename)` | `out` - pointer to c-string to write resulting filepath into; `dirname` and `filename` - c-strings with directory and file names to concatenate

##### In haversine.h

Function | Arguments | Returns
-------- | --------- | -------
`double dg_to_rad(long double d)` | `d` - degrees to translate into radians | Radians
`double haversine_distance(geo_location_t a, geo_location_t b)` | `a` - latitude and longitude of point A; `b` - lat. & lon. of point B | Meters between points A and B


## Useful links

  - [Official GTFS static reference](https://developers.google.com/transit/gtfs/reference/)
  - [Other GTFS handling libraries](https://github.com/CUTR-at-USF/awesome-transit#gtfs-libraries)

## License and attribution

The library is developed and distributed under the [MIT License](https://choosealicense.com/licenses/mit/), a copy of which can be found in the root of the project. Documentation and materials other than the library's source code are distributed under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/).

Files under the `tests/data/google_sample` directory constitute [an example Google Transit Feed](https://developers.google.com/transit/gtfs/examples/gtfs-feed) created and [shared by Google](https://developers.google.com/readme/policies/) and are used according to terms described in the [Creative Commons 3.0 Attribution License](https://creativecommons.org/licenses/by/3.0/). *Additionaly, parts of the in-code documentation may contain pieces of the [GTFS reference](https://developers.google.com/transit/gtfs/reference/).*

Other files under the `tests/data` directory may contain elements of the [open data](http://www.lsl.fi/lisatietoa/avoin-data/) publicly provided by [Lahden Seudun Liikenne](http://www.lsl.fi/) under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/deed.fi).