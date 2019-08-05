/**
 * @file
 * @brief    Fare rule database record handling functionality.
 */

#ifndef CGTFS_DATABASE_FARE_RULE_H
#define CGTFS_DATABASE_FARE_RULE_H

#include <stdio.h>

#include "../../records/fare_rule.h"
#include "database/database.h"

/**
 * Stores a fare_rule_t record in the given database.
 *
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 *
 * @ingroup      Database__EntityStoring
 */
feed_db_status_t store_fare_rule_db(fare_rule_t *record, feed_db_t *db);

#endif