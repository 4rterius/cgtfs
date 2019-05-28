#ifndef CGTFS_DATABASE_SHAPE_H
#define CGTFS_DATABASE_SHAPE_H

#include <stdio.h>

#include "../../records/shape.h"
#include "database/database.h"

feed_db_status_t store_shape_db(shape_t *record, feed_db_t *db);

#endif