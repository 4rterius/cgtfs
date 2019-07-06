#ifndef CGTFS_TESTS_RECORDS_AGENCY_C
#define CGTFS_TESTS_RECORDS_AGENCY_C

#include "greatest/greatest.h"
#include "records/agency.h"

TEST agency_read(void) {

    #define FIELDS_NUM_1 8
    char *field_names[FIELDS_NUM_1] = {
        "agency_id", "agency_name", "agency_url", "agency_timezone",
        "agency_lang", "agency_phone", "agency_fare_url", "agency_email"
    };
    char *field_values[FIELDS_NUM_1] = {
        "1", "blahblah", "http://example.com/", "Europe/Moscow",
        "en", "0 000 000 00 00", "http://cash.me/outside", "ex@amp.le"
    };
    
    agency_t a_1;
    read_agency(&a_1, FIELDS_NUM_1, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("1", a_1.id);
    ASSERT_STR_EQ("blahblah", a_1.name);
    ASSERT_STR_EQ("http://example.com/", a_1.url);
    ASSERT_STR_EQ("Europe/Moscow", a_1.timezone);
    ASSERT_STR_EQ("en", a_1.lang);
    ASSERT_STR_EQ("0 000 000 00 00", a_1.phone);
    ASSERT_STR_EQ("http://cash.me/outside", a_1.fare_url);
    ASSERT_STR_EQ("ex@amp.le", a_1.email);

    PASS();
}

TEST agency_compare(void) {
    agency_t a = {
        .id = "SOME_ID1",
        .name = "amazing name",
        .url = "",
        .timezone = "dfghjkl244124 qwe",
        .lang = "fi",
        .phone = "000111222",
        .fare_url = "https://example.com",
        .email = "no-reply@example.com"
    };

    agency_t b = {
        .id = "SOME_ID1",
        .name = "amazing name",
        .url = "",
        .timezone = "dfghjkl244124 qwe",
        .lang = "fi",
        .phone = "000111222",
        .fare_url = "https://example.com",
        .email = "no-reply@example.com"
    };

    agency_t c = {
        .id = "SOME_ID0",
        .name = "amazing name",
        .url = " ",
        .timezone = "dfghjkl244124 qwe",
        .lang = "fi",
        .phone = "0001112223",
        .email = "no-reply@example.com"
    };

    ASSERT_EQ(0, equal_agency(&a, &b));
    ASSERT_EQ(1, equal_agency(&a, &c));
    ASSERT_EQ(1, equal_agency(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordAgency) {
    RUN_TEST(agency_read);
    RUN_TEST(agency_compare);
}

#endif