#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "reading_utils.h"

int read_agencies(FILE *fp, agency_t **agencies) {

    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    int record_count = 0;
    char **record_values;
    while(read_a_record(fp, field_count, &record_values) > 0) {
        record_count++;
        for (int i = 0; i < field_count; i++)
            printf("%s | ", record_values[i]);
        printf("\n");
    }

    return record_count;
}