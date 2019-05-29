#ifndef CGTFS_DATABASE_STORING_H
#define CGTFS_DATABASE_STORING_H

#include <stdio.h>

#include "database/database.h"
#include "database/database_utils.h"
#include "database/database_records.h"

#include "file_utils.h"
#include "mem_utils.h"


int store_all_agencies_db(FILE *fp, feed_db_t *db);
int store_all_calendar_dates_db(FILE *fp, feed_db_t *db);
int store_all_calendar_records_db(FILE *fp, feed_db_t *db);
int store_all_fare_attributes_db(FILE *fp, feed_db_t *db);
int store_all_fare_rules_db(FILE *fp, feed_db_t *db);
int store_all_feed_info_db(FILE *fp, feed_db_t *db);
int store_all_frequencies_db(FILE *fp, feed_db_t *db);
int store_all_routes_db(FILE *fp, feed_db_t *db);
int store_all_shapes_db(FILE *fp, feed_db_t *db);
int store_all_stop_times_db(FILE *fp, feed_db_t *db);
int store_all_stops_db(FILE *fp, feed_db_t *db);
int store_all_transfers_db(FILE *fp, feed_db_t *db);
int store_all_trips_db(FILE *fp, feed_db_t *db);

#endif