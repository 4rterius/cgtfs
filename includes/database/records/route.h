#ifndef CGTFS_DATABASE_ROUTE_H
#define CGTFS_DATABASE_ROUTE_H

#include <stdio.h>

#include "../../records/route.h"
#include "database/database.h"

feed_db_status_t store_route_db(route_t *record, feed_db_t *db);

#endif