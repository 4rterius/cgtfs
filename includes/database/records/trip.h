/**
 * @file
 * @brief    Trip database record handling functionality.
 */

#ifndef CGTFS_DATABASE_TRIP_H
#define CGTFS_DATABASE_TRIP_H

#include <stdio.h>

#include "../../records/trip.h"
#include "database/database.h"

/**
 * Stores a trip_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 */
feed_db_status_t store_trip_db(trip_t *record, feed_db_t *db);

#endif