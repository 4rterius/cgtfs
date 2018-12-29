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

            if (!(
                !strcmp(records[0].id, "DTA") &&
                !strcmp(records[0].name, "Demo Transit Authority") &&
                !strcmp(records[0].url, "http://google.com") &&
                !strcmp(records[0].timezone, "America/Los_Angeles")
            )) {
                printf("Parsed agency file record 1 incorrectly!");
            }
            free(records);
        }
        fclose(fp);
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

            if (!(
                !strcmp(records[0].service_id, "FULLW") &&
                !strcmp(records[0].date, "20070604") &&
                records[0].exception_type == ET_REMOVED
            )) {
                printf("Parsed calendar dates file record 1 incorrectly!");
            }
            free(records);
        }
        fclose(fp);
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
        }
        fclose(fp);
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
        }
        fclose(fp);
    }
    return 0;
}

#endif