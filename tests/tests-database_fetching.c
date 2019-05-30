#ifndef CGTFS_TESTS_DATABASE_FETCHING_C
#define CGTFS_TESTS_DATABASE_FETCHING_C

#include "greatest/greatest.h"

#include "reading.h"
#include "database/fetching.h"


/** 
 * IMPORTANT: CGTFS_DatabaseStoring suite MUST be run first...
 * This suite checks that the previous suite did everything correctly...
 */
TEST db_all_agencies_fetch(void) {

    feed_db_t db;
    // feed_db_status_t res;

    agency_t *records;

    /* res = */ init_feed_db(&db, "tests_storing.db", 1);
    /* res = */ setup_feed_db(&db, 1);

    int retrieved_count = fetch_all_agencies_db(&db, &records);

    // printf("\nRetrieved: %i...\n", retrieved_count);
    // for (int i = 0; i < retrieved_count; i++) {
    //     printf("\n      agency #%i: {.id = %s, .name = %s}\n\n", i, records[i].id, records[i].name);
    // }

    agency_t expected[4] = {
        {
            .id = "1",
            .name = "Lahden Seudun Liikenne",
            .url = "http://www.lsl.fi",
            .timezone = "Europe/Helsinki",
            .lang = "fi",
            .phone = "03 814 2355"
        },
        {
            .id = "2",
            .name = "Jyväskylä",
            .url = "http://www.lsl.fi",
            .timezone = "blah, blah",
            .lang = "fi",
            .phone = "03 814 2355"
        },
        {
            .id = "3",
            .name = "",
            .url = "",
            .timezone = "",
            .lang = "",
            .phone = ""
        },
        {
            .id = "4",
            .name = "\"djghas\"ldföäånkl´+123sd\"",
            .url = "http://www.lsl.fi",
            .timezone = "blah \"HELLO\" blah",
            .lang = "fi",
            .phone = "03 814 2355"
        }
    };

    ASSERT_EQ_FMT(4, retrieved_count, "%i");
    ASSERT(!equal_agency(&(expected[0]), &(records[0])));
    ASSERT(!equal_agency(&(expected[1]), &(records[1])));
    ASSERT(!equal_agency(&(expected[2]), &(records[2])));
    ASSERT(!equal_agency(&(expected[3]), &(records[3])));
    

    free_feed_db(&db);
    if (retrieved_count > 0) free(records);
    PASS();
}

TEST db_all_calendar_dates_fetch(void) {

    feed_db_t db;
    // feed_db_status_t res;

    calendar_date_t *records;

    /* res = */ init_feed_db(&db, "tests_storing.db", 1);
    /* res = */ setup_feed_db(&db, 1);

    int retrieved_count = fetch_all_calendar_dates_db(&db, &records);

    calendar_date_t expected[9] = {
        {
            .service_id = "12",
            .date = "20190121",
            .exception_type = ET_ADDED
        },
        {
            .service_id = "12",
            .date = "20190128",
            .exception_type = ET_ADDED
        },
        {
            .service_id = "12",
            .date = "20190204",
            .exception_type = ET_ADDED
        },
        {
            .service_id = "12",
            .date = "20190211",
            .exception_type = ET_ADDED
        },
        {
            .service_id = "12",
            .date = "20190218",
            .exception_type = ET_ADDED
        },
        {
            .service_id = "12",
            .date = "20190225",
            .exception_type = ET_ADDED
        },
        {
            .service_id = "12",
            .date = "20190304",
            .exception_type = ET_ADDED
        },
        {
            .service_id = "12",
            .date = "20190311",
            .exception_type = ET_REMOVED
        },
        {
            .service_id = "12",
            .date = "20190318",
            .exception_type = ET_ADDED
        }
    };

    ASSERT_EQ_FMT(9, retrieved_count, "%i");
    ASSERT(!equal_calendar_date(&(expected[0]), &(records[0])));
    ASSERT(!equal_calendar_date(&(expected[1]), &(records[1])));
    ASSERT(!equal_calendar_date(&(expected[2]), &(records[2])));
    ASSERT(!equal_calendar_date(&(expected[3]), &(records[3])));
    ASSERT(!equal_calendar_date(&(expected[4]), &(records[4])));
    ASSERT(!equal_calendar_date(&(expected[5]), &(records[5])));
    ASSERT(!equal_calendar_date(&(expected[6]), &(records[6])));
    ASSERT(!equal_calendar_date(&(expected[7]), &(records[7])));
    ASSERT(!equal_calendar_date(&(expected[8]), &(records[8])));
    

    free_feed_db(&db);
    if (retrieved_count > 0) free(records);
    PASS();
}

