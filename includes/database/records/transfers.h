#ifndef CGTFS_DATABASE_TRANSFERS_H
#define CGTFS_DATABASE_TRANSFERS_H

#include <stdio.h>

#include "../../records/transfers.h"
#include "database/database.h"

feed_db_status_t store_transfer_db(transfer_t *record, feed_db_t *db);

#endif