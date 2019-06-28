# CGTFS - C library to read static GTFS feeds

A thin and fast low-level library which reads GTFS static feeds. This library provides a readable and intuitive C interface for parsing data provided in the Google's [General Transit Feed Specification](https://developers.google.com/transit/gtfs/) format.

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

    if (stops_count > 0) free(stops);
    free(stops_filename);
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

## Useful links

  - [Official GTFS static reference](https://developers.google.com/transit/gtfs/reference/)
  - [Other GTFS handling libraries](https://github.com/CUTR-at-USF/awesome-transit#gtfs-libraries)

## License and attribution

The library is developed and distributed under the [MIT License](https://choosealicense.com/licenses/mit/), a copy of which can be found in the root of the project. Documentation and materials other than the library's source code are distributed under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/).

Files under the `tests/data/google_sample` directory constitute [an example Google Transit Feed](https://developers.google.com/transit/gtfs/examples/gtfs-feed) created and [shared by Google](https://developers.google.com/readme/policies/) and are used according to terms described in the [Creative Commons 3.0 Attribution License](https://creativecommons.org/licenses/by/3.0/). *Additionaly, parts of the in-code documentation may contain pieces of the [GTFS reference](https://developers.google.com/transit/gtfs/reference/).*

Files under the `tests/data/pocono_pony` contain the open data publicly provided by [Monroe County Transportation Authority](https://www.gomcta.com/index.php) under the [Monroe County Transportation Authority Transit Data Developer Terms of Use](https://www.gomcta.com/developerapi.php).

Other files under the `tests/data` directory may contain elements of the [open data](http://www.lsl.fi/lisatietoa/avoin-data/) publicly provided by [Lahden Seudun Liikenne](http://www.lsl.fi/) under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/deed.fi).