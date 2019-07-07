/**
 * @file
 * @brief    Core feed entity functionality.
 */

#ifndef CGTFS_DATASET_H
#define CGTFS_DATASET_H

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

#include "helpers/filenames.h"
#include "reading.h"


/**
 * A GTFS feed entity that encapsulates all data of a single GTFS feed.
 *
 * For each of the GTFS feed files,
 * this struct has a field for an array of the structs to store the file's records
 * and an integer field to store the number of the file's records (-1 if no file or no records).
 *
 * Initialized with init_feed() and freed with free_feed().
 *
 * @see https://developers.google.com/transit/gtfs/reference/
 *
 * @ingroup    Core__FeedEntity
 */
typedef struct {
    agency_t *agencies;
    int agency_count;
    calendar_date_t *calendar_dates;
    int calendar_dates_count;
    calendar_record_t *calendar_records;
    int calendar_records_count;
    fare_attributes_t *fare_attributes;
    int fare_attributes_count;
    fare_rule_t *fare_rules;
    int fare_rules_count;
    feed_info_t *feed_info;
    int feed_info_count;  // 0 or 1 really, but for consistency sake.
    frequency_t *frequencies;
    int frequencies_count;
    route_t *routes;
    int routes_count;
    shape_t *shapes;
    int shapes_count;
    stop_time_t *stop_times;
    int stop_times_count;
    stop_t *stops;
    int stops_count;
    transfer_t *transfers;
    int transfers_count;
    trip_t *trips;
    int trips_count;
} feed_t;


/**
 * Initializes a feed structure with default values
 * (pointers/arrays with NULLs, *_count fields with 0-s).
 *
 * @param[in,out]    feed    Unitialized feed instance.
 *
 * @ingroup          Core__FeedEntity
 */
void init_feed(feed_t *feed);

/**
 * Reads an unpacked GTFS feed from the given folder
 * into the given feed instance.
 *
 * This function is a convenience wrapper for calling
 * file-scope reading functions, which read the entire
 * *.txt files into arrays. It passes pointers
 * to feed_t fields, and after reading stores the counts
 * of each parsed record type into _count fields.
 *
 * @param[out]    instance               Initialized feed instance to read data into.
 * @param[in]     feed_directory_path    /path/to/unpacked/gtfs/feed
 *
 * @returns 0
 *
 * @ingroup       Core__FeedEntity
 */
int read_feed(feed_t *instance, const char *feed_directory_path);

/**
 * Frees the memory taken by the given feed structure.
 *
 * Must be called after a feed instance has been used.
 *
 * @param[in,out]    feed    Initialized feed instance to free.
 */
void free_feed(feed_t *feed);

/**
 * Compares two feed instances.
 *
 * @param[in]    a    First feed instance.
 * @param[in]    b    Second feed instance.
 *
 * @returns      0 if feeds are equal, non-zero if not.
 *
 * @ingroup      Core__FeedEntity
 */
int equal_feeds(const feed_t *a, const feed_t *b);

#endif
