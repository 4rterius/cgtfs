# CGTFS - a C library to read static GTFS feeds

![Release version plate](https://img.shields.io/github/release/rakhack/cgtfs.svg)
[![Build Status](https://travis-ci.com/rakhack/cgtfs.svg?branch=master)](https://travis-ci.com/rakhack/cgtfs)
[![Build status](https://ci.appveyor.com/api/projects/status/etnrf1pg2g0a20jn/branch/master?svg=true)](https://ci.appveyor.com/project/rakhack/cgtfs/branch/master)
![License: MIT plate](https://img.shields.io/github/license/rakhack/cgtfs.svg)

A thin and fast low-level library which reads GTFS static feeds. This library provides a readable and intuitive C interface for parsing data provided in the Google's [General Transit Feed Specification](https://developers.google.com/transit/gtfs/) format.

Docs: [available online](https://rakhack.github.io/cgtfs/doxygen/html/index.html).

## What this library can do

<div>
  <img width="400px" alt="Ways to parse/tranport data with CGTFS (scheme)" src="/docs/doxygen/static/df_straight.svg?raw=true&sanitize=true" />
</div>

## Table of contents

- [CGTFS - a C library to read static GTFS feeds](#CGTFS---a-C-library-to-read-static-GTFS-feeds)
  - [What this library can do](#What-this-library-can-do)
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

The most primitive example (not production-recommended):

```c
#include <stdio.h>
#include "feed.h"

// Example 0: read all feed data into memory
void some_function(void) {
    feed_t amazing_feed;
    init_feed(&amazing_feed);
    read_feed(&amazing_feed, "../tests/data/google_sample");

    if (amazing_feed.agency_count > 0)
        printf("The agency's name is: %s \n", amazing_feed.agencies[0].name);
    else
        perror("Failed to open agency.txt or the file has no records");
    
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

```
$ cd /path/to/cgtfs/
$ git submodule update --init --recursive
$ mkdir build && cd build/
$ cmake -DCMAKE_BUILD_TYPE=Release ..    # produces an optimized & stripped binary without debug symbols, use Debug for development
$ cmake --build .

$ ./tests    # on Linux; tests executable location on Windows may vary, e.g. Release/tests.exe
```

### Documentation

The library is heavily documented via code comments. At releases and important waypoints, the documentation is compiled and commited to the repo. It is [available online](https://rakhack.github.io/cgtfs/doxygen/html/index.html).

However, in order to get the most actual documentation, you are encouraged to compile it yourself.

```
$ doxygen
```

*Note: by default, doxygen is configured to output LaTeX documentation as well. Turn off LaTeX if it is not installed on your system. (./Doxyfile:1648)*

*Note 2: this file is not guaranteed to contain up-to-date information. It is advised that you download the latest release and compile doxygen documentation from its source.*

## API overview

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