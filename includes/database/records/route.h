/**
 * @file
 * @brief    Route database record handling functionality.
 */

#ifndef CGTFS_DATABASE_ROUTE_H
#define CGTFS_DATABASE_ROUTE_H

#include <stdio.h>

#include "../../records/route.h"
#include "database/database.h"

/**
 * Stores a route_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 * 
 * @ingroup      Database__RecordStoring
 */
feed_db_status_t store_route_db(route_t *record, feed_db_t *db);

#endif