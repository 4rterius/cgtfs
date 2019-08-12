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
#include "str_utils.h"
#include "database/database_types.h"
#include "database/database_utils.h"
#include "database/storing.h"
#include "database/fetching.h"


/**
 * Initializes a given feed database.
 *
 * This function sets up default values for connection struct
 * and opens the connection.
 *
 * Calling free_feed_db() is recommended
 * as soon as the connection is no longer needed.
 *
 * Opening the connection again is preferred to
 * keeping stuff open and, thus, locked.
 *
 * @param[in,out]    db          Unitialized feed database instance to operate on.
 * @param[in]        db_path     /path/to/database.file
 * @param[in]        writable    0 to make connection read-only, else for otherwise
 *
 * @returns          FEED_DB_SUCCESS or FEED_DB_ERROR (self-explanatory).
 *
 * @ingroup          Database__FeedEntity
 */
feed_db_status_t init_feed_db(feed_db_t *db, const char *db_path, int writable);

/**
 * Creates the layout in the given database.
 *
 * This function is, basically, a wrapper around a giant SQL query.
 * Ideally, it is called every once in a set time interval (a day, probably),
 * as there is no need to do it every time some information is needed.
 *
 * Every time a database is updated,
 * the database file must be deleted (left to developer).
 *
 * @param[in,out]    db           Initialized feed database to operate on.
 *
 * @returns          FEED_DB_SUCCESS or FEED_DB_ERROR (self-explanatory).
 *
 * @ingroup          Database__FeedEntity
 */
feed_db_status_t setup_feed_db(feed_db_t *db);

/**
 * Imports a .csv file into the given database.
 *
 * Direct CSV -> SQLite parsing.
 *
 * @param[in]     dir      /path/to/unpacked/gtfs/
 * @param[in]     table    Name of the table to import the data into (will be created if doesn't exist).
 * @param[out]    db       Initialized feed database instance to store into.
 *
 * @returns       FEED_DB_SUCCESS if the import went well, FEED_DB_ERROR otherwise.
 *
 * @ingroup       Database__FeedEntity
 */
feed_db_status_t import_csv_file_db(const char *path, const char *table, feed_db_t *db);

/**
 * Imports an unpacked GTFS feed
 * from the given directory to the given database
 * non-semantically.
 *
 * Direct CSV -> SQLite parsing.
 *
 * @param[in]     dir    /path/to/unpacked/gtfs/
 * @param[out]    db     Initialized feed database instance to store into.
 *
 * @returns       FEED_DB_SUCCESS if the import went well, FEED_DB_ERROR otherwise.
 *
 * @ingroup       Database__FeedEntity
 */
feed_db_status_t import_feed_db(const char *dir, feed_db_t *db);

/**
 * Reads an unpacked GTFS feed
 * from the given directory to the given database.
 *
 * This function reads every feed file and stores its records
 * directly into the database, without an intermediate array.
 *
 * Unless CGTFS_STORING_BATCH_TRANSACTIONS_OFF is defined, each
 * file's contents are stored in a single transaction.
 *
 * Pass NULL to `feed_counter` when there's no need
 * to get the count of stored records.
 *
 * @param[in]     dir             /path/to/unpacked/gtfs/
 * @param[out]    db              Initialized feed database instance to store into.
 * @param[out]    feed_counter    Initialized feed instance to write stored records counts to.
 *
 * @returns       Both FEED_DB_SUCCESS and FEED_DB_PARTIAL are successful results;
 *                FEED_DB_SUCCESS is returned only if the feed has records in
 *                EVERY possible feed file.
 *                FEED_DB_PARTIAL is returned if at least one entity file
 *                had at least one record; if not, FEED_DB_ERROR is returned.
 *
 * @ingroup       Database__FeedEntity
 */
feed_db_status_t store_feed_db(const char *dir, feed_db_t *db, feed_t *feed_counter);

/**
 * Reads a GTFS database to a feed instance.
 *
 * A convenience wrapper around calls to table fetching functions.
 * See documentation e.g. for fetch_all_agencies_db().
 *
 * @param[in]     db      Initialized feed database instance to read from.
 * @param[out]    feed    Initialized feed instance to read into.
 *
 * @ingroup          Database__FeedEntity
 */
void fetch_feed_db(feed_db_t *db, feed_t *feed);

/**
 * Frees the memory taken by a feed database instance
 * and closes the connection.
 *
 * It is most important that this function is called immediately
 * after the database connection has served its purpose. Better to
 * open a new one instead of keeping the single connection open
 * for the entire duration of the program run.
 *
 * @param[in,out]    db    Initialized feed database instance to clear.
 *
 * @returns          FEED_DB_SUCCESS or FEED_DB_ERROR (self-explanatory).
 *
 * @ingroup          Database__FeedEntity
 */
feed_db_status_t free_feed_db(feed_db_t *db);

#endif