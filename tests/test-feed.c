#ifndef CGTFS_TESTS_FEED_C
#define CGTFS_TESTS_FEED_C

#include "feed.h"

int test_feed_good(void) {
    feed_t feed = empty_feed();
    read_feed("../tests/data/google_sample", &feed);

    if (feed.agency_count != 1)
        printf("Feed reader counted incorrect number of agencies.\n");
    
    if (feed.calendar_dates_count != 1)
        printf("Feed reader counted incorrect number of calendar dates.\n");

    if (feed.calendar_records_count != 2)
        printf("Feed reader counted incorrect number of calendar records.\n");

    if (feed.fare_attributes_count != 2)
        printf("Feed reader counted incorrect number of fare attributes.\n");

    if (feed.fare_rules_count != 4)
        printf("Feed reader counted incorrect number of fare rules.\n");

    if (feed.feed_info_count != -1)
        printf("Feed reader counted incorrect number of feed info.\n");

    if (feed.frequencies_count != 11)
        printf("Feed reader counted incorrect number of frequencies.\n");
    
    if (feed.routes_count != 5)
        printf("Feed reader counted incorrect number of routes.\n");
    
    if (feed.shapes_count != 0)
        printf("Feed reader counted incorrect number of shapes.\n");
    
    if (feed.stop_times_count != 28)
        printf("Feed reader counted incorrect number of stop times.\n");
    
    if (feed.stops_count != 9)
        printf("Feed reader counted incorrect number of stops.\n");
    
    if (feed.transfers_count != -1)
        printf("Feed reader counted incorrect number of transfers.\n");
    
    if (feed.trips_count != 11)
        printf("Feed reader counted incorrect number of trips.\n");

    return 0;
}

#endif