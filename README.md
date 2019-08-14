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

- [CGTFS - a C library to read static GTFS feeds](#cgtfs---a-c-library-to-read-static-gtfs-feeds)
  - [Table of contents](#table-of-contents)
  - [Examples](#examples)
  - [Build process and dependencies](#build-process-and-dependencies)
    - [Dependencies](#dependencies)
    - [Build process](#build-process)
      - [Linux](#linux)
      - [Windows](#windows)
  - [Documentation](#documentation)
    - [Terms](#terms)
    - [API overview](#api-overview)
      - [Principles](#principles)
      - [String storage](#string-storage)
      - [Structure](#structure)
  - [A small performance showcase](#a-small-performance-showcase)
  - [Useful links](#useful-links)
  - [License and attribution](#license-and-attribution)

## Examples

Some example code is located in the `examples/` folder of the library's source code. Digging into the `tests/` folder might as well be useful, but you should consider that the testing code does not properly handle memory deallocation and error recovery.

The most primitive example, the only one provided here for brevity:

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

## Build process and dependencies

### Dependencies

One of the development goals was to keep the dependencies as minimal as possible. So far, CGTFS has following dependencies:

  - [greatest](https://github.com/silentbicycle/greatest) for tests
  - [sqlite3](https://www.sqlite.org/index.html) for fast & efficient querying *built through [a special cmake-friendly repo](https://github.com/rakhack/sqlite3-cmake)*

### Build process

The library should compile on `gcc >= 4.8.4`, `clang >= 5.0.0` and latest Microsoft's C/C++ compiler.

Configuration: `Release` or `Debug`.

#### Linux
```
$ cd /path/to/cgtfs/
$ git submodule update --init --recursive
$ mkdir build && cd build/
$ cmake -DCMAKE_BUILD_TYPE=%Configuration% ..
$ cmake --build .

$ ./tests
```

#### Windows

```
cd \path\to\cgtfs\
git submodule update --init --recursive
mkdir build && cd build
cmake ..
cmake --build . --config %Configuration%

%Configuration%\tests.exe
```


## Documentation

The library is heavily documented via code comments. At releases and important waypoints, the documentation is compiled and commited to the repo. It is [available online](https://rakhack.github.io/cgtfs/doxygen/html/index.html). However, in order to get the most actual documentation, you are encouraged to compile it yourself.

```
$ doxygen
```

*Please note: this file is not guaranteed to contain up-to-date information. It is advised that you download the latest release and compile doxygen documentation from its source.*

### Terms

The terms used throughout the library code and documentation differ from those defined by the [GTFS reference](https://developers.google.com/transit/gtfs/reference/#term-definitions). The following table illustrates the relation between differing CGTFS terms and reference terms, and their definitions, as well as terms used in the library and abscent from the reference.

| CGTFS term | Reference term | Meaning and notes |
| ---------- | -------------- | ----------------- |
| Feed (entity/instance/object) | *not defined* | A data structure holding the entirety of a feed's data. *In the code and documentation, may be referred to as a feed entity, feed instance or feed object.* |
| Directory | Dataset | A set of files which constitutes a GTFS feed. In some contexts, in the code documentation, terms *feed* and *directory* are interchangable. *Note: GTFS datasets are distributed in form of `*.zip` feed archives. This library, however, only works with unpacked feeds.* |
| Entity (instance) | Record | A complete data structure containing information about a concrete GTFS entity (e.g. information about one route). The library uses the term *entity* to avoid ambiguity with database operations. _Note: however, *entity* is a more abstract term, thus a struct holding one entity's data is, in essense, an entity instance. This documentation may refer to structs simply as **entities** for shortness_. |
| File | *not defined* | A `*.txt` file, a part of the feed, holding information about all the feed's *entities* of a single type. |
| Database | n/a | A single *SQLite* database file, created using the supplied SQL schema (preferably, the creation of the database is left to the library, see the database section). |

### API overview

This library tries to provide a semantic and readable interface. Before release 1.0.0, the library's API is a subject to change without backwards-compatibility concerns.

#### Principles

There are several core principles which could help in understanding the vast interface of the library. Some of them have been enforced from the beginning, others may be gradually integrated into the API.

  - All structs and enumerations have names ending with `_t`.
  - All enumerations have members with names reflecting the enumeration's name.
    - Entity field enumerations start with the first letters of the enumeration's name, e.g. `payment_method_t` has elements `PM_ON_BOARD`, `PM_BEFOREHAND` and `PM_NOT_SET`.
      - There are exceptions at naming conflicts, e.g. `pathway_mode_t`, which would have to start its members' names with `PM` but uses `PTMD` instead.
      - Additionally, all entity field enumerations have `..._NOT_SET` members.
  - All structs have `init_...()` functions for initializing them. These functions MUST be called before the first use of the structure.
    - Feed entity and record entity structs also have `read_...()` and `equal_...()` functions.
    - Structs which need deallocation after use have `free_...()` functions.
  - All functions which have to do something with database operations have `_db` postfix.

#### String storage

String values in CGTFS are stored in memory using statically allocated c-strings. Hence, parsing an unsually long string value may lead to a fatal crash. Default string field lengths are rather sensible but might by too big (bloating the RAM used significantly) or too small (causing crash).

To mitigate that, all string field length definitions are located in the `xstrlengths.h` header. Actual field length definitions are heavily commented in the lower part of the file. By default, they are using `CGTFS_SL_BASE_` definitions found in the upper part of the file. There are three possible usage cases:

  1. All left as it is in hopes for lucky circumstances.
  2. Definition `CGTFS_SL_MODE_PREPARATION` is uncommented, reserving an insensible amount of memory for all fields.
  3. Maximum length of each field type is deduced from the supposed data sources (useful if you're working with the data from a specific agency). This is left to the developer.

#### Structure

The library's API is divided into two so called layers, additional auxiliary functionality and loosely related helpers:

  - **Core layer** provides basic definitions and functions for handling GTFS feeds and entities, and includes:
    - **feed object definition** to store data of an entire feed and functions for working with it:
      - a function to initialize a feed object;
      - a function to parse a feed object from a given directory path;
      - a function to determine whether two feed objects are equal;
    - field enumerations to represent types and values of the fields which can only take values from a limited set defined by the specification, e.g. [`routes.txt/route type`](https://developers.google.com/transit/gtfs/reference/#routestxt);
      - functions to parse field enumeration values from a char array;
    - **entity definitions** to represent e.g. an agency, a stop, a shape, etc. and **functions** for handling them;
      - functions to initialize entity instances;
      - functions to parse entity instances from a char array of field names and a char array of field values;
      - functions to determine whether two entity instances are equal;
    - **batch entity parsing functions** which parse an array of entities from a given `*.txt` file path;
  - **Database layer** provides definitions and functions for working with entities defined in the *core layer* with/through/in a SQLite database instance, and includes:
    - **definition of a connection to a sqlite database** and **functions** for working with it:
      - a function to initialize a database connection;
      - a function to free/close a database connection;
      - a function to setup a database at an opened connection for a GTFS feed;
    - storage transition functions:
      - a **function** to store the contents of a feed from a specified directory into a specified database connection (non-semantically, storing all values as TEXT) *(see note below)*;
      - a **function** to store the contents of a feed from a specified directory into a specified database connection (semantically, parsing every record) *(see note below)*;
      - a **function** to fetch the contents of a feed from a specified database connection into a specicfied feed object;
    - an **enumeration** of general database operation results (success / failure / so-so);
    - **functions** to store entities using a specified database connection;
    - the so-called table operations:
      - **batch entity storing functions** which parse an array of entities from a given `*.txt` file path into a database table (doing so directly, without keeping an intermediate array in the memory);
      - **batch entity fetching functions** which retrieve an array of entities of a single type from a specified database connection;
  - **Utilities** include:
    - **functions** for reading CSV files;
    - an assisting **function** for clearing a c-string array;
    - utilitary **functions** for working a with sqlite database;
  - **Helpers** include:
    - several preprocessor definitions used across the library;
    - a **function** for extracting filename without extension from a given path;
    - a **function** for making a filepath from a directory and a file in it;
    - a **function** for converting degrees into radians;
    - a **geolocation definition** which holds a latitude value and a longitude value;
      - a **function** for calculating a distance (in meters) between the two geolocation points.

_Note: CGTFS provides two ways of parsing a directory into a database, semantic and non-semantic. Semantic stores all values according to the specification, creating a reference-defined database layout and filling it with data of according types. Non-semantic directly translates GTFS *.txt files as CSVs into the database, creating a layout based on file headers and storing all data as text. See more in the related documentation page._

A more detailed documentation for each layer, definition and function can be found in the module documentation.

## A small performance showcase

```
# Pocono Pony (1.65 mb)

Benchmark results for / feed dir -> memory parsing:
 -> 1        iteration:    235690500 ns. / 1 iter. => 235.690500 ms.
 -> 10       iterations:   1522158000 ns. / 10 iter. => 152.215800 ms.
---------

Benchmark results for / feed dir -> db parsing (semantic):
 -> 1        iteration:    3559970000 ns. / 1 iter. => 3559.970000 ms.
 -> 10       iterations:   33531279900 ns. / 10 iter. => 3353.127990 ms.
---------

Benchmark results for / feed dir -> db parsing (non-semantic):
 -> 1        iteration:    468014300 ns. / 1 iter. => 468.014300 ms.
 -> 10       iterations:   5315382000 ns. / 10 iter. => 531.538200 ms.
---------


# LSL (20.6 mb)

Benchmark results for / feed dir -> memory parsing:
 -> 1        iteration:    2053141000 ns. / 1 iter. => 2053.141000 ms.
 -> 10       iterations:   19250407600 ns. / 10 iter. => 1925.040760 ms.
---------

Benchmark results for / feed dir -> db parsing (semantic):
 -> 1        iteration:    14864547700 ns. / 1 iter. => 14864.547700 ms.
 -> 10       iterations:   151779149800 ns. / 10 iter. => 15177.914980 ms.
---------

Benchmark results for / feed dir -> db parsing (non-semantic):
 -> 1        iteration:    3478527500 ns. / 1 iter. => 3478.527500 ms.
 -> 10       iterations:   34999966400 ns. / 10 iter. => 3499.996640 ms.
---------


# MTA NYC Transit Subway (63.4 mb)

Benchmark results for / feed dir -> memory parsing:
 -> 1        iteration:    5560275600 ns. / 1 iter. => 5560.275600 ms.
 -> 10       iterations:   53092411900 ns. / 10 iter. => 5309.241190 ms.
---------

Benchmark results for / feed dir -> db parsing (semantic):
 -> 1        iteration:    40642734000 ns. / 1 iter. => 40642.734000 ms.
 -> 10       iterations:   376395287900 ns. / 10 iter. => 37639.528790 ms.
---------

Benchmark results for / feed dir -> db parsing (non-semantic):
 -> 1        iteration:    9276035200 ns. / 1 iter. => 9276.035200 ms.
 -> 10       iterations:   91401069000 ns. / 10 iter. => 9140.106900 ms.
---------

```

## Useful links

  - [Official GTFS static reference](https://developers.google.com/transit/gtfs/reference/)
  - [Other GTFS handling libraries](https://github.com/CUTR-at-USF/awesome-transit#gtfs-libraries)

## License and attribution

The library is developed and distributed under the [MIT License](https://choosealicense.com/licenses/mit/), a copy of which can be found in the root of the project. Documentation and materials other than the library's source code are distributed under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/).

Files under the `tests/data/google_sample` directory constitute [an example Google Transit Feed](https://developers.google.com/transit/gtfs/examples/gtfs-feed) created and [shared by Google](https://developers.google.com/readme/policies/) and are used according to terms described in the [Creative Commons 3.0 Attribution License](https://creativecommons.org/licenses/by/3.0/). *Additionaly, parts of the in-code documentation may contain pieces of the [GTFS reference](https://developers.google.com/transit/gtfs/reference/).*

Files under the `tests/data/pocono_pony` contain the open data publicly provided by [Monroe County Transportation Authority](https://www.gomcta.com/index.php) under the [Monroe County Transportation Authority Transit Data Developer Terms of Use](https://www.gomcta.com/developerapi.php).

Other files under the `tests/data` directory may contain elements of the [open data](http://www.lsl.fi/lisatietoa/avoin-data/) publicly provided by [Lahden Seudun Liikenne](http://www.lsl.fi/) under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/deed.fi).

Usage of the public data provided by Google, Monroe County Transportation Authority and Lahden Seudun Liikenne does not suggest endorsement by any of the aforementioned licensors.