#ifndef CGTFS_TESTS_READING_C
#define CGTFS_TESTS_READING_C

#include <stdio.h>
#include "reading.h"

int test_reading_all_agencies() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/agency.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/agency.txt` file");
        } else {
            agency_t *records;
            int record_count = read_all_agencies(fp, &records);

            if (record_count != 1) {
                printf("Number of records parsed from agencies file is incorrect");
            }

            if (!(
                !strcmp(records[0].id, "DTA") &&
                !strcmp(records[0].name, "Demo Transit Authority") &&
                !strcmp(records[0].url, "http://google.com") &&
                !strcmp(records[0].timezone, "America/Los_Angeles")
            )) {
                printf("Parsed agency file record 1 incorrectly!");
            }
            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_calendar_dates() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/calendar_dates.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/calendar_dates.txt` file");
        } else {
            calendar_date_t *records;
            int record_count = read_all_calendar_dates(fp, &records);

            if (record_count != 1) {
                printf("Number of records parsed from calendar dates file is incorrect");
            }

            if (!(
                !strcmp(records[0].service_id, "FULLW") &&
                !strcmp(records[0].date, "20070604") &&
                records[0].exception_type == ET_REMOVED
            )) {
                printf("Parsed calendar dates file record 1 incorrectly!");
            }
            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_calendar_records() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/calendar.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/calendar.txt` file");
        } else {
            calendar_record_t *records;
            int record_count = read_all_calendar_records(fp, &records);

            if (record_count != 2) {
                printf("Number of records parsed from calendar records file is incorrect");
            }

            if (!(
                !strcmp(records[0].service_id, "FULLW") &&
                records[0].monday == SA_AVAILABLE &&
                records[0].tuesday == SA_AVAILABLE &&
                records[0].wednesday == SA_AVAILABLE &&
                records[0].thursday == SA_AVAILABLE &&
                records[0].friday == SA_AVAILABLE &&
                records[0].saturday == SA_AVAILABLE &&
                records[0].sunday == SA_AVAILABLE &&
                !strcmp(records[0].start_date, "20070101") &&
                !strcmp(records[0].end_date, "20101231")
            )) {
                printf("Parsed calendar records file record 1 incorrectly!");
            }
            
            if (!(
                !strcmp(records[1].service_id, "WE") &&
                records[1].monday == SA_UNAVAILABLE &&
                records[1].tuesday == SA_UNAVAILABLE &&
                records[1].wednesday == SA_UNAVAILABLE &&
                records[1].thursday == SA_UNAVAILABLE &&
                records[1].friday == SA_UNAVAILABLE &&
                records[1].saturday == SA_AVAILABLE &&
                records[1].sunday == SA_AVAILABLE &&
                !strcmp(records[1].start_date, "20070101") &&
                !strcmp(records[1].end_date, "20101231")
            )) {
                printf("Parsed calendar records file record 2 incorrectly!");
            }

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_fare_attributes() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/fare_attributes.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/fare_attributes.txt` file");
        } else {
            fare_attributes_t *records;
            int record_count = read_all_fare_attributes(fp, &records);

            if (record_count != 2) {
                printf("Number of records parsed from fare attributes file is incorrect");
            }

            if (!(
                !strcmp(records[0].fare_id, "p") &&
                records[0].price == 1.25 &&
                !strcmp(records[0].currency_type, "USD") &&
                records[0].payment_method == PM_ON_BOARD &&
                records[0].transfers == TS_NOT_ALLOWED &&
                records[0].transfer_duration == 0
            )) {
                printf("Parsed fare attributes file record 1 incorrectly!");
            }

            if (!(
                !strcmp(records[1].fare_id, "a") &&
                records[1].price == 5.25 &&
                !strcmp(records[1].currency_type, "USD") &&
                records[1].payment_method == PM_ON_BOARD &&
                records[1].transfers == TS_NOT_ALLOWED &&
                records[1].transfer_duration == 0
            )) {
                printf("Parsed fare attributes file record 2 incorrectly!");
            }

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_fare_rules() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/fare_rules.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/fare_rules.txt` file");
        } else {
            fare_rule_t *records;
            int record_count = read_all_fare_rules(fp, &records);

            if (record_count != 4) {
                printf("Number of records parsed from fare rules file is incorrect");
            }

            if (!(
                !strcmp(records[0].fare_id, "p") &&
                !strcmp(records[0].route_id, "AB") &&
                !strcmp(records[0].origin_id, "") &&
                !strcmp(records[0].destination_id, "") &&
                !strcmp(records[0].contains_id, "")
            )) {
                printf("Parsed fare rules file record 1 incorrectly!");
            }

            if (!(
                !strcmp(records[1].fare_id, "p") &&
                !strcmp(records[1].route_id, "STBA") &&
                !strcmp(records[1].origin_id, "") &&
                !strcmp(records[1].destination_id, "") &&
                !strcmp(records[1].contains_id, "")
            )) {
                printf("Parsed fare rules file record 2 incorrectly!");
            }

            if (!(
                !strcmp(records[2].fare_id, "p") &&
                !strcmp(records[2].route_id, "BFC") &&
                !strcmp(records[2].origin_id, "") &&
                !strcmp(records[2].destination_id, "") &&
                !strcmp(records[2].contains_id, "")
            )) {
                printf("Parsed fare rules file record 3 incorrectly!");
            }

            if (!(
                !strcmp(records[3].fare_id, "a") &&
                !strcmp(records[3].route_id, "AAMV") &&
                !strcmp(records[3].origin_id, "") &&
                !strcmp(records[3].destination_id, "") &&
                !strcmp(records[3].contains_id, "")
            )) {
                printf("Parsed fare rules file record 4 incorrectly!");
            }

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_frequencies() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/frequencies.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/frequencies.txt` file");
        } else {
            frequency_t *records;
            int record_count = read_all_frequencies(fp, &records);

            if (record_count != 11) {
                printf("Number of records parsed from frequencies file is incorrect");
            }

            if (!(
                !strcmp(records[0].trip_id, "STBA") &&
                !strcmp(records[0].start_time, "6:00:00") &&
                !strcmp(records[0].end_time, "22:00:00") &&
                records[0].headway_secs == 1800
            )) {
                printf("Parsed frequencies file record 1 incorrectly!");
            }

            if (!(
                !strcmp(records[1].trip_id, "CITY1") &&
                !strcmp(records[1].start_time, "6:00:00") &&
                !strcmp(records[1].end_time, "7:59:59") &&
                records[1].headway_secs == 1800
            )) {
                printf("Parsed frequencies file record 2 incorrectly!");
            }

            if (!(
                !strcmp(records[2].trip_id, "CITY2") &&
                !strcmp(records[2].start_time, "6:00:00") &&
                !strcmp(records[2].end_time, "7:59:59") &&
                records[2].headway_secs == 1800
            )) {
                printf("Parsed frequencies file record 3 incorrectly!");
            }

            if (!(
                !strcmp(records[3].trip_id, "CITY1") &&
                !strcmp(records[3].start_time, "8:00:00") &&
                !strcmp(records[3].end_time, "9:59:59") &&
                records[3].headway_secs == 600
            )) {
                printf("Parsed frequencies file record 4 incorrectly!");
            }

            if (!(
                !strcmp(records[4].trip_id, "CITY2") &&
                !strcmp(records[4].start_time, "8:00:00") &&
                !strcmp(records[4].end_time, "9:59:59") &&
                records[4].headway_secs == 600
            )) {
                printf("Parsed frequencies file record 5 incorrectly!");
            }

            if (!(
                !strcmp(records[5].trip_id, "CITY1") &&
                !strcmp(records[5].start_time, "10:00:00") &&
                !strcmp(records[5].end_time, "15:59:59") &&
                records[5].headway_secs == 1800
            )) {
                printf("Parsed frequencies file record 6 incorrectly!");
            }

            if (!(
                !strcmp(records[6].trip_id, "CITY2") &&
                !strcmp(records[6].start_time, "10:00:00") &&
                !strcmp(records[6].end_time, "15:59:59") &&
                records[6].headway_secs == 1800
            )) {
                printf("Parsed frequencies file record 7 incorrectly!");
            }

            if (!(
                !strcmp(records[7].trip_id, "CITY1") &&
                !strcmp(records[7].start_time, "16:00:00") &&
                !strcmp(records[7].end_time, "18:59:59") &&
                records[7].headway_secs == 600
            )) {
                printf("Parsed frequencies file record 8 incorrectly!");
            }

            if (!(
                !strcmp(records[8].trip_id, "CITY2") &&
                !strcmp(records[8].start_time, "16:00:00") &&
                !strcmp(records[8].end_time, "18:59:59") &&
                records[8].headway_secs == 600
            )) {
                printf("Parsed frequencies file record 9 incorrectly!");
            }

            if (!(
                !strcmp(records[9].trip_id, "CITY1") &&
                !strcmp(records[9].start_time, "19:00:00") &&
                !strcmp(records[9].end_time, "22:00:00") &&
                records[9].headway_secs == 1800
            )) {
                printf("Parsed frequencies file record 10 incorrectly!");
            }

            if (!(
                !strcmp(records[10].trip_id, "CITY2") &&
                !strcmp(records[10].start_time, "19:00:00") &&
                !strcmp(records[10].end_time, "22:00:00") &&
                records[10].headway_secs == 1800
            )) {
                printf("Parsed frequencies file record 11 incorrectly!");
            }

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_routes() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/routes.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/routes.txt` file");
        } else {
            route_t *records;
            int record_count = read_all_routes(fp, &records);

            if (record_count != 5) {
                printf("Number of records parsed from routes file is incorrect");
            }

            if (!(
                !strcmp(records[0].id, "AB") &&
                !strcmp(records[0].agency_id, "DTA") &&
                !strcmp(records[0].short_name, "10") &&
                !strcmp(records[0].long_name, "Airport - Bullfrog") &&
                !strcmp(records[0].desc, "") &&
                records[0].type == RT_BUS &&
                !strcmp(records[0].url, "") &&
                !strcmp(records[0].color, "") &&
                !strcmp(records[0].text_color, "")
            )) {
                printf("Parsed routes file record 1 incorrectly!");
            }

            if (!(
                !strcmp(records[1].id, "BFC") &&
                !strcmp(records[1].agency_id, "DTA") &&
                !strcmp(records[1].short_name, "20") &&
                !strcmp(records[1].long_name, "Bullfrog - Furnace Creek Resort") &&
                !strcmp(records[1].desc, "") &&
                records[1].type == RT_BUS &&
                !strcmp(records[1].url, "") &&
                !strcmp(records[1].color, "") &&
                !strcmp(records[1].text_color, "")
            )) {
                printf("Parsed routes file record 2 incorrectly!");
            }
            
            if (!(
                !strcmp(records[2].id, "STBA") &&
                !strcmp(records[2].agency_id, "DTA") &&
                !strcmp(records[2].short_name, "30") &&
                !strcmp(records[2].long_name, "Stagecoach - Airport Shuttle") &&
                !strcmp(records[2].desc, "") &&
                records[2].type == RT_BUS &&
                !strcmp(records[2].url, "") &&
                !strcmp(records[2].color, "") &&
                !strcmp(records[2].text_color, "")
            )) {
                printf("Parsed routes file record 3 incorrectly!");
            }

            if (!(
                !strcmp(records[3].id, "CITY") &&
                !strcmp(records[3].agency_id, "DTA") &&
                !strcmp(records[3].short_name, "40") &&
                !strcmp(records[3].long_name, "City") &&
                !strcmp(records[3].desc, "") &&
                records[3].type == RT_BUS &&
                !strcmp(records[3].url, "") &&
                !strcmp(records[3].color, "") &&
                !strcmp(records[3].text_color, "")
            )) {
                printf("Parsed routes file record 4 incorrectly!");
            }

            if (!(
                !strcmp(records[4].id, "AAMV") &&
                !strcmp(records[4].agency_id, "DTA") &&
                !strcmp(records[4].short_name, "50") &&
                !strcmp(records[4].long_name, "Airport - Amargosa Valley") &&
                !strcmp(records[4].desc, "") &&
                records[4].type == RT_BUS &&
                !strcmp(records[4].url, "") &&
                !strcmp(records[4].color, "") &&
                !strcmp(records[4].text_color, "")
            )) {
                printf("Parsed routes file record 5 incorrectly!");
            }

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_shapes() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/shapes.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/shapes.txt` file");
        } else {
            shape_t *records;
            int record_count = read_all_shapes(fp, &records);

            if (record_count != 0) {
                printf("Number of records parsed from shapes file is incorrect");
            }

            // TODO: add some test for this case and this reader

            if (record_count > 0) free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_stop_times() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/stop_times.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/stop_times.txt` file");
        } else {
            stop_time_t *records;
            int record_count = read_all_stop_times(fp, &records);

            if (record_count != 28) {
                printf("Number of records parsed from stop times file is incorrect");
            }

            if (!(
                !strcmp(records[0].trip_id, "STBA") &&
                !strcmp(records[0].arrival_time, "6:00:00") &&
                !strcmp(records[0].departure_time, "6:00:00") &&
                !strcmp(records[0].stop_id, "STAGECOACH") &&
                records[0].stop_sequence == 1 &&
                !strcmp(records[0].stop_headsign, "") &&
                records[0].pickup_type == ST_REGULAR &&
                records[0].dropoff_type == ST_REGULAR &&
                records[0].shape_dist_traveled == 0
            )) {
                printf("Parsed stop times file record 1 incorrectly!");
            }

            if (!(
                !strcmp(records[1].trip_id, "STBA") &&
                !strcmp(records[1].arrival_time, "6:20:00") &&
                !strcmp(records[1].departure_time, "6:20:00") &&
                !strcmp(records[1].stop_id, "BEATTY_AIRPORT") &&
                records[1].stop_sequence == 2 &&
                !strcmp(records[1].stop_headsign, "") &&
                records[1].pickup_type == ST_REGULAR &&
                records[1].dropoff_type == ST_REGULAR &&
                records[1].shape_dist_traveled == 0
            )) {
                printf("Parsed stop times file record 2 incorrectly!");
            }

            if (!(
                !strcmp(records[2].trip_id, "CITY1") &&
                !strcmp(records[2].arrival_time, "6:00:00") &&
                !strcmp(records[2].departure_time, "6:00:00") &&
                !strcmp(records[2].stop_id, "STAGECOACH") &&
                records[2].stop_sequence == 1 &&
                !strcmp(records[2].stop_headsign, "") &&
                records[2].pickup_type == ST_REGULAR &&
                records[2].dropoff_type == ST_REGULAR &&
                records[2].shape_dist_traveled == 0
            )) {
                printf("Parsed stop times file record 3 incorrectly!");
            }

            // and further on

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_stops() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/stops.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/stops.txt` file");
        } else {
            stop_t *records;
            int record_count = read_all_stops(fp, &records);

            if (record_count != 9) {
                printf("Number of records parsed from stops file is incorrect");
            }

            if (!(
                !strcmp(records[0].id, "FUR_CREEK_RES") &&
                !strcmp(records[0].name, "Furnace Creek Resort (Demo)") &&
                !strcmp(records[0].desc, "") &&
                records[0].lat == 36.425288 &&
                records[0].lon == -117.133162 &&
                !strcmp(records[0].zone_id, "") &&
                !strcmp(records[0].url, "")
            )) {
                printf("Parsed stops file record 1 incorrectly!");
            }

            if (!(
                !strcmp(records[1].id, "BEATTY_AIRPORT") &&
                !strcmp(records[1].name, "Nye County Airport (Demo)") &&
                !strcmp(records[1].desc, "") &&
                records[1].lat == 36.868446 &&
                records[1].lon == -116.784582 &&
                !strcmp(records[1].zone_id, "") &&
                !strcmp(records[1].url, "")
            )) {
                printf("Parsed stops file record 2 incorrectly!");
            }

            if (!(
                !strcmp(records[2].id, "BULLFROG") &&
                !strcmp(records[2].name, "Bullfrog (Demo)") &&
                !strcmp(records[2].desc, "") &&
                records[2].lat == 36.88108 &&
                records[2].lon == -116.81797 &&
                !strcmp(records[2].zone_id, "") &&
                !strcmp(records[2].url, "")
            )) {
                printf("Parsed stops file record 3 incorrectly!");
            }

            // and further on

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

int test_reading_all_trips() {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/google_sample/trips.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/google_sample/trips.txt` file");
        } else {
            trip_t *records;
            int record_count = read_all_trips(fp, &records);

            if (record_count != 11) {
                printf("Number of records parsed from trips file is incorrect");
            }

            if (!(
                !strcmp(records[0].route_id, "AB") &&
                !strcmp(records[0].service_id, "FULLW") &&
                !strcmp(records[0].trip_id, "AB1") &&
                !strcmp(records[0].headsign, "to Bullfrog") &&
                records[0].direction_id == 0 &&
                !strcmp(records[0].block_id, "1") &&
                !strcmp(records[0].shape_id, "")
            )) {
                printf("Parsed trips file record 1 incorrectly!");
            }

            if (!(
                !strcmp(records[1].route_id, "AB") &&
                !strcmp(records[1].service_id, "FULLW") &&
                !strcmp(records[1].trip_id, "AB2") &&
                !strcmp(records[1].headsign, "to Airport") &&
                records[1].direction_id == 1 &&
                !strcmp(records[1].block_id, "2") &&
                !strcmp(records[1].shape_id, "")
            )) {
                printf("Parsed trips file record 2 incorrectly!");
            }

            if (!(
                !strcmp(records[2].route_id, "STBA") &&
                !strcmp(records[2].service_id, "FULLW") &&
                !strcmp(records[2].trip_id, "STBA") &&
                !strcmp(records[2].headsign, "Shuttle") &&
                records[2].direction_id == 0 &&
                !strcmp(records[2].block_id, "") &&
                !strcmp(records[2].shape_id, "")
            )) {
                printf("Parsed trips file record 3 incorrectly!");
            }

            // and further on

            free(records);
            fclose(fp);
        }
    }
    return 0;
}

#endif