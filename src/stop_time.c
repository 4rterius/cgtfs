#include "records/stop_time.h"

stop_type_t parse_stop_type(const char *value) {
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

timepoint_precision_t parse_timepoint_precision(const char *value) {
    if (strcmp(value, "0") == 0)
        return TP_APPROXIMATE;
    else if (strcmp(value, "1") == 0 || strcmp(value, "") == 0)
        return TP_EXACT;
    else
        return TP_NOT_SET;
}

void init_stop_time(stop_time_t *record) {
    strcpy(record->trip_id, "");
    strcpy(record->arrival_time, "");
    strcpy(record->departure_time, "");
    strcpy(record->stop_id, "");
    record->stop_sequence = 0;
    strcpy(record->stop_headsign, "");
    record->pickup_type = ST_REGULAR;
    record->dropoff_type = ST_REGULAR;
    record->shape_dist_traveled = 0.0;
    record->timepoint = TP_EXACT;
    record->is_null = 1;
}

void read_stop_time(stop_time_t *record, int field_count, const char **field_names, const char **field_values) {
    init_stop_time(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "trip_id") == 0) {
            strcpy(record->trip_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "arrival_time") == 0) {
            strcpy(record->arrival_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "departure_time") == 0) {
            strcpy(record->departure_time, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_id") == 0) {
            strcpy(record->stop_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_sequence") == 0) {
            record->stop_sequence = (unsigned int)strtoul(field_values[i], NULL, 0);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "stop_headsign") == 0) {
            strcpy(record->stop_headsign, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "pickup_type") == 0) {
            record->pickup_type = parse_stop_type(field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "drop_off_type") == 0) {
            record->dropoff_type = parse_stop_type(field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "shape_dist_traveled") == 0) {
            record->shape_dist_traveled = strtod(field_values[i], NULL);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "timepoint") == 0) {
            record->timepoint = parse_timepoint_precision(field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}
