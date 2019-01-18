#ifndef CGTFS_TESTS_ALL_C
#define CGTFS_TESTS_ALL_C

#include "greatest/greatest.h"
#include "feed.h"

TEST feed_parsing(void) {
    feed_t f;
    
    read_feed(&f, "../tests/data/google_sample");

    ASSERT_EQ(1, f.agency_count);
    ASSERT_EQ(1, f.calendar_dates_count);
    ASSERT_EQ(2, f.calendar_records_count);
    ASSERT_EQ(2, f.fare_attributes_count);
    ASSERT_EQ(4, f.fare_rules_count);
    ASSERT_EQ(-1, f.feed_info_count);
    ASSERT_EQ(11, f.frequencies_count);
    ASSERT_EQ(5, f.routes_count);
    ASSERT_EQ(0, f.shapes_count);
    ASSERT_EQ(28, f.stop_times_count);
    ASSERT_EQ(9, f.stops_count);
    ASSERT_EQ(-1, f.transfers_count);
    ASSERT_EQ(11, f.trips_count);

    free_feed(&f);
    PASS();
}

TEST feed_comparison(void) {
    feed_t f1, f2, f3;

    read_feed(&f1, "../tests/data/google_sample");
    read_feed(&f2, "../tests/data/google_sample");
    read_feed(&f3, "../tests/data/pocono_pony");

    ASSERT_EQ_FMT(0, equal_feeds(&f1, &f2), "%i");
    ASSERT_EQ_FMT(1, equal_feeds(&f1, &f3), "%i");
    ASSERT_EQ_FMT(1, equal_feeds(&f2, &f3), "%i");

    free_feed(&f1);
    free_feed(&f2);
    free_feed(&f3);
}



SUITE(CGTFS_Feed) {
    RUN_TEST(feed_parsing);
    RUN_TEST(feed_comparison);
}

#endif