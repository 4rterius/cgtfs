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
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(calendar_date_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_calendar_date(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_calendar_records(FILE *fp, calendar_record_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(calendar_record_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_calendar_record(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_fare_attributes(FILE *fp, fare_attributes_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(fare_attributes_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_fare_attributes(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_fare_rules(FILE *fp, fare_rule_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(fare_rule_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_fare_rule(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_feed_info(FILE *fp, feed_info_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(feed_info_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_feed_info(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_frequencies(FILE *fp, frequency_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(frequency_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_frequency(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_routes(FILE *fp, route_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(route_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_route(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_shapes(FILE *fp, shape_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(shape_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_shape(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_stop_times(FILE *fp, stop_time_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(stop_time_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_stop_time(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_stops(FILE *fp, stop_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(stop_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_stop(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_transfers(FILE *fp, transfer_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(transfer_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_transfer(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}

int read_all_trips(FILE *fp, trip_t **records) {
    char **record_values;
    int record_count = count_lines(fp) - 1;

    rewind(fp);
    char **field_names;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 0)
        return -1;

    *records = malloc(record_count * sizeof(trip_t));

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0)
            (*records)[i] = read_trip(field_count, field_names, record_values);
    }

    free(field_names);
    free(record_values);

    return record_count;
}