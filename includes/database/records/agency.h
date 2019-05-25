#ifndef CGTFS_DATABASE_AGENCY_H
#define CGTFS_DATABASE_AGENCY_H

#include <stdio.h>

#include "../../records/agency.h"
#include "database/database.h"

feed_db_status_t store_agency_db(agency_t *record, feed_db_t *db);

#endif