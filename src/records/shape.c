#include <stdlib.h>
#include "records/shape.h"

void init_shape(shape_t *record) {
    strcpy(record->id, "");
    record->pt_lat = 0.0;
    record->pt_lon = 0.0;
    record->pt_sequence = 0;
    record->dist_traveled = 0;
}

void read_shape(shape_t *record, int field_count, const char **field_names, const char **field_values) {
    init_shape(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "shape_id") == 0) {
            strcpy(record->id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "shape_pt_lat") == 0) {
            record->pt_lat = strtod(field_values[i], NULL);  // TODO: strtold not working, figure out why
            continue;
        }
        if (strcmp(field_names[i], "shape_pt_lon") == 0) {
            record->pt_lon = strtod(field_values[i], NULL);  // TODO: same as record->c:26
            continue;
        }
        if (strcmp(field_names[i], "shape_pt_sequence") == 0) {
            record->pt_sequence = (unsigned int)strtoul(field_values[i], NULL, 0);
            continue;
        }
        if (strcmp(field_names[i], "shape_dist_traveled") == 0) {
            record->dist_traveled = strtod(field_values[i], NULL);
            continue;
        }
    }
}

int equal_shape(const shape_t *a, const shape_t *b) {
    return (!strcmp(a->id, b->id) &&
             a->pt_lat == b->pt_lat &&
             a->pt_lon == b->pt_lon &&
             a->pt_sequence == b->pt_sequence &&
             a->dist_traveled == b->dist_traveled);
}
