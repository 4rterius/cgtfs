/**
 * @file
 * @brief    Feed database handling utilities.
 */

#ifndef CGTFS_DATABASE_UTILS_H
#define CGTFS_DATABASE_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sqlite3/src/sqlite3.h"

#include "database/database_types.h"
#include "database/database.h"

#define STATEMENT_BUF_LEN 1000


/**
 * Counts the number of records in the given db table.
 *
 * @param[in]    db            Initialized feed database instance to connect to.
 * @param[in]    table_name    Name of the table to process.
 *
 * @returns      -1 on error, number of records on success.
 *
 * @ingroup      Utils__Database
 */
int count_rows(feed_db_t *db, const char *table_name);


/**
 * Starts a sqlite3 transaction.
 *
 * Returns an error if CGTFS has already opened an unfinished transaction.
 * Sets db->in_transaction to 1.
 *
 * @param[in,out]    db    Initialized feed database instance to operate on.
 *
 * @returns          Success or failure of the operation.
 *
 * @ingroup          Utils__Database
 */
feed_db_status_t begin_transaction(feed_db_t *db);

/**
 * Ends a sqlite3 transaction.
 *
 * Returns an error if CGTFS has not opened an unfinished transaction.
 * Sets db->in_transaction to 0.
 *
 * @param[in,out]    db    Initialized feed database instance to operate on.
 *
 * @returns          Success or failure of the operation.
 *
 * @ingroup          Utils__Database
 */
feed_db_status_t end_transaction(feed_db_t *db);

#endif