/**
 * @file
 * @brief    Frequency database record handling functionality.
 */

#ifndef CGTFS_DATABASE_FREQUENCY_H
#define CGTFS_DATABASE_FREQUENCY_H

#include <stdio.h>

#include "../../records/frequency.h"
#include "database/database.h"

/**
 * Stores a frequency_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 * 
 * @ingroup      Database__RecordStoring
 */
feed_db_status_t store_frequency_db(frequency_t *record, feed_db_t *db);

#endif