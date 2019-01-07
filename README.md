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

#### Record readers

*Work in progress*

#### Enumeration parsers

*Work in progress*

#### File readers

*Work in progress*

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
