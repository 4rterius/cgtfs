#ifndef CGTFS_TESTS_RECORDS_FEED_INFO_C
#define CGTFS_TESTS_RECORDS_FEED_INFO_C

#include "greatest/greatest.h"
#include "records/feed_info.h"

TEST feed_info_read(void) {

    #define FIELDS_NUM_6 8
    char *field_names[FIELDS_NUM_6] = {
        "feed_publisher_name", "feed_publisher_url", "feed_lang", "feed_start_date",
        "feed_end_date", "feed_version", "feed_contact_email", "feed_contact_url"
    };
    char *field_values[FIELDS_NUM_6] = {
        "Vasilij Terkin", "protocol://domain.zone", "somelang", "18970527",
        "30000101", "0.1.0", "some@example.com", "http://example.com"
    };

    feed_info_t fi_1;
    read_feed_info(&fi_1, FIELDS_NUM_6, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("Vasilij Terkin", fi_1.feed_publisher_name);
    ASSERT_STR_EQ("protocol://domain.zone", fi_1.feed_publisher_url);
    ASSERT_STR_EQ("somelang", fi_1.feed_lang);
    ASSERT_STR_EQ("18970527", fi_1.feed_start_date);
    ASSERT_STR_EQ("30000101", fi_1.feed_end_date);
    ASSERT_STR_EQ("0.1.0", fi_1.feed_version);
    ASSERT_STR_EQ("some@example.com", fi_1.feed_contact_email);
    ASSERT_STR_EQ("http://example.com", fi_1.feed_contact_url);

    PASS();
}

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

    ASSERT_EQ(1, equal_feed_info(&a, &b));
    ASSERT_EQ(0, equal_feed_info(&a, &c));
    ASSERT_EQ(0, equal_feed_info(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordFeedInfo) {
    RUN_TEST(feed_info_read);
    RUN_TEST(feed_info_compare);
}

#endif