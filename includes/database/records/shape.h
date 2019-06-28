/**
 * @file
 * @brief    Shape database record handling functionality.
 */

#ifndef CGTFS_DATABASE_SHAPE_H
#define CGTFS_DATABASE_SHAPE_H

#include <stdio.h>

#include "../../records/shape.h"
#include "database/database.h"

/**
 * Stores a shape_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 */
feed_db_status_t store_shape_db(shape_t *record, feed_db_t *db);

#endif