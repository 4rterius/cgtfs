#include "dataset.h"

dataset_t empty_dataset(void) {
    dataset_t ds;
    ds.agencies = NULL;
    ds.agency_count = 0;
    ds.calendar_dates = NULL;
    ds.calendar_dates_count = 0;
    ds.calendar_records = NULL;
    ds.calendar_records_count = 0;
    ds.fare_attributes = NULL;
    ds.fare_attributes_count = 0;
    ds.fare_rules = NULL;
    ds.fare_rules_count = 0;
    ds.feed_info = NULL;
    ds.feed_info_count = 0;
    ds.frequencies = NULL;
    ds.frequencies_count = 0;
    ds.routes = NULL;
    ds.routes_count = 0;
    ds.shapes = NULL;
    ds.shapes_count = 0;
    ds.stop_times = NULL;
    ds.stop_times_count = 0;
    ds.stops = NULL;
    ds.stops_count = 0;
    ds.transfers = NULL;
    ds.transfers_count = 0;
    ds.trips = NULL;
    ds.trips_count = 0;
    return ds;
}