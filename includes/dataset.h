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
    calendar_date_t *calendar_dates;
    calendar_record_t *calendar_records;
    fare_attribute_t *fare_attributes;
    fare_rule_t *fare_rules;
    feed_info_t feed_info;
    frequency_t *frequencies;
    route_t *routes;
    shape_t *shapes;
    stop_time_t *stop_times;
    stop_t *stops;
    transfer_t *transfers;
    trip_t *trips;
} dataset_t;

#endif
