#include "stop_time.h"

stop_type_t parse_stop_type(char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return ST_REGULAR;
    else if (strcmp(value, "1") == 0)
        return ST_NOT_AVAILABLE;
    else if (strcmp(value, "2") == 0)
        return ST_CONTACT_AGENCY;
    else if (strcmp(value, "3") == 0)
        return ST_CONTACT_DRIVER;
    else
        return ST_NOT_SET;
}

timepoint_precision_t parse_timepoint_precision(char *value) {
    if (strcmp(value, "0") == 0)
        return TP_APPROXIMATE;
    else if (strcmp(value, "1") == 0 || strcmp(value, "") == 0)
        return TP_EXACT;
    else
        return TP_NOT_SET;
}

stop_time_t empty_stop_time(void) {
    stop_time_t stop_time;
    strcpy(stop_time.trip_id, "");
    strcpy(stop_time.arrival_time, "");
    strcpy(stop_time.departure_time, "");
    strcpy(stop_time.stop_id, "");
    stop_time.stop_sequence = 0;
    strcpy(stop_time.stop_headsign, "");
    stop_time.pickup_type = ST_REGULAR;
    stop_time.dropoff_type = ST_REGULAR;
    stop_time.shape_dist_traveled = 0.0;
    stop_time.timepoint = TP_EXACT;
    stop_time.is_null = 1;
    return stop_time;
}

stop_time_t read_stop_time(int field_count, char **field_names, char **field_values) {
    stop_time_t stop_time;
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "trip_id") == 0) {
            strcpy(stop_time.trip_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "arrival_time") == 0) {
            strcpy(stop_time.arrival_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "departure_time") == 0) {
            strcpy(stop_time.departure_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_id") == 0) {
            strcpy(stop_time.stop_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_sequence") == 0) {
            stop_time.stop_sequence = (unsigned int)strtoul(field_values[i], NULL, 0);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_headsign") == 0) {
            strcpy(stop_time.stop_headsign, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "pickup_type") == 0) {
            stop_time.pickup_type = parse_stop_type(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "drop_off_type") == 0) {
            stop_time.dropoff_type = parse_stop_type(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "shape_dist_traveled") == 0) {
            stop_time.shape_dist_traveled = strtod(field_values[i], NULL);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "timepoint") == 0) {
            stop_time.timepoint = parse_timepoint_precision(field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        stop_time.is_null = 1;
    else
        stop_time.is_null = 0;

    return stop_time;
}
