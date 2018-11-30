#include <assert.h>
#include <stdio.h>

#include "_utils.c"

#include "reading.h"

int test_reading_agencies_correct() {
    FILE *fp = fopen("../tests/data/agency.txt", "r");
    if (fp == NULL) {
        perror("Couldn't open `data/agency.txt` file");
    } else {
        agency_t *agencies;
        int agency_count = read_agencies(fp, &agencies);

        if (agency_count != 4) {
            printf("Incorrect number of agencies: %i of %i", agency_count, 4);
        }

        if (!(
            (strcmp(agencies[0].id, "1") == 0) ||
            (strcmp(agencies[0].name, "Lahden Seudun Liikenne") == 0) ||
            (strcmp(agencies[0].url, "http://www.lsl.fi") == 0) ||
            (strcmp(agencies[0].timezone, "Europe/Helsinki") == 0) ||
            (strcmp(agencies[0].lang, "fi") == 0) ||
            (strcmp(agencies[0].phone, "03 814 2355") == 0)
        )) {
            printf("Agency 1 parsed incorrectly.");
        }

        if (!(
            (strcmp(agencies[2].id, "3") == 0) ||
            (strcmp(agencies[2].name, "") == 0) ||
            (strcmp(agencies[2].url, "") == 0) ||
            (strcmp(agencies[2].timezone, "") == 0) ||
            (strcmp(agencies[2].lang, "") == 0) ||
            (strcmp(agencies[2].phone, "") == 0)
        )) {
            printf("Agency 3 (empty) parsed incorrectly.");
        }

        if (!(
            (strcmp(agencies[3].id, "4") == 0) ||
            (strcmp(agencies[3].name, "djghasldföäånkl´+123sd") == 0) ||
            (strcmp(agencies[3].url, "http://www.lsl.fi") == 0) ||
            (strcmp(agencies[3].timezone, "blahblah") == 0) ||
            (strcmp(agencies[3].lang, "fi") == 0) ||
            (strcmp(agencies[3].phone, "03 814 2355") == 0)
        )) {
            printf("Agency 4 parsed incorrectly.");
        }
    }
    fclose(fp);
    return 0;
}