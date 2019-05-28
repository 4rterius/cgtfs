#ifndef CGTFS_DATABASE_STOP_H
#define CGTFS_DATABASE_STOP_H

#include <stdio.h>

#include "../../records/stop.h"
#include "database/database.h"

feed_db_status_t store_stop_db(stop_t *record, feed_db_t *db);

#endif