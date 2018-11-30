#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "reading_utils.h"


int read_agencies(FILE *fp, agency_t **agencies) {
    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    while (read_one_record(fp, field_count, &record_values) > 0) {
        agency_t agency = make_agency(field_count, field_names, record_values);
        record_count++;
        // TODO: allocate memory in *agencies array and write a new agency there
    }

    return record_count;
}