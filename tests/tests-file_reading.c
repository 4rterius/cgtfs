#ifndef CGTFS_TESTS_FILE_READING_C
#define CGTFS_TESTS_FILE_READING_C

#include "greatest/greatest.h"
#include "reading.h"


TEST fr_agency(void) {
    FILE *fp = fopen("../tests/data/google_sample/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/agency.txt` test file");
    } else {
        agency_t *records;
        int record_count = read_all_agencies(fp, &records);

        ASSERT_EQ(1, record_count);

        agency_t expected[1] = {
            {
                .id = "DTA",
                .name = "Demo Transit Authority",
                .url = "http://google.com",
                .timezone = "America/Los_Angeles"
            }
        };

        ASSERT(!equal_agency(&(expected[0]), &(records[0])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_calendar_dates(void) {
    FILE *fp = fopen("../tests/data/google_sample/calendar_dates.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/calendar_dates.txt` test file");
    } else {
        calendar_date_t *records;
        int record_count = read_all_calendar_dates(fp, &records);

        ASSERT_EQ(1, record_count);

        calendar_date_t expected[1] = {
            {
                .service_id = "FULLW",
                .date = "20070604",
                .exception_type = ET_REMOVED
            }
        };

        ASSERT(!equal_calendar_date(&(expected[0]), &(records[0])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_calendar_records(void) {
    FILE *fp = fopen("../tests/data/google_sample/calendar.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/calendar.txt` test file");
    } else {
        calendar_record_t *records;
        int record_count = read_all_calendar_records(fp, &records);

        ASSERT_EQ(2, record_count);

        calendar_record_t expected[2] = {
            {
                .service_id = "FULLW",
                .start_date = "20070101",
                .end_date = "20101231",
                .monday = SA_AVAILABLE,
                .tuesday = SA_AVAILABLE,
                .wednesday = SA_AVAILABLE,
                .thursday = SA_AVAILABLE,
                .friday = SA_AVAILABLE,
                .saturday = SA_AVAILABLE,
                .sunday = SA_AVAILABLE
            },
            {
                .service_id = "WE",
                .start_date = "20070101",
                .end_date = "20101231",
                .monday = SA_UNAVAILABLE,
                .tuesday = SA_UNAVAILABLE,
                .wednesday = SA_UNAVAILABLE,
                .thursday = SA_UNAVAILABLE,
                .friday = SA_UNAVAILABLE,
                .saturday = SA_AVAILABLE,
                .sunday = SA_AVAILABLE
            },
        };

        ASSERT(!equal_calendar_record(&(expected[0]), &(records[0])));
        ASSERT(!equal_calendar_record(&(expected[1]), &(records[1])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_fare_attributes(void) {
    FILE *fp = fopen("../tests/data/google_sample/fare_attributes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/fare_attributes.txt` test file");
    } else {
        fare_attributes_t *records;
        int record_count = read_all_fare_attributes(fp, &records);

        ASSERT_EQ(2, record_count);

        fare_attributes_t expected[2] = {
            {
                .fare_id = "p",
                .price = 1.25,
                .currency_type = "USD",
                .payment_method = PM_ON_BOARD,
                .transfers = TS_NOT_ALLOWED,
                .transfer_duration = 0
            },
            {
                .fare_id = "a",
                .price = 5.25,
                .currency_type = "USD",
                .payment_method = PM_ON_BOARD,
                .transfers = TS_NOT_ALLOWED,
                .transfer_duration = 0
            }
        };

        ASSERT(!equal_fare_attributes(&(expected[0]), &(records[0])));
        ASSERT(!equal_fare_attributes(&(expected[1]), &(records[1])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_fare_rules(void) {
    FILE *fp = fopen("../tests/data/google_sample/fare_rules.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/fare_rules.txt` test file");
    } else {
        fare_rule_t *records;
        int record_count = read_all_fare_rules(fp, &records);

        ASSERT_EQ(4, record_count);

        fare_rule_t expected[4] = {
            {
                .fare_id = "p",
                .route_id = "AB",
                .origin_id = "",
                .destination_id = "",
                .contains_id = ""
            },
            {
                .fare_id = "p",
                .route_id = "STBA",
                .origin_id = "",
                .destination_id = "",
                .contains_id = ""
            },
            {
                .fare_id = "p",
                .route_id = "BFC",
                .origin_id = "",
                .destination_id = "",
                .contains_id = ""
            },
            {
                .fare_id = "a",
                .route_id = "AAMV",
                .origin_id = "",
                .destination_id = "",
                .contains_id = ""
            }
        };

        ASSERT(!equal_fare_rule(&(expected[0]), &(records[0])));
        ASSERT(!equal_fare_rule(&(expected[1]), &(records[1])));
        ASSERT(!equal_fare_rule(&(expected[2]), &(records[2])));
        ASSERT(!equal_fare_rule(&(expected[3]), &(records[3])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_frequencies(void) {
    FILE *fp = fopen("../tests/data/google_sample/frequencies.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/frequencies.txt` test file");
    } else {
        frequency_t *records;
        int record_count = read_all_frequencies(fp, &records);

        ASSERT_EQ(11, record_count);

        frequency_t expected[11] = {
            {
                .trip_id = "STBA",
                .start_time = "6:00:00",
                .end_time = "22:00:00",
                .headway_secs = 1800
            },
            {
                .trip_id = "CITY1",
                .start_time = "6:00:00",
                .end_time = "7:59:59",
                .headway_secs = 1800
            },
            {
                .trip_id = "CITY2",
                .start_time = "6:00:00",
                .end_time = "7:59:59",
                .headway_secs = 1800
            }
        };

        ASSERT(!equal_frequency(&(expected[0]), &(records[0])));
        ASSERT(!equal_frequency(&(expected[1]), &(records[1])));
        ASSERT(!equal_frequency(&(expected[2]), &(records[2])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_levels(void) {
    FILE *fp = fopen("../tests/data/ext_levels.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/ext_levels.txt` test file");
    } else {
        level_t *records;
        int record_count = read_all_levels(fp, &records);

        ASSERT_EQ(4, record_count);

        level_t expected[4] = {
            {
                .id = "LVL_001",
                .index = 1.6,
                .name = "Upper Level"
            },
            {
                .id = "LVL_002",
                .index = 1.0,
                .name = "Mid Level"
            },
            {
                .id = "LVL_003",
                .index = 0,
                .name = "Bottom Level"
            },
            {
                .id = "LVL_004",
                .index = -0.5,
                .name = "Underground Level"
            }
        };

        ASSERT(!equal_level(&(expected[0]), &(records[0])));
        ASSERT(!equal_level(&(expected[1]), &(records[1])));
        ASSERT(!equal_level(&(expected[2]), &(records[2])));
        ASSERT(!equal_level(&(expected[3]), &(records[3])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_pathways(void) {
    FILE *fp = fopen("../tests/data/ext_pathways.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/ext_pathways.txt` test file");
    } else {
        pathway_t *records;
        int record_count = read_all_pathways(fp, &records);

        ASSERT_EQ(2, record_count);

        pathway_t expected[2] = {
            {
                .id = "PW1",
                .from_stop_id = "STP_A",
                .to_stop_id = "STP_Z",
                .mode = PTMD_WALKWAY,
                .is_bidirectional = PD_BIDIRECTIONAL,
                .length = 250000.74,
                .traversal_time = 6000,
                .stair_count = 3,
                .max_slope = 0.083,
                .min_width = 2.1,
                .signposted_as = "Туда",
                .reversed_signposted_as = "Сюда"
            },
            {
                .id = "PW9",
                .from_stop_id = "STP_X",
                .to_stop_id = "STP_C",
                .mode = PTMD_PAYGATE,
                .is_bidirectional = PD_UNIDIRECTIONAL,
                .length = 15.6,
                .traversal_time = 100,
                .stair_count = -9,
                .max_slope = 0,
                .min_width = 1.7,
                .signposted_as = "Сюда",
                .reversed_signposted_as = "Туда"
            }
        };

        ASSERT(!equal_pathway(&(expected[0]), &(records[0])));
        ASSERT(!equal_pathway(&(expected[1]), &(records[1])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_routes(void) {
    FILE *fp = fopen("../tests/data/google_sample/routes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/routes.txt` test file");
    } else {
        route_t *records;
        int record_count = read_all_routes(fp, &records);

        ASSERT_EQ(5, record_count);

        route_t expected[5] = {
            {
                .id = "AB",
                .agency_id = "DTA",
                .short_name = "10",
                .long_name = "Airport - Bullfrog",
                .desc = "",
                .type = RT_BUS,
                .url = "",
                .color = "",
                .text_color = ""
            },
            {
                .id = "BFC",
                .agency_id = "DTA",
                .short_name = "20",
                .long_name = "Bullfrog - Furnace Creek Resort",
                .desc = "",
                .type = RT_BUS,
                .url = "",
                .color = "",
                .text_color = ""
            },
            {
                .id = "STBA",
                .agency_id = "DTA",
                .short_name = "30",
                .long_name = "Stagecoach - Airport Shuttle",
                .desc = "",
                .type = RT_BUS,
                .url = "",
                .color = "",
                .text_color = ""
            }
        };

        ASSERT(!equal_route(&(expected[0]), &(records[0])));
        ASSERT(!equal_route(&(expected[1]), &(records[1])));
        ASSERT(!equal_route(&(expected[2]), &(records[2])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_shapes(void) {
    FILE *fp = fopen("../tests/data/google_sample/shapes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/shapes.txt` test file");
    } else {
        shape_t *records;
        int record_count = read_all_shapes(fp, &records);

        ASSERT_EQ(0, record_count);

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_stop_times(void) {
    FILE *fp = fopen("../tests/data/google_sample/stop_times.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/stop_times.txt` test file");
    } else {
        stop_time_t *records;
        int record_count = read_all_stop_times(fp, &records);

        ASSERT_EQ(28, record_count);

        stop_time_t expected[28] = {
            {
                .trip_id = "STBA",
                .arrival_time = "6:00:00",
                .departure_time = "6:00:00",
                .stop_id = "STAGECOACH",
                .stop_sequence = 1,
                .stop_headsign = "",
                .pickup_type = ST_REGULAR,
                .dropoff_type = ST_REGULAR,
                .shape_dist_traveled = 0,
                .timepoint = TP_EXACT
            },
            {
                .trip_id = "STBA",
                .arrival_time = "6:20:00",
                .departure_time = "6:20:00",
                .stop_id = "BEATTY_AIRPORT",
                .stop_sequence = 2,
                .stop_headsign = "",
                .pickup_type = ST_REGULAR,
                .dropoff_type = ST_REGULAR,
                .shape_dist_traveled = 0,
                .timepoint = TP_EXACT
            },
            {
                .trip_id = "CITY1",
                .arrival_time = "6:00:00",
                .departure_time = "6:00:00",
                .stop_id = "STAGECOACH",
                .stop_sequence = 1,
                .stop_headsign = "",
                .pickup_type = ST_REGULAR,
                .dropoff_type = ST_REGULAR,
                .shape_dist_traveled = 0,
                .timepoint = TP_EXACT
            }
        };

        ASSERT(!equal_stop_time(&(expected[0]), &(records[0])));
        ASSERT(!equal_stop_time(&(expected[1]), &(records[1])));
        ASSERT(!equal_stop_time(&(expected[2]), &(records[2])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_stops(void) {
    FILE *fp = fopen("../tests/data/google_sample/stops.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/stops.txt` test file");
    } else {
        stop_t *records;
        int record_count = read_all_stops(fp, &records);

        ASSERT_EQ(9, record_count);

        stop_t expected[9] = {
            {
                .id = "FUR_CREEK_RES",
                .name = "Furnace Creek Resort (Demo)",
                .desc = "",
                .lat = 36.425288,
                .lon = -117.133162,
                .zone_id = "",
                .url = ""
            },
            {
                .id = "BEATTY_AIRPORT",
                .name = "Nye County Airport (Demo)",
                .desc = "",
                .lat = 36.868446,
                .lon = -116.784582,
                .zone_id = "",
                .url = ""
            },
            {
                .id = "BULLFROG",
                .name = "Bullfrog (Demo)",
                .desc = "",
                .lat = 36.88108,
                .lon = -116.81797,
                .zone_id = "",
                .url = ""
            }
        };

        ASSERT(!equal_stop(&(expected[0]), &(records[0])));
        ASSERT(!equal_stop(&(expected[1]), &(records[1])));
        ASSERT(!equal_stop(&(expected[2]), &(records[2])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST fr_transfers(void) {
    FILE *fp = fopen("../tests/data/google_sample/transfers.txt", "r");

    transfer_t *records;
    int record_count = read_all_transfers(fp, &records);

    ASSERT_EQ_FMTm("Parsed records from empty file", -1, record_count, "%i");

    if (record_count > 0) free(records);
    if (fp) fclose(fp);

    PASS();
}

TEST fr_trips(void) {
    FILE *fp = fopen("../tests/data/google_sample/trips.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/trips.txt` test file");
    } else {
        trip_t *records;
        int record_count = read_all_trips(fp, &records);

        ASSERT_EQ(11, record_count);

        trip_t expected[11] = {
            {
                .route_id = "AB",
                .service_id = "FULLW",
                .id = "AB1",
                .headsign = "to Bullfrog",
                .direction_id = 0,
                .block_id = "1",
                .shape_id = ""
            },
            {
                .route_id = "AB",
                .service_id = "FULLW",
                .id = "AB2",
                .headsign = "to Airport",
                .direction_id = 1,
                .block_id = "2",
                .shape_id = ""
            },
            {
                .route_id = "STBA",
                .service_id = "FULLW",
                .id = "STBA",
                .headsign = "Shuttle",
                .direction_id = 0,
                .block_id = "",
                .shape_id = ""
            }
        };

        ASSERT(!equal_trip(&(expected[0]), &(records[0])));
        ASSERT(!equal_trip(&(expected[1]), &(records[1])));
        ASSERT(!equal_trip(&(expected[2]), &(records[2])));

        if (record_count > 0) free(records);
        if (fp) fclose(fp);
    }
    PASS();
}



SUITE(CGTFS_FileReading) {
    RUN_TEST(fr_agency);
    RUN_TEST(fr_calendar_dates);
    RUN_TEST(fr_calendar_records);
    RUN_TEST(fr_fare_attributes);
    RUN_TEST(fr_fare_rules);
    RUN_TEST(fr_frequencies);
    RUN_TEST(fr_levels);
    RUN_TEST(fr_pathways);
    RUN_TEST(fr_routes);
    RUN_TEST(fr_shapes);
    RUN_TEST(fr_stop_times);
    RUN_TEST(fr_stops);
    RUN_TEST(fr_transfers);
    RUN_TEST(fr_trips);
}

#endif