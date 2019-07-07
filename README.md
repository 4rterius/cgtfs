# CGTFS - a C library to read static GTFS feeds

![Release version plate](https://img.shields.io/github/release/rakhack/cgtfs.svg)
[![Build Status](https://travis-ci.com/rakhack/cgtfs.svg?branch=master)](https://travis-ci.com/rakhack/cgtfs)
[![Build status](https://ci.appveyor.com/api/projects/status/etnrf1pg2g0a20jn/branch/master?svg=true)](https://ci.appveyor.com/project/rakhack/cgtfs/branch/master)
![License: MIT plate](https://img.shields.io/github/license/rakhack/cgtfs.svg)

A thin and fast low-level library which reads GTFS static feeds. This library provides a readable and intuitive C interface for parsing data provided in the Google's [General Transit Feed Specification](https://developers.google.com/transit/gtfs/) format.

**Docs: [available online](https://rakhack.github.io/cgtfs/doxygen/html/index.html).**

The scope of this library's functionality is illustrated by the following figure.

<div>
  <img width="500px" alt="Ways to parse/tranport data with CGTFS (scheme)" src="/docs/doxygen/static/df_straight.svg?raw=true&sanitize=true" />
</div>

## Table of contents

- [CGTFS - a C library to read static GTFS feeds](#CGTFS---a-C-library-to-read-static-GTFS-feeds)
  - [Table of contents](#Table-of-contents)
  - [Examples](#Examples)
  - [Build process and dependencies](#Build-process-and-dependencies)
    - [Dependencies](#Dependencies)
    - [Build process](#Build-process)
  - [Documentation](#Documentation)
    - [API overview](#API-overview)
  - [Useful links](#Useful-links)
  - [License and attribution](#License-and-attribution)

## Examples

Some example source code is located in the `examples/` folder of the library's source code. Digging into the `tests/` folder might as well be useful.

The most primitive example:

```c
#include <stdio.h>
#include "feed.h"

/**
 * Example 0: read all feed data into memory
 */
void some_function(void) {
    // Feed initialization.
    //
    // As with all entity structs (records, feed,
    // db connection, etc.), init_T(T *) function must be called.
    //
    // Every such struct has to be eventually freed by free_T(T *),
    // with the notable exception of all record entities
    // (a unified approach to struct handling is still WIP).
    feed_t amazing_feed;
    init_feed(&amazing_feed);

    // Feed reading.
    //
    // This function is a convenience wrapper for calling 
    // file-scope reading functions, which read the entire 
    // *.txt files into arrays. This function passes pointers
    // to feed_t fields, and after reading stores the counts
    // of each parsed record type into _count fields.
    // 
    // Obviously, takes **a lot** of memory.
    read_feed(&amazing_feed, "../tests/data/google_sample");

    // If a *.txt file does not exist or cannot be opened,
    // -1 is assigned to the corresponding _count field.
    // If the file can be opened but has no records, 0 is assigned.
    // Otherwise, the field gets the number of records read from the file.
    if (amazing_feed.agency_count > 0)
        printf("The agency's name is: %s \n", amazing_feed.agencies[0].name);
    else
        perror("Failed to open agency.txt or the file has no records");
    
    // Don't forget to call this function.
    // No, really :|
    free_feed(&amazing_feed);
}
```

A database setup and querying example (something like this is a likely use case):

```c
#include <stdio.h>

#include "feed.h"
#include "database/database.h"


int row_callback(void *, int column_count, char **data, char **column_names);


/**
 * Example 2: 
 * 
 * Store gtfs folder as a database and
 * query it for first 10 stop_time records
 * with arrival time within the next 10 minutes.
 */

// The querying itself is done via SQL.
// CGTFS only handles creating the database,
// setting up the layout and filling it with
// feeds' data.
const char *sql_query = 
    "SELECT stop_id, trip_id, arrival_time "
    "FROM stop_times "
    "WHERE arrival_time "
        "BETWEEN time('now', 'localtime') "
        "AND time('now', '+10 minutes', 'localtime') "
    "LIMIT 10;";

void some_database_manipulation(void) {
    char *error_msg = NULL;

    feed_db_t database;
    feed_db_status_t result;

    // Database connection initialization.
    //
    // This function sets up default values
    // for the connection struct
    // and opens the connection.
    //
    // Calling free_feed_db(..) is recommended as soon
    // as the connection is no longer needed.
    //
    // Opening the connection again is preferred to 
    // keeping stuff open and, thus, locked.
    //
    // The sign in `result < FEED_DB_SUCCESS` allows
    // the result of operation to be FEED_DB_PARTIAL (see docs),
    // though for now, it only really matters with store_feed_db(..) .
    result = init_feed_db(&database, "example2.db", 1);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to create/open a test database: %s !\n", database.error_msg);
        goto clearup;
    }

    // Database layout setup.
    //
    // This function is, basically, a wrapper around a giant SQL query.
    // Ideally, it is done every once in a set time interval (day, probably),
    // as there is no need to do it every time some information is needed.
    //
    // Every time the database is updated,
    // it must be deleted (left to the developer).
    //
    // This function is most likely to be followed by store_feed_db(..) .
    result = setup_feed_db(&database, 0);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to create the layout of the test database: %s !\n", database.error_msg);
        goto clearup;
    }

    // Feed storing.
    // 
    // This function reads every feed file 
    // and reads its records directly into the database,
    // without an intermediate array.
    //
    // Unless CGTFS_STORING_BATCH_TRANSACTIONS_OFF is defined, each
    // file's contents are stored in a single transaction.
    //
    // Both FEED_DB_SUCCESS and FEED_DB_PARTIAL are acceptable results.
    // Use equality sign only if your feed has records in EVERY possible
    // feed file.
    result = store_feed_db("../tests/data/pocono_pony", &database, NULL);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to store a test gtfs directory: data/pocono_pony: %s !\n", database.error_msg);
        goto clearup;
    }

    // The querying itself.
    database.rc = sqlite3_exec(database.conn, sql_query, row_callback, NULL, &error_msg);
    if (error_msg != NULL) {
        printf("Error while executing query: %s !\n", error_msg);
        goto clearup;
    }
    
    printf("Success.\n");

    clearup:
    sqlite3_free(error_msg);
    free_feed_db(&database);
}

int row_callback(void *param, int column_count, char **data, char **column_names) {
    if (column_count < 3)
        return 1;
    
    printf("<stop %s>\n", data[0]);
    printf("  Arrival time:  %s\n", data[2]);
    printf("  Trip id:       %s\n", data[1]);

    return 0;
}
```

## Build process and dependencies

### Dependencies

One of the development goals was to keep the dependencies as minimal as possible. So far, CGTFS has following dependencies:

  - [greatest](https://github.com/silentbicycle/greatest) for tests
  - [sqlite3](https://www.sqlite.org/index.html) for fast & efficient querying *built through [a special cmake-friendly repo](https://github.com/rakhack/sqlite3-cmake)*

### Build process

The library should compile on `gcc >= 4.8.4`, `clang >= 5.0.0` and latest Microsoft's C/C++ compiler.

```
$ cd /path/to/cgtfs/
$ git submodule update --init --recursive
$ mkdir build && cd build/
$ cmake -DCMAKE_BUILD_TYPE=Release ..    # produces an optimized & stripped binary without debug symbols, use Debug for development
$ cmake --build .

$ ./tests    # on Linux; tests executable location on Windows may vary, e.g. Release/tests.exe
```

## Documentation

The library is heavily documented via code comments. At releases and important waypoints, the documentation is compiled and commited to the repo. It is [available online](https://rakhack.github.io/cgtfs/doxygen/html/index.html).

However, in order to get the most actual documentation, you are encouraged to compile it yourself.

```
$ doxygen
```

*Note: by default, doxygen is configured to output LaTeX documentation as well. Turn off LaTeX if it is not installed on your system. (./Doxyfile:1648)*

*Note 2: this file is not guaranteed to contain up-to-date information. It is advised that you download the latest release and compile doxygen documentation from its source.*

### API overview

This library tries to provide a semantic and readable interface. Before release 1.0.0, the library's API is a subject to change without backwards-compatibility concerns.

A brief API overview can be found in the 'Overview' section of documentation compiled by doxygen.

## Useful links

  - [Official GTFS static reference](https://developers.google.com/transit/gtfs/reference/)
  - [Other GTFS handling libraries](https://github.com/CUTR-at-USF/awesome-transit#gtfs-libraries)

## License and attribution

The library is developed and distributed under the [MIT License](https://choosealicense.com/licenses/mit/), a copy of which can be found in the root of the project. Documentation and materials other than the library's source code are distributed under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/).

Files under the `tests/data/google_sample` directory constitute [an example Google Transit Feed](https://developers.google.com/transit/gtfs/examples/gtfs-feed) created and [shared by Google](https://developers.google.com/readme/policies/) and are used according to terms described in the [Creative Commons 3.0 Attribution License](https://creativecommons.org/licenses/by/3.0/). *Additionaly, parts of the in-code documentation may contain pieces of the [GTFS reference](https://developers.google.com/transit/gtfs/reference/).*

Files under the `tests/data/pocono_pony` contain the open data publicly provided by [Monroe County Transportation Authority](https://www.gomcta.com/index.php) under the [Monroe County Transportation Authority Transit Data Developer Terms of Use](https://www.gomcta.com/developerapi.php).

Other files under the `tests/data` directory may contain elements of the [open data](http://www.lsl.fi/lisatietoa/avoin-data/) publicly provided by [Lahden Seudun Liikenne](http://www.lsl.fi/) under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/deed.fi).

Usage of the public data provided by Google, Monroe County Transportation Authority and Lahden Seudun Liikenne does not suggest endorsement by any of the aforementioned licensors.