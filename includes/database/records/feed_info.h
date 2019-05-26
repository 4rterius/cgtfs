#ifndef CGTFS_DATABASE_FEED_INFO_H
#define CGTFS_DATABASE_FEED_INFO_H

#include <stdio.h>

#include "../../records/feed_info.h"
#include "database/database.h"

feed_db_status_t store_feed_info_db(feed_info_t *record, feed_db_t *db);

#endif