TEST db_all_calendar_records_fetch(void) {

    feed_db_t db;
    // feed_db_status_t res;

    calendar_record_t *records;

    /* res = */ init_feed_db(&db, "tests_storing.db", 1);
    /* res = */ setup_feed_db(&db, 1);

    int retrieved_count = fetch_all_calendar_records_db(&db, &records);

    calendar_record_t expected[4] = {
        {
            .service_id = "1000",
            .monday = SA_AVAILABLE,
            .tuesday = SA_AVAILABLE,
            .wednesday = SA_AVAILABLE,
            .thursday = SA_AVAILABLE,
            .friday = SA_AVAILABLE,
            .saturday = SA_UNAVAILABLE,
            .sunday = SA_UNAVAILABLE,
            .start_date = "20180101",
            .end_date = "20190101"
        },
        {
            .service_id = "1001",
            .monday = SA_UNAVAILABLE,
            .tuesday = SA_UNAVAILABLE,
            .wednesday = SA_UNAVAILABLE,
            .thursday = SA_UNAVAILABLE,
            .friday = SA_UNAVAILABLE,
            .saturday = SA_AVAILABLE,
            .sunday = SA_AVAILABLE,
            .start_date = "20190101",
            .end_date = "20190101"
        },
        {
            .service_id = "1002",
            .monday = SA_NOT_SET,
            .tuesday = SA_NOT_SET,
            .wednesday = SA_NOT_SET,
            .thursday = SA_UNAVAILABLE,
            .friday = SA_AVAILABLE,
            .saturday = SA_AVAILABLE,
            .sunday = SA_NOT_SET,
            .start_date = "19910203",
            .end_date = "29920203"
        },
        {
            .service_id = "",
            .monday = SA_NOT_SET,
            .tuesday = SA_NOT_SET,
            .wednesday = SA_NOT_SET,
            .thursday = SA_NOT_SET,
            .friday = SA_NOT_SET,
            .saturday = SA_NOT_SET,
            .sunday = SA_NOT_SET,
            .start_date = "",
            .end_date = ""
        }
    };

    ASSERT_EQ_FMT(4, retrieved_count, "%i");
    ASSERT(!equal_calendar_record(&(expected[0]), &(records[0])));
    ASSERT(!equal_calendar_record(&(expected[1]), &(records[1])));
    ASSERT(!equal_calendar_record(&(expected[2]), &(records[2])));
    ASSERT(!equal_calendar_record(&(expected[3]), &(records[3])));
    

    free_feed_db(&db);
    if (retrieved_count > 0) free(records);
    PASS();
}

TEST db_all_fare_attributes_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/fare_attributes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/fare_attributes.txt` test file");
    } else {
        fare_attributes_t *expected;
        int expected_count = read_all_fare_attributes(fp, &expected);

        ASSERT_EQ_FMT(2, expected_count, "%i");


        feed_db_t db;
        fare_attributes_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_fare_attributes_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_fare_attributes(&(expected[i]), &(records[i])));


        free_feed_db(&db);
        if (retrieved_count > 0) free(records);
        if (expected_count > 0) free(expected);
        if (fp) fclose(fp);
    }
    PASS();
}


SUITE(CGTFS_DatabaseFetching) {
    RUN_TEST(db_all_agencies_fetch);
    RUN_TEST(db_all_calendar_dates_fetch);
    RUN_TEST(db_all_calendar_records_fetch);
    RUN_TEST(db_all_fare_attributes_fetch);
}

#endif