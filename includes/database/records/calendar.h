#ifndef CGTFS_DATABASE_CALENDAR_H
#define CGTFS_DATABASE_CALENDAR_H

#include <stdio.h>

#include "../../records/calendar.h"
#include "database/database.h"

feed_db_status_t store_calendar_record_db(calendar_record_t *record, feed_db_t *db);

#endif