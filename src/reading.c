#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "reading_utils.h"


int read_all_agencies(FILE *fp, agency_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(agency_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_agency(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_calendar_dates(FILE *fp, calendar_date_t **records) {
    
    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(calendar_date_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(calendar_date_t));
        (*records)[record_count] = read_calendar_date(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_calendar_records(FILE *fp, calendar_record_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(calendar_record_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(calendar_record_t));
        (*records)[record_count] = read_calendar_record(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_fare_attributes(FILE *fp, fare_attributes_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(fare_attributes_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(fare_attributes_t));
        (*records)[record_count] = read_fare_attributes(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_fare_rules(FILE *fp, fare_rule_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(fare_rule_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(fare_rule_t));
        (*records)[record_count] = read_fare_rule(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_feed_info(FILE *fp, feed_info_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(feed_info_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(feed_info_t));
        (*records)[record_count] = read_feed_info(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_frequencies(FILE *fp, frequency_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(frequency_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(frequency_t));
        (*records)[record_count] = read_frequency(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_routes(FILE *fp, route_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(route_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(route_t));
        (*records)[record_count] = read_route(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_shapes(FILE *fp, shape_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(shape_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(shape_t));
        (*records)[record_count] = read_shape(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_stop_times(FILE *fp, stop_time_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(stop_time_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(stop_time_t));
        (*records)[record_count] = read_stop_time(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_stops(FILE *fp, stop_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(stop_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(stop_t));
        (*records)[record_count] = read_stop(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_transfers(FILE *fp, transfer_t **records) {

    rewind(fp);

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(transfer_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(transfer_t));
        (*records)[record_count] = read_transfer(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_trips(FILE *fp, trip_t **records) {

    rewind(fp);
    
    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    int record_count = 0;
    
    *records = malloc(sizeof(trip_t));
    
    while (read_record(fp, field_count, &record_values) > 0) {
        *records = realloc(*records, (record_count + 1) * sizeof(trip_t));
        (*records)[record_count] = read_trip(field_count, field_names, record_values);
        record_count++;
    }

    free(field_names);
    free(record_values);

    return record_count;
}