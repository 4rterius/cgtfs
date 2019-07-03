# API overview {#api_overview}

*Please note: up to release `1.0.0`, the library's API is a subject to a change without backwards-compatibility concerns.*

This library tries to provide a semantic, consistent and readable interface. The following diagrams show the ways GTFS data can be parsed or transferred between different storage types using this library.

  - `DIRECTORY` stands for an unpacked feed (a set of files located in a single directory, as per the official specification).
    - `FILE` - a single `*.txt` file.
  - `DATABASE` - a single SQLite database file, created using the supplied SQL schema (preferably, the creation of the database is left to the library, see setup_feed_db()).
  - `FEED OBJ` - a feed_t instance.
  - `ENTITIES` - an array of entities, e.g. `agency_t *`.
    - `ENTITY` - a single entity instance, e.g. `agency_t`.
  - _**Bold arrows** indicate that such a function exists in the API which makes it possible to transfer the entire contents of a feed between two types of storage with a single function call (not counting the setup and teardown functions)._

<div style="text-align: center;">
<div style="display: inline-block; width: 100%; max-width: 500px; padding-right: 5%;">
@image html df_straight.svg "Ways to parse/tranport data with CGTFS (simple diagram)" width=100%
</div>
<div style="display: inline-block; width: 100%; max-width: 400px;">
@image html df_scheme.svg "Ways to parse/tranport data with CGTFS (scheme)" width=100%
</div>
</div>

@image latex df_straight.eps "Ways to parse/tranport data with CGTFS (simple diagram)" width=12cm

@image latex df_scheme.eps "Ways to parse/tranport data with CGTFS (scheme)" width=12cm



@section ApiOverview__Structure Structure

The library's API is divided into two so called layers, additional auxiliary functionality and loosely related helpers: 

  - **Core layer** provides basic definitions and functions for handling GTFS feeds and entities, and includes:
    - feed object definition (struct) to store data of an entire feed;
      - a function to initialize a feed object;
      - a function to parse a feed object from a given directory path;
      - a function to determine whether two feed objects are equal;
    - field enumerations to represent types and values of the fields which can only take values from a limited set defined by the specification, e.g. [`routes.txt/route type`](https://developers.google.com/transit/gtfs/reference/#routestxt);
      - functions to parse field enumeration values from a char array;
    - entity definitions (structs) to represent e.g. an agency, a stop, a shape, etc.;
      - functions to initialize entity instances;
      - functions to parse entity instances from a char array of field names and a char array of field values;
      - functions to determine whether two entity instances are equal;
    - batch entity parsing functions which parse an array of entities from a given `*.txt` file path;
  - **Database layer** provides definitions and functions for working with entities defined in the *core layer* with/through/in a SQLite database instance, and includes:
    - feed database definition (struct) of a connection to a sqlite database;
      - a function to initialize a database connection;
      - a function to free/close a database connection;
      - a function to setup a database at an opened connection for a GTFS feed;
    - storage transition functions:
      - a function to store the contents of a feed from a specified directory into a specified database connection;
      - a function to fetch the contents of a feed from a specified database connection into a specicfied feed object;
    - an enumeration of general database operation results (success / failure / so-so);
    - functions to store entities using a specified database connection;
    - the so-called table operations:
      - batch entity storing functions which parse an array of entities from a given `*.txt` file path into a database table (doing so directly, without keeping an intermediate array in the memory);
      - batch entity fetching functions which retrieve an array of entities of a single type from a specified database connection;
  - **Utilities** include:
    - functions for reading GTFS CSV files;
    - an assisting function for clearing a c-string array;
    - utilitary functions for working a with sqlite database;
  - **Helpers** include:
    - several preprocessor definitions used across the library;
    - a function for making a filepath from a directory and a file in it;
    - a function for converting degrees into radians;
    - a geolocation definition (struct) which holds a latitude value and a longitude value;
      - a function for calculating a distance (in meters) between the two geolocation points.