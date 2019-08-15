# Data transition guide {#data_transition}

Although the entire library's public interface is exposed and considered to be of use for the developer using this library, the main expected use cases are parsing GTFS feeds and converting them into databases. This page provides commentary on how these actions could be done by the library's user.

## Basic data structures

There are two core data structures which are designed to be used for operating on GTFS datasets: feed_t and feed_db_t.

### Feed entity

Feed entity, presented by the feed_t structure, stores data about all possible GTFS records, as specified by the format reference. Thus, it has fields storing the numbers of entities (e.g. feed_t.stops_count) and fields storing the entities themselves (e.g. feed_t.stops). The _count fields have `int` types, and entity fields are arrays of values with entities' types (e.g. `agency_t *`). Feed entity must be:

  - initialized by calling init_feed() function before any use,
  - cleared by free_feed() immediately after it has been used.

As the library uses static buffers for storing record string fields, the feed entity takes *a lot* of memory. The exact relation between feed source size and memory taken by a feed_t instance varies, but be prepared for it to take at least an order of magnitude more memory. Thus, freeing the entity's memory is important and should be done ASAP. (The only exception to this is when the entity is used for storing counts only, as done by the third argument of store_feed_db().)

The following example is a common layout of the feed entity usage.

```c
#include "feed.h"

void some_func(void) {
    feed_t my_feed;
    init_feed(&my_feed);

    // Something done with my_feed.

    free_feed(&my_feed);
}
```

Also, see the following functions:

  - read_feed() - explained below,
  - equal_feeds().

### Feed database connection entity

Feed database connection entity (feed_db_t struct) stores data about a connection to a SQLite database. Namely, it stores path to the database file, a `sqlite3 *` value, an error message set by the library, a return code integer also set by the library, a boolean indicating whether the connection is open and a transaction state boolean, set by CGTFS's transaction functions. This allows the programmer to pass around the entire information about a SQLite connection in a simple and organized manner.

Encapsulating the connection data, it should be used with CGTFS, and is actually passed to all the library's database-related functions. This entity must be:

  - initialized with init_feed_db() before usage (among other things, opens the connection),
  - torn down with free_feed_db() after usage (frees the memory AND closes the connection).

The connection remains open until free_feed_db() is called on a struct, thus it is better to tear down the struct when you expect a large break in database operations during your program's execution.

As with most database operations, these two functions return a feed_db_status_t value.

The following example is a common layout of the feed database connection entity usage.

```c
#include "feed.h"
#include "database/database.h"

#define IS_WRITABLE = 1

int some_db_func(void) {
    feed_db_t my_db;
    feed_db_status_t res;

    res = init_feed_db(&my_db, "/path/to/database/file", IS_WRITABLE);

    if (res < FEED_DB_SUCCESS) {
        free_feed_db(&my_db);
        return 0;
    }

    // Something done with my_db connection.

    free_feed_db(&my_db);  // this can also return an error, but it will be easier to just quit the program.
    return 1;
}
```

Also, see the following functions:

  - setup_feed_db() - creates a database layout based on the GTFS reference,
  - import_feed_db(), store_feed_db(), fetch_feed_db() - explained below,
  - begin_transaction_db(), end_transaction_db() - begin and end SQLite transactions, writing the transaction state into the connection entity.

## Transition methods

### Reading to memory

The most primitive and the fastest parsing method stores a GTFS feed in the application memory. The amount of memory needed is much bigger than the size of the feed itself, due to static string field memory allocation.

Reading is done with the read_feed() function, taking a pointer to the database entity instance (see above) and a path to the directory with an unpacked GTFS feed. Always returns zero.

An example below shows the most primitive use case.

@include example_0.c

### Non-semantic import to database

Potentially the most used feature of the library. Reads all `*.txt` files in the given directory and parses their contents as if they were CSV files (which they are, actually). Is reasonably fast for a CSV parser. Realized in two functions.

  - import_csv_file_db() which parses a CSV file at the given path into the given table in the given database. Creates the tables.
  - import_feed_db() which is, basically, a convenience wrapper for the previous function, calling it for every file it finds in the given directory path. Table names are deduced from the filenames (stripping the `.txt` part).

