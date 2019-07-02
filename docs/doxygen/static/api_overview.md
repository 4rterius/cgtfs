# API overview {#api_overview}

*Please note: up to release `1.0.0`, the library's API is a subject to a change without backwards-compatibility concerns.*

This library tries to provide a semantic, consistent and readable interface. The following diagrams show the ways GTFS data can be parsed or transferred between different storage types using this library.

  - `DIRECTORY` stands for an unpacked feed (a set of files located in a single directory, as per the official specification).
    - `FILE` - a single `*.txt` file.
  - `DATABASE` - a single SQLite database file, created using the supplied SQL schema (preferably, the creation of the database is left to the library, see setup_feed_db()).
  - `FEED OBJ` - a feed_t instance.
  - `ENTITIES` - an array of entities, e.g. `agency_t *`.
    - `ENTITY` - a single entity instance, e.g. `agency_t`.
  - _**Bold arrows** indicate that a function exists in the API, which makes it possible to transfer the entire contents of a feed between two types of storage with a single function call (not counting the setup and teardown functions)._

<div style="text-align: center;">
<div style="display: inline-block; width: 100%; max-width: 500px; padding-right: 5%;">
@image html df_straight.svg "Ways to parse/tranport data with CGTFS (simple diagram)" width=100%
</div>
<div style="display: inline-block; width: 100%; max-width: 500px;">
@image html df_scheme.svg "Ways to parse/tranport data with CGTFS (scheme)" width=100%
</div>
</div>

@image latex df_straight.eps "Ways to parse/tranport data with CGTFS (simple diagram)" width=12cm

@image latex df_scheme.eps "Ways to parse/tranport data with CGTFS (scheme)" width=12cm

