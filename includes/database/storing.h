#ifndef CGTFS_DATABASE_STORING_H
#define CGTFS_DATABASE_STORING_H

#include <stdio.h>

#include "database/database.h"
#include "database/database_utils.h"
#include "database/records/agency.h"
#include "database/records/calendar_dates.h"

#include "file_utils.h"
#include "mem_utils.h"


int store_all_agencies_db(FILE *fp, feed_db_t *db);
int store_all_calendar_dates_db(FILE *fp, feed_db_t *db);

#endif