#ifndef CGTFS_TESTS_RECORDS_FEED_INFO_C
#define CGTFS_TESTS_RECORDS_FEED_INFO_C

#include "greatest/greatest.h"
#include "records/feed_info.h"

TEST feed_info_compare(void) {
    feed_info_t a = {
        .feed_publisher_name = "EXAMPLE",
        .feed_publisher_url = "https://example.com",
        .feed_lang = "EN",
        .feed_start_date = "01012019",
        .feed_end_date = "02012019",
        .feed_version = "",
        .feed_contact_email = "example@some.url",
        .feed_contact_url = "https://some.url/"
    };

    feed_info_t b = {
        .feed_publisher_name = "EXAMPLE",
        .feed_publisher_url = "https://example.com",
        .feed_lang = "EN",
        .feed_start_date = "01012019",
        .feed_end_date = "02012019",
        .feed_version = "",
        .feed_contact_email = "example@some.url",
        .feed_contact_url = "https://some.url/"
    };

    feed_info_t c = {
        .feed_publisher_name = "EXAMPLE2",
        .feed_publisher_url = "https://example.c0m",
        .feed_lang = "",
        .feed_start_date = "01012019",
        .feed_end_date = "02012019",
        .feed_version = "2",
        .feed_contact_email = "example@some.url",
        .feed_contact_url = "https://some.url/"
    };

    ASSERT_EQ(equal_feed_info(&a, &b), 0);
    ASSERT_EQ(equal_feed_info(&a, &c), 1);
    ASSERT_EQ(equal_feed_info(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordFeedInfo) {
    RUN_TEST(feed_info_compare);
}

#endif