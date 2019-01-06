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
- | -
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


### Functions

*Work in progress*


## Useful links

- [Official GTFS static reference](https://developers.google.com/transit/gtfs/reference/)
- [Other GTFS handling libraries](https://github.com/CUTR-at-USF/awesome-transit#gtfs-libraries)

## License and attribution

The library is developed and distributed under the [MIT License](https://choosealicense.com/licenses/mit/), a copy of which can be found in the root of the project. Documentation and materials other than the library's source code are distributed under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/).

Files under the `tests/data/google_sample` directory constitute [an example Google Transit Feed](https://developers.google.com/transit/gtfs/examples/gtfs-feed) created and [shared by Google](https://developers.google.com/readme/policies/) and are used according to terms described in the [Creative Commons 3.0 Attribution License](https://creativecommons.org/licenses/by/3.0/).

Other files under the `tests/data` directory may contain elements of the [open data](http://www.lsl.fi/lisatietoa/avoin-data/) publicly provided by [Lahden Seudun Liikenne](http://www.lsl.fi/) under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/deed.fi).