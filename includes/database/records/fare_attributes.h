#ifndef CGTFS_DATABASE_FARE_ATTRIBUTES_H
#define CGTFS_DATABASE_FARE_ATTRIBUTES_H

#include <stdio.h>

#include "../../records/fare_attributes.h"
#include "database/database.h"

feed_db_status_t store_fare_attributes_db(fare_attributes_t *record, feed_db_t *db);

#endif