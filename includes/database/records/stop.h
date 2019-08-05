/**
 * @file
 * @brief    Stop database record handling functionality.
 */

#ifndef CGTFS_DATABASE_STOP_H
#define CGTFS_DATABASE_STOP_H

#include <stdio.h>

#include "../../records/stop.h"
#include "database/database.h"

/**
 * Stores a stop_t record in the given database.
 *
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 *
 * @ingroup      Database__EntityStoring
 */
feed_db_status_t store_stop_db(stop_t *record, feed_db_t *db);

#endif