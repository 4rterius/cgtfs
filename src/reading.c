#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "reading_utils.h"


int read_all_agencies(FILE *fp, agency_t **records) {
    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(agency_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(agency_t));
        (*records)[record_count] = read_agency(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_calendar_dates(FILE *fp, calendar_date_t **records) {
    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(calendar_date_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(agency_t));
        (*records)[record_count] = read_calendar_date(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_calendar_records(FILE *fp, calendar_record_t **records) {
    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(calendar_record_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(agency_t));
        (*records)[record_count] = read_calendar_record(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_fare_attributes(FILE *fp, fare_attributes_t **records) {
    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(fare_attributes_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(agency_t));
        (*records)[record_count] = read_fare_attributes(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}