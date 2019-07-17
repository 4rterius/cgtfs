#include "records/level.h"

void init_level(level_t *record) {
    strcpy(record->id, "");
    strcpy(record->name, "");
    record->index = 0.0;
    record->is_null = 1;
}

void read_level(level_t *record, int field_count, const char **field_names, const char **field_values) {
    init_level(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "level_id") == 0) {
            strcpy(record->id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "level_index") == 0) {
            record->index = strtod(field_values[i], NULL);
            continue;
        }
        if (strcmp(field_names[i], "level_name") == 0) {
            strcpy(record->name, field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}

int equal_level(const level_t *a, const level_t *b) {
    return !(!strcmp(a->id, b->id) &&
             !strcmp(a->name, b->name) &&
             a->index == b->index);
}