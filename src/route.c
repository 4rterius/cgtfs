#include "route.h"

route_type_t parse_route_type(char *value) {
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

route_t empty_route(void) {
    route_t route;
    strcpy(route.id, "");
    strcpy(route.agency_id, "");
    strcpy(route.short_name, "");
    strcpy(route.long_name, "");
    strcpy(route.desc, "");
    route.type = RT_NOT_SET; 
    strcpy(route.url, "");
    strcpy(route.color, "");
    strcpy(route.text_color, "");
    route.sort_order = 0;
    route.is_null = 1;
    return route;
}

route_t read_route(int field_count, char **field_names, char **field_values) {
    route_t route = empty_route();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(route.id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(route.agency_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_short_name") == 0) {
            strcpy(route.short_name, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_long_name") == 0) {
            strcpy(route.long_name, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_desc") == 0) {
            strcpy(route.desc, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_type") == 0) {
            route.type = parse_route_type(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_url") == 0) {
            strcpy(route.url, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_color") == 0) {
            strcpy(route.color, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_text_color") == 0) {
            strcpy(route.text_color, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "route_sort_order") == 0) {
            route.sort_order = (int)strtol(field_values[i], NULL, 0);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        route.is_null = 1;
    else
        route.is_null = 0;
    
    return route;
}