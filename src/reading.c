#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "reading_utils.h"

int read_agencies(FILE *fp, agency_t **agencies) {

    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    char ***record_values;
    int record_count = read_records(fp, &record_values);

    return record_count;
}