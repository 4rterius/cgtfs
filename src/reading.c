#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "file_utils.h"
#include "mem_utils.h"


int read_all_agencies(FILE *fp, agency_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_agency(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_calendar_dates(FILE *fp, calendar_date_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_calendar_date(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_calendar_records(FILE *fp, calendar_record_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_calendar_record(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_fare_attributes(FILE *fp, fare_attributes_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_fare_attributes(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_fare_rules(FILE *fp, fare_rule_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_fare_rule(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_feed_info(FILE *fp, feed_info_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_feed_info(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_frequencies(FILE *fp, frequency_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_frequency(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_levels(FILE *fp, level_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_level(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_pathways(FILE *fp, pathway_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_pathway(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_routes(FILE *fp, route_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_route(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_shapes(FILE *fp, shape_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_shape(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_stop_times(FILE *fp, stop_time_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_stop_time(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_stops(FILE *fp, stop_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_stop(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_transfers(FILE *fp, transfer_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_transfer(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int read_all_trips(FILE *fp, trip_t **records) {
    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);

    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }

    *records = malloc(lines_count * sizeof(**records));

    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_trip(&(*records)[i], field_count, (const char **)field_names, (const char **)record_values);
            // free_cstr_arr(record_values, field_count);
            record_count++;
        }
        free_cstr_arr(record_values, field_count);
    }

    if (record_count == 0)
        *records = realloc(*records, record_count * sizeof(**records));

    free_cstr_arr(field_names, field_count);
    return record_count;
}