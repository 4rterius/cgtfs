#ifndef CGTFS_DATABASE_H
#define CGTFS_DATABASE_H

#include <string.h>
#include "sqlite3/sqlite3.h"

/**
 * Base struct of all db processes to encapsulate the DB realization.
 */
typedef struct feed_db_t {
    char *path;
    sqlite3* conn;
    char *error_msg;
    int rc;
} feed_db_t;

/**
 * Possible outcomes of feed db operations.
 */
typedef enum feed_db_status_t {
    FEED_DB_ERROR,
    FEED_DB_SUCCESS,
    FEED_DB_EXISTS
} feed_db_status_t;

/**
 * Initializes a give feed database.
 * @param db       Pointer to the feed database to serve.
 * @param db_path  /path/to/database
 * @returns Result of the db operation.
 */
feed_db_status_t init_feed_db(feed_db_t *db, const char *db_path);

/**
 * Empties the given database.
 * @param Feed database to clear.
 * @returns Result of the db operation.
 */
feed_db_status_t clear_feed_db(feed_db_t *db);

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