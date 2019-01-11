#include "frequency.h"

time_exactness_t parse_time_exactness(const char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return TE_NOT_EXACT;
    else if (strcmp(value, "1") == 0)
        return TE_EXACT;
    else
        return TE_NOT_SET;
}

frequency_t empty_frequency(void) {
    frequency_t frequency;
    strcpy(frequency.trip_id, "");
    strcpy(frequency.start_time, "");
    strcpy(frequency.end_time, "");
    frequency.headway_secs = 0;
    frequency.exact_times = TE_NOT_EXACT;
    frequency.is_null = 1;
    return frequency;
}

frequency_t read_frequency(const int field_count, const char **field_names, const char **field_values) {
    frequency_t frequency = empty_frequency();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "trip_id") == 0) {
            strcpy(frequency.trip_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "start_time") == 0) {
            strcpy(frequency.start_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "end_time") == 0) {
            strcpy(frequency.end_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "headway_secs") == 0) {
            frequency.headway_secs = (int)strtol(field_values[i], NULL, 0);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "exact_times") == 0) {
            frequency.exact_times = parse_time_exactness(field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        frequency.is_null = 1;
    else
        frequency.is_null = 0;
    
    return frequency;
}