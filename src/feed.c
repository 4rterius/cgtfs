#include "feed.h"

feed_t empty_feed(void) {
    feed_t feed;
    feed.agencies = NULL;
    feed.agency_count = 0;
    feed.calendar_dates = NULL;
    feed.calendar_dates_count = 0;
    feed.calendar_records = NULL;
    feed.calendar_records_count = 0;
    feed.fare_attributes = NULL;
    feed.fare_attributes_count = 0;
    feed.fare_rules = NULL;
    feed.fare_rules_count = 0;
    feed.feed_info = NULL;
    feed.feed_info_count = 0;
    feed.frequencies = NULL;
    feed.frequencies_count = 0;
    feed.routes = NULL;
    feed.routes_count = 0;
    feed.shapes = NULL;
    feed.shapes_count = 0;
    feed.stop_times = NULL;
    feed.stop_times_count = 0;
    feed.stops = NULL;
    feed.stops_count = 0;
    feed.transfers = NULL;
    feed.transfers_count = 0;
    feed.trips = NULL;
    feed.trips_count = 0;
    return feed;
}