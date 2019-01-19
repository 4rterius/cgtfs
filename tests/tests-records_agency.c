#ifndef CGTFS_TESTS_RECORDS_AGENCY_C
#define CGTFS_TESTS_RECORDS_AGENCY_C

#include "greatest/greatest.h"
#include "records/agency.h"

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

    ASSERT_EQ(equal_agency(&a, &b), 0);
    ASSERT_EQ(equal_agency(&a, &c), 1);
    ASSERT_EQ(equal_agency(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordAgency) {
    RUN_TEST(agency_compare);
}

#endif