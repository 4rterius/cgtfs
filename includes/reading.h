#ifndef CGTFS_READING_H
#define CGTFS_READING_H

#include <stdio.h>

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

int read_agencies(FILE *fp, agency_t **records);
int read_calendar_dates(FILE *fp, calendar_date_t **records);
int read_calendar_records(FILE *fp, calendar_record_t **records);
int read_fare_attributes(FILE *fp, fare_attribute_t **records);
int read_fare_rules(FILE *fp, fare_rule_t **records);
int read_feed_info(FILE *fp, feed_info_t *records);
int read_frequences(FILE *fp, frequency_t **records);
int read_routes(FILE *fp, route_t **records);
int read_shapes(FILE *fp, shape_t **records);
int read_stop_times(FILE *fp, stop_time_t **records);
int read_stops(FILE *fp, stop_t **records);
int read_transfers(FILE *fp, transfer_t **records);
int read_trips(FILE *fp, trip_t **records);

#endif
