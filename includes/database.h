#ifndef CGTFS_DATABASE_H
#define CGTFS_DATABASE_H

#include <stdlib.h>
#include <string.h>
#include "sqlite3/src/sqlite3.h"

#include "database_types.h"
#include "database_utils.h"


/**
 * Initializes a give feed database.
 * @param db       Pointer to the feed database to serve.
 * @param db_path  /path/to/database
 * @param writable 0 for make connection read-only, else for otherwise
 * @returns Result of the db operation.
 */
feed_db_status_t init_feed_db(feed_db_t *db, const char *db_path, int writable);

/**
 * Creates the layout in the given database.
 * @param Feed database to work on.
 * @returns Result of the db operation.
 */
feed_db_status_t setup_feed_db(feed_db_t *db);

/**
 * Reads a CGTFS from the given directory to the given database.
 * @param db   The database to write into.
 * @param dir  The GTFS directory to read.
 * @returns Result of the db operation.
 */
feed_db_status_t read_feed_db_dir(feed_db_t *db, const char *gtfs_dir);

/**
 * Frees the memory taken by a feed database struct and closes the connection.
 * @param db Feed database struct to clear.
 * @returns Result of the db operation.
 */
feed_db_status_t free_feed_db(feed_db_t *db);

#endif