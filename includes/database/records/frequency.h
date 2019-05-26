#ifndef CGTFS_DATABASE_FREQUENCY_H
#define CGTFS_DATABASE_FREQUENCY_H

#include <stdio.h>

#include "../../records/frequency.h"
#include "database/database.h"

feed_db_status_t store_frequency_db(frequency_t *record, feed_db_t *db);

#endif