/**
 * @file
 * @brief    File reading functionality.
 * 
 * Defines functions to parse entire feed files into record arrays.
 */

#ifndef CGTFS_READING_H
#define CGTFS_READING_H

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

/**
 * Reads all records from the agencies.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of agency_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_agencies(FILE *fp, agency_t **records);

/**
 * Reads all records from the calendar_dates.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of calendar_date_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_calendar_dates(FILE *fp, calendar_date_t **records);

/**
 * Reads all records from the calendar.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of calendar_record_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_calendar_records(FILE *fp, calendar_record_t **records);

/**
 * Reads all records from the fare_attributes.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of fare_attributes_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_fare_attributes(FILE *fp, fare_attributes_t **records);

/**
 * Reads all records from the fare_rules.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of fare_rule_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_fare_rules(FILE *fp, fare_rule_t **records);

/**
 * Reads all records from the feed_info.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of feed_info_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_feed_info(FILE *fp, feed_info_t **records);

/**
 * Reads all records from the frequencies.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of frequency_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_frequencies(FILE *fp, frequency_t **records);

/**
 * Reads all records from the routes.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of route_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_routes(FILE *fp, route_t **records);

/**
 * Reads all records from the shapes.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of shape_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_shapes(FILE *fp, shape_t **records);

/**
 * Reads all records from the stop_times.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of stop_time_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_stop_times(FILE *fp, stop_time_t **records);

/**
 * Reads all records from the stops.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of stop_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_stops(FILE *fp, stop_t **records);

/**
 * Reads all records from the transfers.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of transfer_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_transfers(FILE *fp, transfer_t **records);

/**
 * Reads all records from the trips.txt file.
 * 
 * @param[in]     fp         Opened file connection to read from.
 * @param[out]    records    A non-allocated array of of trip_t records.
 * 
 * @returns       -1 on failure/error, number of records on success.
 * 
 * @ingroup       Core__EntityFileReading
 */
int read_all_trips(FILE *fp, trip_t **records);

#endif
