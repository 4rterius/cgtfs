#include "fare_rule.h"

void init_fare_rule(fare_rule_t *record) {
    strcpy(record->fare_id, "");
    strcpy(record->route_id, "");
    strcpy(record->origin_id, "");
    strcpy(record->destination_id, "");
    strcpy(record->contains_id, "");
    record->is_null = 1;
}

void read_fare_rule(fare_rule_t *record, int field_count, const char **field_names, const char **field_values) {
    init_fare_rule(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "fare_id") == 0) {
            strcpy(record->fare_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(record->route_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "origin_id") == 0) {
            strcpy(record->origin_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "destination_id") == 0) {
            strcpy(record->destination_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "contains_id") == 0) {
            strcpy(record->contains_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}