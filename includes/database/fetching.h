#ifndef CGTFS_DATABASE_FETCHING_H
#define CGTFS_DATABASE_FETCHING_H

#include <stdio.h>

#include "database/database.h"
#include "database/database_utils.h"
#include "database/database_records.h"

#include "file_utils.h"
#include "mem_utils.h"


/**
 * Populates a given array of agency_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_agencies_db(feed_db_t *db, agency_t **records);

/**
 * Populates a given array of calendar_date_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_calendar_dates_db(feed_db_t *db, calendar_date_t **records);

/**
 * Populates a given array of calendar_record_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_calendar_records_db(feed_db_t *db, calendar_record_t **records);

/**
 * Populates a given array of fare_attributes_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_fare_attributes_db(feed_db_t *db, fare_attributes_t **records);

/**
 * Populates a given array of fare_rule_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_fare_rules_db(feed_db_t *db, fare_rule_t **records);

/**
 * Populates a given array of feed_info_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_feed_info_db(feed_db_t *db, feed_info_t **records);

/**
 * Populates a given array of frequency_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_frequencies_db(feed_db_t *db, frequency_t **records);

/**
 * Populates a given array of route_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_routes_db(feed_db_t *db, route_t **records);

/**
 * Populates a given array of shape_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_shapes_db(feed_db_t *db, shape_t **records);

/**
 * Populates a given array of stop_time_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_stop_times_db(feed_db_t *db, stop_time_t **records);

/**
 * Populates a given array of stop_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_stops_db(feed_db_t *db, stop_t **records);

/**
 * Populates a given array of transfer_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_transfers_db(feed_db_t *db, transfer_t **records);

/**
 * Populates a given array of trip_t records 
 * from a given feed database instance.
 * 
 * @param[in]     db         Initialized feed database instance to get data from.
 * @param[out]    records    Non-allocated array to populate.
 * 
 * @returns       Number of retrieved records.
 */
int fetch_all_trips_db(feed_db_t *db, trip_t **records);

#endif