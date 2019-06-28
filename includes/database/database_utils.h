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
 * @param[in]    db            Feed database instance to connect to.
 * @param[in]    table_name    Name of the table to process.
 * 
 * @returns      -1 on error, number of records on success.
 */
int count_rows(feed_db_t *db, const char *table_name);


/**
 * Starts a sqlite3 transaction.
 * 
 * @param[in,out]    db    Feed database instance to operate on.
 * 
 * @returns          Success or failure of the operation.
 */
feed_db_status_t begin_transaction(feed_db_t *db);

/**
 * Ends a sqlite3 transaction.
 * 
 * @param[in,out]    db    Feed database instance to operate on.
 * 
 * @returns          Success or failure of the operation.
 */
feed_db_status_t end_transaction(feed_db_t *db);

#endif