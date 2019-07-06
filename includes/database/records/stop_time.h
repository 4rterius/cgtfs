/**
 * @file
 * @brief    Stop time database record handling functionality.
 */

#ifndef CGTFS_DATABASE_STOP_TIME_H
#define CGTFS_DATABASE_STOP_TIME_H

#include <stdio.h>

#include "../../records/stop_time.h"
#include "database/database.h"

/**
 * Stores a stop_time_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 * 
 * @ingroup      Database__EntityStoring
 */
feed_db_status_t store_stop_time_db(stop_time_t *record, feed_db_t *db);

#endif