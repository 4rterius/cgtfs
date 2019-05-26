#ifndef CGTFS_DATABASE_CALENDAR_DATES_H
#define CGTFS_DATABASE_CALENDAR_DATES_H

#include <stdio.h>

#include "../../records/calendar_dates.h"
#include "database/database.h"

feed_db_status_t store_calendar_dates_db(calendar_date_t *record, feed_db_t *db);

#endif