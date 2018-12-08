#include "fare_rule.h"

fare_rule_t empty_fare_rule(void) {
    fare_rule_t fare_rule;
    strcpy(fare_rule.fare_id, "");
    strcpy(fare_rule.route_id, "");
    strcpy(fare_rule.origin_id, "");
    strcpy(fare_rule.destination_id, "");
    strcpy(fare_rule.contains_id, "");
    fare_rule.is_null = 1;
    return fare_rule;
}

fare_rule_t read_fare_rule(int field_count, char **field_names, char **field_values) {
    fare_rule_t fare_rule = empty_fare_rule();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "fare_id") == 0) {
            strcpy(fare_rule.fare_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(fare_rule.route_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "origin_id") == 0) {
            strcpy(fare_rule.origin_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "destination_id") == 0) {
            strcpy(fare_rule.destination_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "contains_id") == 0) {
            strcpy(fare_rule.contains_id, field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        fare_rule.is_null = 1;
    else
        fare_rule.is_null = 0;

    return fare_rule;
}