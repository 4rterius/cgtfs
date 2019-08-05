/**
 * @file
 * @brief    Transfer database record handling functionality.
 */

#ifndef CGTFS_DATABASE_TRANSFERS_H
#define CGTFS_DATABASE_TRANSFERS_H

#include <stdio.h>

#include "../../records/transfers.h"
#include "database/database.h"

/**
 * Stores a transfer_t record in the given database.
 *
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 *
 * @ingroup      Database__EntityStoring
 */
feed_db_status_t store_transfer_db(transfer_t *record, feed_db_t *db);

#endif