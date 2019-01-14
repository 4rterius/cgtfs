#include "records/route.h"

route_type_t parse_route_type(const char *value) {
    if (strcmp(value, "0") == 0)
        return RT_STREET_LEVEL;
    else if (strcmp(value, "1") == 0)
        return RT_UNDERGROUND;
    else if (strcmp(value, "2") == 0)
        return RT_LONG_RAIL;
    else if (strcmp(value, "3") == 0)
        return RT_BUS;
    else if (strcmp(value, "4") == 0)
        return RT_FERRY;
    else if (strcmp(value, "5") == 0)
        return RT_CABLE_CAR;
    else if (strcmp(value, "6") == 0)
        return RT_SUSPENDED;
    else if (strcmp(value, "7") == 0)
        return RT_FUNICULAR;
    else
        return RT_NOT_SET;
}

void init_route(route_t *record) {
    strcpy(record->id, "");
    strcpy(record->agency_id, "");
    strcpy(record->short_name, "");
    strcpy(record->long_name, "");
    strcpy(record->desc, "");
    record->type = RT_NOT_SET; 
    strcpy(record->url, "");
    strcpy(record->color, "");
    strcpy(record->text_color, "");
    record->sort_order = 0;
    record->is_null = 1;
}

void read_route(route_t *record, int field_count, const char **field_names, const char **field_values) {
    init_route(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(record->id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(record->agency_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_short_name") == 0) {
            strcpy(record->short_name, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_long_name") == 0) {
            strcpy(record->long_name, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_desc") == 0) {
            strcpy(record->desc, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_type") == 0) {
            record->type = parse_route_type(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_url") == 0) {
            strcpy(record->url, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_color") == 0) {
            strcpy(record->color, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_text_color") == 0) {
            strcpy(record->text_color, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_sort_order") == 0) {
            record->sort_order = (int)strtol(field_values[i], NULL, 0);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}