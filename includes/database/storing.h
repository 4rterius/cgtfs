/**
 * @file
 * @brief    Batch database content storing functionality.
 * 
 * Defines functions which read feed files
 * in their entirety and populate the database tables.
 */

#ifndef CGTFS_DATABASE_STORING_H
#define CGTFS_DATABASE_STORING_H

#include <stdio.h>

#include "database/database.h"
#include "database/database_utils.h"
#include "database/database_records.h"

#include "file_utils.h"
#include "mem_utils.h"


/**
 * Stores a file of agency_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_agencies_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of calendar_date_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_calendar_dates_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of calendar_record_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_calendar_records_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of fare_attributes_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_fare_attributes_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of fare_rule_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_fare_rules_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of feed_info_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_feed_info_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of frequency_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_frequencies_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of route_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_routes_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of shape_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_shapes_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of stop_time_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_stop_times_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of stop_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_stops_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of transfer_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_transfers_db(FILE *fp, feed_db_t *db);

/**
 * Stores a file of trip_t records 
 * into a given feed database instance.
 * 
 * @param[in]     fp    Opened file to source data from.
 * @param[out]    db    Initialized feed database instance to populate.
 * 
 * @returns       Number of stored records.
 */
int store_all_trips_db(FILE *fp, feed_db_t *db);

#endif