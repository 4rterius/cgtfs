#ifndef CGTFS_TESTS_DATABASE_STORING_C
#define CGTFS_TESTS_DATABASE_STORING_C

#include "greatest/greatest.h"
#include "database/storing.h"


TEST db_all_agencies_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/agency.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_agencies_db(fp, &db);
        ASSERT_EQ(4, stored_count);

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_calendar_dates_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/calendar_dates.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/calendar_dates.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_calendar_dates_db(fp, &db);
        ASSERT_EQ_FMT(9, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_calendar_records_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/calendar.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/calendar.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_calendar_records_db(fp, &db);
        ASSERT_EQ_FMT(4, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_fare_attributes_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/fare_attributes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/fare_attributes.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_fare_attributes_db(fp, &db);
        ASSERT_EQ_FMT(2, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_fare_rules_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/fare_rules.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/fare_rules.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_fare_rules_db(fp, &db);
        ASSERT_EQ_FMT(4, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_feed_info_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/feed_info.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/feed_info.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_feed_info_db(fp, &db);
        ASSERT_EQ_FMT(1, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_frequencies_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/frequencies.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/frequencies.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_frequencies_db(fp, &db);
        ASSERT_EQ_FMT(11, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_routes_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/routes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/routes.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_routes_db(fp, &db);
        ASSERT_EQ_FMT(8, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_shapes_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/shapes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/shapes.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_shapes_db(fp, &db);
        ASSERT_EQ_FMT(10, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_stop_times_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/stop_times.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/stop_times.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_stop_times_db(fp, &db);
        ASSERT_EQ_FMT(28, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_stops_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/stops.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/stops.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_stops_db(fp, &db);
        ASSERT_EQ_FMT(6, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_transfers_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/transfers.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/transfers.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_transfers_db(fp, &db);
        ASSERT_EQ_FMT(4, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_trips_store(void) {
    FILE *fp = fopen("../tests/data/stupid_gtfs/trips.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/trips.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_storing.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_trips_db(fp, &db);
        ASSERT_EQ_FMT(4, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

SUITE(CGTFS_DatabaseStoring) {
    RUN_TEST(db_all_agencies_store);
    RUN_TEST(db_all_calendar_dates_store);
    RUN_TEST(db_all_calendar_records_store);
    RUN_TEST(db_all_fare_attributes_store);
    RUN_TEST(db_all_fare_rules_store);
    RUN_TEST(db_all_feed_info_store);
    RUN_TEST(db_all_frequencies_store);
    RUN_TEST(db_all_routes_store);
    RUN_TEST(db_all_shapes_store);
    RUN_TEST(db_all_stop_times_store);
    RUN_TEST(db_all_stops_store);
    RUN_TEST(db_all_stop_times_store);  // TODO: remove
    RUN_TEST(db_all_transfers_store);
    RUN_TEST(db_all_trips_store);
}

#endif