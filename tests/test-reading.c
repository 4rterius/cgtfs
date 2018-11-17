#include <assert.h>
#include <stdio.h>

#include "_utils.c"

#include "reading.h"

int test_reading_agencies_correct() {
    FILE *fp = fopen("../tests/data/agency.txt", "r");
    if (fp == NULL) {
        perror("Couldn't open `data/agency.txt` file");
    } else {
        agency_t *a;
        read_agencies(fp, &a);
    }
    fclose(fp);
    return 0;
}