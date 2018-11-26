#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "reading_utils.h"

int rd_cb(int line_num, int field_count, char **record_vals) {
    printf("%i: ", line_num);
    for (int i = 0; i < field_count; i++)
        printf("%s  ", record_vals[i]);
    printf("\n");
    return 0;
}

int read_agencies(FILE *fp, agency_t **agencies) {
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    char **record_values;
    int record_count = 0;

    while (read_one_record(fp, field_count, &record_values) > 0) {
        // f(record_values);
        record_count++;
    }

    return record_count;
}