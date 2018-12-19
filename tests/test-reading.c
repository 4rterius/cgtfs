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
            free(records);
        }
        fclose(fp);
    }
    return 0;
}

#endif