#ifndef CGTFS_DATABASE_FETCHING_H
#define CGTFS_DATABASE_FETCHING_H

#include <stdio.h>

#include "database/database.h"
#include "database/database_utils.h"
#include "database/records/agency.h"

#include "file_utils.h"
#include "mem_utils.h"


int fetch_all_agencies_db(feed_db_t *db, agency_t **records);

#endif