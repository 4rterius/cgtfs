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
 * and an integer field to store the number of the file's records (zero if no file or no records).
 * 
 * @see https://developers.google.com/transit/gtfs/reference/
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
 * @param[out] feed Pointer to the feed to initialize.
 */
void init_feed(feed_t *feed);

/**
 * Reads an unpacked GTFS feed from the given folder into the given feed_t pointer.
 * @param[out] instance             Pointer to the feed to read data into.
 * @param[in]  feed_directory_path  /path/to/unpacked/gtfs/feed
 * @returns 0
 */
int read_feed(feed_t *instance, const char *feed_directory_path);

/**
 * Frees the memory taken by the given feed structure.
 * @param feed Pointer to the feed to free.
 */
void free_feed(feed_t *feed);

#endif
