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
    
    *agencies = malloc(sizeof(agency_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *agencies = realloc(*agencies, (record_count + 1) * sizeof(agency_t));
        (*agencies)[record_count] = make_agency(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_calendar_records(FILE *fp, calendar_record_t **calendar_records) {
    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *calendar_records = malloc(sizeof(calendar_record_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *calendar_records = realloc(*calendar_records, (record_count + 1) * sizeof(agency_t));
        (*calendar_records)[record_count] = make_calendar_record(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}