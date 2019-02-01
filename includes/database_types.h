#ifndef CGTFS_DATABASE_TYPES_H
#define CGTFS_DATABASE_TYPES_H

#include "sqlite3/src/sqlite3.h"


/**
 * Base struct of all db processes to encapsulate the DB realization.
 */
typedef struct feed_db_t {
    char *path;
    sqlite3* conn;
    char *error_msg;
    int rc;
    int open;
} feed_db_t;

/**
 * Possible outcomes of feed db operations.
 */
typedef enum feed_db_status_t {
    FEED_DB_ERROR,
    FEED_DB_SUCCESS
} feed_db_status_t;

#endif