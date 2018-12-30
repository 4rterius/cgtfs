#ifndef CGTFS_DATASET_H
#define CGTFS_DATASET_H

#include "agency.h"
#include "calendar_dates.h"
#include "calendar.h"
#include "fare_attributes.h"
#include "fare_rule.h"
#include "feed_info.h"
#include "frequency.h"
#include "route.h"
#include "shape.h"
#include "stop_time.h"
#include "stop.h"
#include "transfers.h"
#include "trip.h"

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


feed_t empty_feed(void);
int read_feed(char *feed_directory_path, feed_t *feed_instance);

#endif
