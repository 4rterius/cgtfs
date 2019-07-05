# CGTFS - a C library to read static GTFS feeds {#mainpage}

A thin and fast low-level library which reads GTFS static feeds. This library provides a readable and intuitive C interface for parsing data provided in the Google's [General Transit Feed Specification](https://developers.google.com/transit/gtfs/) format.

## Examples

Some example source code is located in the `examples/` folder of the library's source code. Digging into the `tests/` folder might as well be useful.

### Reading a feed into memory

*Note: usage shown in this example is not recommended for parsing a real feed, as it __will__ take __a lot of__ memory for any substantially big amounts of data.*

@include example_0.c

### An entity file reading

Read all bus stops and print out their information

@include example_1.c

### Database-backed querying

Store a gtfs folder as a database and query it for first 10 stop time records with arrival time within the next 10 minutes.

@include example_2.c

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
$ cmake .. && cmake --build .

$ ./tests    # on Linux; tests executable location on Windows may vary, e.g. Debug/tests.exe
```

## Documentation

The library is heavily documented via code comments. You are encouraged to compile them into HTML.

```
$ doxygen
```

*Note: by default, doxygen is configured to output LaTeX documentation as well. Turn off LaTeX if it is not installed on your system. (./Doxyfile:1648)*

*Note 2: this file is not guaranteed to contain up-to-date information. It is advised that you download the latest release and compile doxygen documentation from its source.*

### API overview

An overview of the library's interface is provided in a separate section. See @ref api_overview.


## Useful links

  - [Official GTFS static reference](https://developers.google.com/transit/gtfs/reference/)
  - [Other GTFS handling libraries](https://github.com/CUTR-at-USF/awesome-transit#gtfs-libraries)

## License and attribution

The library is developed and distributed under the @ref mit_license "MIT License", a copy of which can be found in the root of the project's source code. Documentation and materials other than the library's source code are distributed under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/).

Files under the `tests/data/google_sample` directory constitute [an example Google Transit Feed](https://developers.google.com/transit/gtfs/examples/gtfs-feed) created and [shared by Google](https://developers.google.com/readme/policies/) and are used according to terms described in the [Creative Commons 3.0 Attribution License](https://creativecommons.org/licenses/by/3.0/). *Additionaly, parts of the in-code documentation may contain pieces of the [GTFS reference](https://developers.google.com/transit/gtfs/reference/).*

Files under the `tests/data/pocono_pony` contain the open data publicly provided by [Monroe County Transportation Authority](https://www.gomcta.com/index.php) under the [Monroe County Transportation Authority Transit Data Developer Terms of Use](https://www.gomcta.com/developerapi.php).

Other files under the `tests/data` directory may contain elements of the [open data](http://www.lsl.fi/lisatietoa/avoin-data/) publicly provided by [Lahden Seudun Liikenne](http://www.lsl.fi/) under the [Creative Commons Attribution 4.0 License](https://creativecommons.org/licenses/by/4.0/deed.fi).

Usage of the public data provided by Google, Monroe County Transportation Authority and Lahden Seudun Liikenne does not suggest endorsement by any of the aforementioned licensors.