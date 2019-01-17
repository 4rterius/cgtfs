#include "records/frequency.h"

time_exactness_t parse_time_exactness(const char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return TE_NOT_EXACT;
    else if (strcmp(value, "1") == 0)
        return TE_EXACT;
    else
        return TE_NOT_SET;
}

void init_frequency(frequency_t *record) {
    strcpy(record->trip_id, "");
    strcpy(record->start_time, "");
    strcpy(record->end_time, "");
    record->headway_secs = 0;
    record->exact_times = TE_NOT_EXACT;
    record->is_null = 1;
}

void read_frequency(frequency_t *record, int field_count, const char **field_names, const char **field_values) {
    init_frequency(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "trip_id") == 0) {
            strcpy(record->trip_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "start_time") == 0) {
            strcpy(record->start_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "end_time") == 0) {
            strcpy(record->end_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "headway_secs") == 0) {
            record->headway_secs = (int)strtol(field_values[i], NULL, 0);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "exact_times") == 0) {
            record->exact_times = parse_time_exactness(field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}

int equal_frequency(const frequency_t *a, const frequency_t *b) {
    return !(!strcmp(a->trip_id, b->trip_id) &&
             !strcmp(a->start_time, b->start_time) &&
             !strcmp(a->end_time, b->end_time) &&
             a->headway_secs == b->headway_secs &&
             a->exact_times == b->exact_times);
}