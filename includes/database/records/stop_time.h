#ifndef CGTFS_DATABASE_STOP_TIME_H
#define CGTFS_DATABASE_STOP_TIME_H

#include <stdio.h>

#include "../../records/stop_time.h"
#include "database/database.h"

feed_db_status_t store_stop_time_db(stop_time_t *record, feed_db_t *db);

#endif