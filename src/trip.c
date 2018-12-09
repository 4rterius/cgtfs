#include "trip.h"

wheelchair_accessible_t parse_wheelchair_accessibility(char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return WA_UNKNOWN;
    else if (strcmp(value, "1") == 0)
        return WA_POSSIBLE;
    else if (strcmp(value, "2") == 0)
        return WA_NOT_POSSIBLE;
    else
        return WA_NOT_SET;
}

bikes_allowed_t parse_bike_allowance(char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return BA_UNKNOWN;
    else if (strcmp(value, "1") == 0)
        return BA_POSSIBLE;
    else if (strcmp(value, "2") == 0)
        return BA_NOT_POSSIBLE;
    else
        return BA_NOT_SET;
}

trip_t empty_trip(void) {
    trip_t trip;
    strcpy(trip.route_id, "");
    strcpy(trip.service_id, "");
    strcpy(trip.trip_id, "");
    strcpy(trip.headsign, "");
    strcpy(trip.short_name, "");
    trip.direction_id = 0;
    strcpy(trip.block_id, "");
    strcpy(trip.shape_id, "");
    trip.wheelchair_accessible = WA_UNKNOWN;
    trip.bikes_allowed = BA_UNKNOWN;
    trip.is_null = 1;
    return trip;
}

trip_t read_trip(int field_count, char **field_names, char **field_values) {
    trip_t trip = empty_trip();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(trip.route_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "service_id") == 0) {
            strcpy(trip.service_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "trip_id") == 0) {
            strcpy(trip.trip_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "trip_headsign") == 0) {
            strcpy(trip.headsign, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "trip_short_name") == 0) {
            strcpy(trip.short_name, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "direction_id") == 0) {
            trip.direction_id = (unsigned int)strtoul(field_values[i], NULL, 0);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "block_id") == 0) {
            strcpy(trip.block_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "shape_id") == 0) {
            strcpy(trip.shape_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "wheelchair_accessible") == 0) {
            trip.wheelchair_accessible = parse_wheelchair_accessibility(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "bikes_allowed") == 0) {
            trip.bikes_allowed = parse_bike_allowance(field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        trip.is_null = 1;
    else
        trip.is_null = 0;
    
    return trip;
}