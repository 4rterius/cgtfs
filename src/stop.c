#include "stop.h"

location_type_t parse_location_type(char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return LT_STOP;
    else if (strcmp(value, "1") == 0)
        return LT_STATION;
    else if (strcmp(value, "2") == 0)
        return LT_STATION_ENTRANCE_EXIT;
    else
        return LT_NOT_SET;
}

wheelchair_boarding_t parse_wheelchair_boarding(char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return WB_UNKNOWN_OR_INHERITED;
    else if (strcmp(value, "1") == 0)
        return WB_SOME;
    else if (strcmp(value, "2") == 0)
        return WB_NOT_POSSIBLE;
    else
        return WB_NOT_SET;
}

stop_t empty_stop(void) {
    stop_t stop;
    strcpy(stop.id, "");
    strcpy(stop.code, "");
    strcpy(stop.name, "");
    strcpy(stop.desc, "");
    stop.lat = 0.0;
    stop.lon = 0.0;
    strcpy(stop.zone_id, "");
    strcpy(stop.url, "");
    stop.location_type = LT_STOP;
    strcpy(stop.parent_station, "");
    strcpy(stop.timezone, "");
    stop.wheelchair_boarding = WB_UNKNOWN_OR_INHERITED;
    stop.is_null = 1;
    return stop;
}

stop_t read_stop(int field_count, char **field_names, char **field_values) {
    stop_t stop = empty_stop();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "stop_id") == 0) {
            strcpy(stop.id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_code") == 0) {
            strcpy(stop.code, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_name") == 0) {
            strcpy(stop.name, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_desc") == 0) {
            strcpy(stop.desc, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_lat") == 0) {
            stop.lat = strtold(field_values[i], NULL);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_lon") == 0) {
            stop.lon = strtold(field_values[i], NULL);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "zone_id") == 0) {
            strcpy(stop.zone_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_url") == 0) {
            strcpy(stop.url, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "location_type") == 0) {
            stop.location_type = parse_location_type(field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "parent_station") == 0) {
            strcpy(stop.parent_station, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_timezone") == 0) {
            strcpy(stop.timezone, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "wheelchair_boarding") == 0) {
            stop.wheelchair_boarding = parse_wheelchair_boarding(field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        stop.is_null = 1;
    else
        stop.is_null = 0;
    
    return stop;
}