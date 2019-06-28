/**
 * @file
 * @brief    Core types for feed database functionality.
 */

#ifndef CGTFS_DATABASE_TYPES_H
#define CGTFS_DATABASE_TYPES_H

#include "sqlite3/src/sqlite3.h"


/**
 * @ingroup     Database
 * @defgroup    Database__Types    Types
 * @brief       Core types used in feed database manipulation.
 * 
 * Required header: `database_types.h`
 */


/**
 * Base struct of all db processes to encapsulate the DB realization.
 * 
 * @ingroup    Database__Types
 */
typedef struct feed_db_t {
    char *path;         ///< /path/to/database.file
    sqlite3* conn;      ///< Underlying sqlite3 connection.
    char *error_msg;    ///< Field for storing sqlite error messages. Populate with strdup()
    int rc;             ///< Field for storing sqlite return codes.
    int open;           ///< Whether this connection has been opened or not (0 || 1)
} feed_db_t;

/**
 * Possible outcomes of feed db operations.
 * 
 * @ingroup    Database__Types
 */
typedef enum feed_db_status_t {
    FEED_DB_ERROR = 0,      ///< Miserably failed, check error message or return code.
    FEED_DB_SUCCESS = 1,    ///< Successfully done whatever.
    FEED_DB_PARTIAL = 2     ///< Kinda succeeded, but not fully. (Might indicate some files missing from a feed.)
} feed_db_status_t;

#endif