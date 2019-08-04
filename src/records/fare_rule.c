#include "records/fare_rule.h"

void init_fare_rule(fare_rule_t *record) {
    strcpy(record->fare_id, "");
    strcpy(record->route_id, "");
    strcpy(record->origin_id, "");
    strcpy(record->destination_id, "");
    strcpy(record->contains_id, "");
}

void read_fare_rule(fare_rule_t *record, int field_count, const char **field_names, const char **field_values) {
    init_fare_rule(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "fare_id") == 0) {
            strcpy(record->fare_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(record->route_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "origin_id") == 0) {
            strcpy(record->origin_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "destination_id") == 0) {
            strcpy(record->destination_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "contains_id") == 0) {
            strcpy(record->contains_id, field_values[i]);
            continue;
        }
    }
}

int equal_fare_rule(const fare_rule_t *a, const fare_rule_t *b) {
    return !(!strcmp(a->fare_id, b->fare_id) &&
             !strcmp(a->route_id, b->route_id) &&
             !strcmp(a->origin_id, b->origin_id) &&
             !strcmp(a->destination_id, b->destination_id) &&
             !strcmp(a->contains_id, b->contains_id));
}