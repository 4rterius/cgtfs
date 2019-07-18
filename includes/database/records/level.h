/**
 * @file
 * @brief    Level database record handling functionality.
 */

#ifndef CGTFS_DATABASE_LEVEL_H
#define CGTFS_DATABASE_LEVEL_H

#include <stdio.h>

#include "../../records/level.h"
#include "database/database.h"

/**
 * Stores a level_t record in the given database.
 *
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 *
 * @ingroup      Database__EntityStoring
 */
feed_db_status_t store_level_db(level_t *record, feed_db_t *db);

#endif