/**
 * @file
 * @brief    Fare attribute database record handling functionality.
 */

#ifndef CGTFS_DATABASE_FARE_ATTRIBUTES_H
#define CGTFS_DATABASE_FARE_ATTRIBUTES_H

#include <stdio.h>

#include "../../records/fare_attributes.h"
#include "database/database.h"

/**
 * Stores a fare_attribute_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 * 
 * @ingroup      Database__EntityStoring
 */
feed_db_status_t store_fare_attributes_db(fare_attributes_t *record, feed_db_t *db);

#endif