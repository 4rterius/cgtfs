#ifndef CGTFS_TESTS_ALL_C
#define CGTFS_TESTS_ALL_C

#include "greatest/greatest.h"
#include "feed.h"

TEST feed_parsing_success(void) {
    feed_t f;
    
    init_feed(&f);
    read_feed(&f, "../tests/data/google_sample");

    ASSERT_EQ(f.agency_count, 1);
    ASSERT_EQ(f.calendar_dates_count, 1);
    ASSERT_EQ(f.calendar_records_count, 2);
    ASSERT_EQ(f.fare_attributes_count, 2);
    ASSERT_EQ(f.fare_rules_count, 4);
    ASSERT_EQ(f.feed_info_count, -1);
    ASSERT_EQ(f.frequencies_count, 11);
    ASSERT_EQ(f.routes_count, 5);
    ASSERT_EQ(f.shapes_count, 0);
    ASSERT_EQ(f.stop_times_count, 28);
    ASSERT_EQ(f.stops_count, 9);
    ASSERT_EQ(f.transfers_count, -1);
    ASSERT_EQ(f.trips_count, 11);

    free_feed(&f);
    PASS();
}

TEST feed_parsing_agency(void) {
    feed_t f;
    
    init_feed(&f);
    read_feed(&f, "../tests/data/google_sample");

    agency_t a1 = { .id = "DTA",
                    .name = "Demo Transit Authority",
                    .url = "http://google.com",
                    .timezone = "America/Los_Angeles"
    };

    ASSERT_EQ(f.agency_count, 1);

    ASSERT_STR_EQ(f.agencies[0].id, a1.id);
    ASSERT_STR_EQ(f.agencies[0].name, a1.name);
    ASSERT_STR_EQ(f.agencies[0].url, a1.url);
    ASSERT_STR_EQ(f.agencies[0].timezone, a1.timezone);

    free_feed(&f);
    PASS();
}

// ...



SUITE(CGTFS_Feed) {
    RUN_TEST(feed_parsing_success);
    RUN_TEST(feed_parsing_agency);
}

#endif