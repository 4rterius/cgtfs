#ifndef CGTFS_STORING_DB_H
#define CGTFS_STORING_DB_H

#include <stdio.h>

#include "records/agency.h"
#include "records/calendar_dates.h"
#include "records/calendar.h"
#include "records/fare_attributes.h"
#include "records/fare_rule.h"
#include "records/feed_info.h"
#include "records/frequency.h"
#include "records/route.h"
#include "records/shape.h"
#include "records/stop_time.h"
#include "records/stop.h"
#include "records/transfers.h"
#include "records/trip.h"

#include "database/database.h"
#include "database/database_utils.h"

feed_db_status_t store_agency_db(agency_t *record, feed_db_t *db);

#endif