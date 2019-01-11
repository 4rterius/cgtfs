#include "shape.h"
#include <stdlib.h>

shape_t empty_shape(void) {
    shape_t shape;
    strcpy(shape.id, "");
    shape.pt_lat = 0.0;
    shape.pt_lon = 0.0;
    shape.pt_sequence = 0;
    shape.dist_traveled = 0;
    shape.is_null = 1;
    return shape;
}

shape_t read_shape(const int field_count, const char **field_names, const char **field_values) {
    shape_t shape = empty_shape();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "shape_id") == 0) {
            strcpy(shape.id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "shape_pt_lat") == 0) {
            shape.pt_lat = strtod(field_values[i], NULL);  // TODO: strtold not working, figure out why
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "shape_pt_lon") == 0) {
            shape.pt_lon = strtod(field_values[i], NULL);  // TODO: same as shape.c:26
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "shape_pt_sequence") == 0) {
            shape.pt_sequence = (unsigned int)strtoul(field_values[i], NULL, 0);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "shape_dist_traveled") == 0) {
            shape.dist_traveled = strtod(field_values[i], NULL);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        shape.is_null = 1;
    else
        shape.is_null = 0;
    
    return shape;
}