```c
#include "feed.h"
#include "database/database.h"

#define IS_WRITABLE = 1

int some_db_func(void) {
    feed_db_t my_db;
    feed_db_status_t res;

    res = init_feed_db(&my_db, "/path/to/database/file", IS_WRITABLE);

    if (res < FEED_DB_SUCCESS) {
        puts(my_db.error_msg);
        free_feed_db(&my_db);
        return 0;
    }

    res = import_feed_db("/path/to/unpacked/gtfs/feed", &my_db);

    if (res < FEED_DB_SUCCESS) {
        puts(my_db.error_msg);
        free_feed_db(&my_db);
        return 0;
    }

    // Something done with the data in the database pointed to by my_db connection.

    free_feed_db(&my_db);
    return 1;
}
```

Also, see the following functions:

  - get_filename_no_ext() - strips all but the base filename from a given path,
  - make_filepath() - combines a given directory with a given filename.

### Semantic parsing to database

Another option for parsing a GTFS directory into a database. Unlike the prevous one, actually parses every @ref Core__EntityList "record" it finds. Hence, it is much (4+ times) slower than non-semantic parsing. As it parses data into reference-defined structs before storing them in the database, all non-standard files and fields are ignored; all files and fields which are not present leave empty tables or columns, respectively.

Done by store_feed_db() function, which takes the same arguments as import_feed_db(), and an optional `feed_t *feed_counter` argument, which, if not `NULL`, stores the numbers of parsed records once the function has returned a successful `feed_db_status_t` value. Unlike its non-semantic counterpart, the function requires a call to setup_feed_db() before usage to create the target database layout.

```c
#include "feed.h"
#include "database/database.h"

#define IS_WRITABLE = 1

int some_db_func(void) {
    feed_db_t my_db;
    feed_db_status_t res;

    res = init_feed_db(&my_db, "/path/to/database/file", IS_WRITABLE);

    if (res < FEED_DB_SUCCESS) {
        free_feed_db(&my_db);
        return 0;
    }

    res = setup_feed_db(&my_db);

    if (res < FEED_DB_SUCCESS) {
        puts(my_db.error_msg);
        free_feed_db(&my_db);
        return 0;
    }

    res = store_feed_db("/path/to/unpacked/gtfs/feed", &my_db, NULL);

    if (res < FEED_DB_SUCCESS) {
        puts(my_db.error_msg);
        free_feed_db(&my_db);
        return 0;
    }

    // Something done with the data in the database pointed to by my_db connection.

    free_feed_db(&my_db);
    return 1;
}
```

Also, if you have come as far as you did, see:

  - the entire database feed entity @ref Database__FeedEntity "documentation module".


### Fetching from database into memory

The function fetch_feed_db() provides a way to get *all* database records stored by CGTFS back to memory. Since the library does not provide GTFS file writing functionality, it can be seen as a counterpart for store_feed_db() function. Takes a database connection entity pointer and a feed entity pointer, and gets data from the former into the latter. Does not return anything, the success of the operation can be found by checking the resulting number of records in the feed entity pointed to by the value passed as the function's first argument.

```c
#include "feed.h"
#include "database/database.h"

#define IS_WRITABLE = 0

int some_db_func(void) {
    feed_t my_feed;
    feed_db_t my_db;
    feed_db_status_t res;

    res = init_feed_db(&my_db, "/path/to/database/file", IS_WRITABLE);

    if (res < FEED_DB_SUCCESS) {
        free_feed_db(&my_db);
        return 0;
    }

    init_feed(&my_feed);
    res = fetch_feed_db(&my_db, &my_feed);

    if (res < FEED_DB_SUCCESS) {
        puts(my_db.error_msg);
        free_feed_db(&my_db);
        return 0;
    }

    free_feed_db(&my_db);

    // Something done with the data in my_feed.

    free_feed(&my_feed);
    return 1;
}
```


## Performance

Generally, reading feeds to memory is the fastest operation of all discussed on this page, but it is also the most RAM-consuming. Non-semantic database import is the second fastest operation, taking 2-3 times longer than to-memory reading, but it is somewhat sensible in terms of RAM consumption. Semantic feed parsing into the database is the longest of the three, taking clearly inadequate time. Unless your target machine is *blazingly* fast, or you need a reference-compliant database with correct typing, you are advised against using this.

The following listing provides output from the CGTFS `./bench` executable, ran on several GTFS feeds on a Win10 i7-8550U NVMe machine through WSL 1.

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
