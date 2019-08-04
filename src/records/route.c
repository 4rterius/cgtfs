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
}

void read_route(route_t *record, int field_count, const char **field_names, const char **field_values) {
    init_route(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(record->id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(record->agency_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_short_name") == 0) {
            strcpy(record->short_name, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_long_name") == 0) {
            strcpy(record->long_name, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_desc") == 0) {
            strcpy(record->desc, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_type") == 0) {
            record->type = parse_route_type(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_url") == 0) {
            strcpy(record->url, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_color") == 0) {
            strcpy(record->color, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_text_color") == 0) {
            strcpy(record->text_color, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "route_sort_order") == 0) {
            record->sort_order = (int)strtol(field_values[i], NULL, 0);
            continue;
        }
    }
}

int equal_route(const route_t *a, const route_t *b) {
    return (!strcmp(a->id, b->id) &&
             !strcmp(a->agency_id, b->agency_id) &&
             !strcmp(a->short_name, b->short_name) &&
             !strcmp(a->long_name, b->long_name) &&
             !strcmp(a->desc, b->desc) &&
             !strcmp(a->url, b->url) &&
             !strcmp(a->color, b->color) &&
             !strcmp(a->text_color, b->text_color) &&
             a->type == b->type &&
             a->sort_order == b->sort_order);
}