/**
 * @file
 * @brief    Feed info database record handling functionality.
 */

#ifndef CGTFS_DATABASE_FEED_INFO_H
#define CGTFS_DATABASE_FEED_INFO_H

#include <stdio.h>

#include "../../records/feed_info.h"
#include "database/database.h"

/**
 * Stores a feed_info_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 */
feed_db_status_t store_feed_info_db(feed_info_t *record, feed_db_t *db);

#endif