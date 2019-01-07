# CGTFS - C library to read static GTFS feeds

![Release version plate](https://img.shields.io/github/release-pre/rakhack/cgtfs.svg)
![Code size plate](https://img.shields.io/github/languages/code-size/rakhack/cgtfs.svg)
![License: MIT plate](https://img.shields.io/github/license/rakhack/cgtfs.svg)

A thin and fast low-level library which reads GTFS static feeds. This library provides a readable and intuitive C interface for parsing data provided in the format defined by Google's [General Transit Feed Specification](https://developers.google.com/transit/gtfs/).

*Note: as of the last README update, this library is deep in the development stage. Though it is tested and already provides the described functionality, it might not be doing that in the most efficient or stable manner. As such, caution is advised when using **cgtfs**.*

## Examples

```c
#include <stdio.h>
#include "feed.h"

// Example 0: read all feed data into memory
// (!) be careful, as reading ~12mb feed will take ~200mb of RAM.
void some_function(void) {
    feed_t amazing_feed = empty_feed();
    read_feed("/path/to/unpacked/gtfs/", &amazing_feed);

    if (amazing_feed.agency_count > 0)
        printf("The agency's name is: %s \n", amazing_feed.agencies[0].name);
    else
        perror("Failed to open agency.txt or the file has no records");
}
```

Unfortunately, as of version 0.1.0, the memory usage is far from sensible, and into-database reading is not yet implemented (but will be soon). Hence, it is generally recommended to use individual readers instead, as shown in the `example 1` below.

```c
#include <stdio.h>
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

As of version 0.1.0, the library has no dependencies. However, as a database integration for higher speed and memory efficiency is in plans, [*SQLite*](https://www.sqlite.org/index.html) might become one.

The downside is that extraction of GTFS .zip needs to be done separately.

### Build process

```
$ cd /path/to/cgtfs/
$ mkdir build && cd build/
$ cmake .. && cmake --build .

$ ./tests    # on Linux; tests executable location on Windows may vary
```

## API overview

This library tries to provide a semantic and readable interface. Before release 1.0.0, the library's API is a subject to change without backwards-compatibility.

### Structures

#### Record structures

Each of the following structs has fields according to its respective specification.

Additionally, they all have `is_null` integer field set to 1 unless all *required* fields have been parsed by their `read_*` function (structs have been designed for use with reader functions, for instance, `read_agency(..)` returns a parsed `agency_t` structure).

It is recommended to instantiate them with `empty_*()` function return value.

*Please note: All IDs are stored as strings.*

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

As with record structs, it is recommended to instantiate it with `empty_feed()` value.

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
`int read_header(FILE *fp, char ***field_names)` | `fp` - opened file stream to read header from; `field_names` - pointer to an array of c-strings, to write field names into | Number of fields
`int read_record(FILE *fp, int fields_number, char ***record_values)` | `fp` - opened file stream to read a row from; `fields_number` - number of fields to parse; `record_values` - pointer to an array of c-strings, to write row values into | 1 on success, -1 on file reading error
`int count_lines(FILE *fp)` | `fp` - opened file stream to count lines in | Number of lines in the file, -1 on file reading error

#### Enumeration parsers

For each of the aforementioned [enumerations](#enumerations), a parser exists that takes a c-string argument and returns an enum value. These parsers also ensure default values correctness (according to the GTFS spec). The list of these parsers is as following:

```c
service_availability_t parse_service_availability(char *value);
exception_type_t parse_exception_type(char *value);
payment_method_t parse_payment_method(char *value);
transfers_state_t parse_transfer_state(char *value);
time_exactness_t parse_time_exactness(char *value);
route_type_t parse_route_type(char *value);
location_type_t parse_location_type(char *value);
wheelchair_boarding_t parse_wheelchair_boarding(char *value);
stop_type_t parse_stop_type(char *value);
timepoint_precision_t parse_timepoint_precision(char *value);
transfer_type_t parse_transfer_type(char *value);
wheelchair_accessible_t parse_wheelchair_accessibility(char *value);
bikes_allowed_t parse_bike_allowance(char *value);
```

#### Record reading and initialization functions

For each of the aforementioned [record structs](#record-structures), an initialization function `* empty_*(void)` and a reader `* read_*(int field_count, char **field_names, char **field_values)` exist. Initialization functions take nothing and return an empty struct (with default values set and initialized). Readers take a number of fields, an array of c-strings with names of the fields, and an array of field values of a single row (record).

All of these functions are given in the following list:

```c
agency_t empty_agency(void);
agency_t read_agency(int field_count, char **field_names, char **field_values);

calendar_record_t empty_calendar_record(void);
calendar_record_t read_calendar_record(int field_count, char **field_names, char **field_values);

calendar_date_t empty_calendar_date(void);
calendar_date_t read_calendar_date(int field_count, char **field_names, char **field_values);

fare_attributes_t empty_fare_attributes(void);
fare_attributes_t read_fare_attributes(int field_count, char **field_names, char **field_values);

fare_rule_t empty_fare_rule(void);
fare_rule_t read_fare_rule(int field_count, char **field_names, char **field_values);

feed_info_t empty_feed_info(void);
feed_info_t read_feed_info(int field_count, char **field_names, char **field_values);

frequency_t empty_frequency(void);
frequency_t read_frequency(int field_count, char **field_names, char **field_values);

route_t empty_route(void);
route_t read_route(int field_count, char **field_names, char **field_values);

shape_t empty_shape(void);
shape_t read_shape(int field_count, char **field_names, char **field_values);

stop_t empty_stop(void);
stop_t read_stop(int field_count, char **field_names, char **field_values);

stop_time_t empty_stop_time(void);
stop_time_t read_stop_time(int field_count, char **field_names, char **field_values);

transfer_t empty_transfer(void);
transfer_t read_transfer(int field_count, char **field_names, char **field_values)

trip_t empty_trip(void);
trip_t read_trip(int field_count, char **field_names, char **field_values);
```


#### File readers

File readers are functions that handle reading entire files, e.g. `routes.txt`. They are convenient wrappers around [record readers](#record-reading-and-initialization-functions) which:

- read file headers;
- count records and allocate sufficient memory for the resulting record structs;
- loop through the file lines and read each of them using record readers;
- free their own temporary memory.

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

##### filenames.h

Function | Arguments | Returns
-------- | --------- | -------
`void make_filepath(char **out, const char *dirname, const char *filename)` | `out` - pointer to c-string to write resulting filepath into; `dirname` and `filename` - c-strings with directory and file names to concatenate | Nothing

##### haversine.h

Function | Arguments | Returns
-------- | --------- | -------
`double dg_to_rad(long double d)` | `d` - degrees to translate into radians | Radians
`double haversine_distance(geo_location_t a, geo_location_t b)` | `a` - latitude and longitude of point A; `b` - lat. & lon. of point B | Meters between points A and B


## Useful links

- [Official GTFS static reference](https://developers.google.com/transit/gtfs/reference/)
- [Other GTFS handling libraries](https://github.com/CUTR-at-USF/awesome-transit#gtfs-libraries)

## License and attribution

The library is developed and distributed under the [MIT License](https://choosealicense.com/licenses/mit/), a copy of which can be found in the root of the project. Documentation and materials other than the library's source code are distributed under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/).

Files under the `tests/data/google_sample` directory constitute [an example Google Transit Feed](https://developers.google.com/transit/gtfs/examples/gtfs-feed) created and [shared by Google](https://developers.google.com/readme/policies/) and are used according to terms described in the [Creative Commons 3.0 Attribution License](https://creativecommons.org/licenses/by/3.0/).

Other files under the `tests/data` directory may contain elements of the [open data](http://www.lsl.fi/lisatietoa/avoin-data/) publicly provided by [Lahden Seudun Liikenne](http://www.lsl.fi/) under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/deed.fi).
