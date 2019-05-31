#ifndef CGTFS_DATABASE_H
#define CGTFS_DATABASE_H

#include <stdlib.h>
#include <string.h>
#include "sqlite3/src/sqlite3.h"

#include "feed.h"
#include "database/database_types.h"
#include "database/database_utils.h"
#include "database/storing.h"
#include "database/fetching.h"


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
 * @param db        Feed database to work on.
 * @param overwrite 0 to make error if tables already exist, else for otherwise.
 * @returns Result of the db operation.
 */
feed_db_status_t setup_feed_db(feed_db_t *db, int overwrite);

/**
 * Reads a CGTFS from the given directory to the given database.
 * @param dir  The GTFS directory to read.
 * @param db   The database to store into.
 * @returns Result of the db operation.
 */
feed_db_status_t store_feed_db(const char *dir, feed_db_t *db);

/**
 * Reads a GTFS database to an in-memory feed instance.
 * @param db    The database to read from.
 * @param feed  The feed_t instance to read into.
 * @returns Result of the db operation.
 */
feed_db_status_t fetch_feed_db(feed_db_t *db, feed_t *feed);

/**
 * Frees the memory taken by a feed database struct and closes the connection.
 * @param db Feed database struct to clear.
 * @returns Result of the db operation.
 */
feed_db_status_t free_feed_db(feed_db_t *db);

#endif