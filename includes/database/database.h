/**
 * @file
 * @brief    Core feed database entity functionality.
 */

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
 * 
 * @param[in,out]    db          Unitialized feed database instance to operate on.
 * @param[in]        db_path     /path/to/database.file
 * @param[in]        writable    0 for make connection read-only, else for otherwise
 * 
 * @returns          Result of the operation.
 */
feed_db_status_t init_feed_db(feed_db_t *db, const char *db_path, int writable);

/**
 * Creates the layout in the given database.
 * 
 * @param[in,out]    db           Initialized feed database to operate on.
 * @param[in]        overwrite    0 to make error if tables already exist, else for otherwise.
 * 
 * @returns          Result of the operation.
 */
feed_db_status_t setup_feed_db(feed_db_t *db, int overwrite);

/**
 * Reads an unpacked GTFS feed 
 * from the given directory to the given database.
 * 
 * Pass NULL to `feed_counter` when there's no need 
 * to get the count of stored records.
 * 
 * @param[in]     dir             /path/to/unpacked/gtfs/
 * @param[out]    db              Initialized feed database instance to store into.
 * @param[out]    feed_counter    Initialized feed instance to write stored records counts to.
 * 
 * @returns       Result of the db operation.
 */
feed_db_status_t store_feed_db(const char *dir, feed_db_t *db, feed_t *feed_counter);

/**
 * Reads a GTFS database to a feed instance.
 * 
 * @param[in]     db      Initialized feed database instance to read from.
 * @param[out]    feed    Initialized feed instance to read into.
 */
void fetch_feed_db(feed_db_t *db, feed_t *feed);

/**
 * Frees the memory taken by a feed database instance 
 * and closes the connection.
 * 
 * @param[in,out]    db    Initialized feed database instance to clear.
 * 
 * @returns          Result of the db operation.
 */
feed_db_status_t free_feed_db(feed_db_t *db);

#endif