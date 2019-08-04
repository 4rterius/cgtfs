#include "records/trip.h"

wheelchair_accessible_t parse_wheelchair_accessibility(const char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return WA_UNKNOWN;
    else if (strcmp(value, "1") == 0)
        return WA_POSSIBLE;
    else if (strcmp(value, "2") == 0)
        return WA_NOT_POSSIBLE;
    else
        return WA_NOT_SET;
}

bikes_allowed_t parse_bike_allowance(const char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return BA_UNKNOWN;
    else if (strcmp(value, "1") == 0)
        return BA_POSSIBLE;
    else if (strcmp(value, "2") == 0)
        return BA_NOT_POSSIBLE;
    else
        return BA_NOT_SET;
}

void init_trip(trip_t *record) {
    strcpy(record->route_id, "");
    strcpy(record->service_id, "");
    strcpy(record->id, "");
    strcpy(record->headsign, "");
    strcpy(record->short_name, "");
    record->direction_id = 0;
    strcpy(record->block_id, "");
    strcpy(record->shape_id, "");
    record->wheelchair_accessible = WA_UNKNOWN;
    record->bikes_allowed = BA_UNKNOWN;
}

void read_trip(trip_t *record, int field_count, const char **field_names, const char **field_values) {
    init_trip(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "route_id") == 0) {
            strcpy(record->route_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "service_id") == 0) {
            strcpy(record->service_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "trip_id") == 0) {
            strcpy(record->id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "trip_headsign") == 0) {
            strcpy(record->headsign, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "trip_short_name") == 0) {
            strcpy(record->short_name, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "direction_id") == 0) {
            record->direction_id = (unsigned int)strtoul(field_values[i], NULL, 0);
            continue;
        }
        if (strcmp(field_names[i], "block_id") == 0) {
            strcpy(record->block_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "shape_id") == 0) {
            strcpy(record->shape_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "wheelchair_accessible") == 0) {
            record->wheelchair_accessible = parse_wheelchair_accessibility(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "bikes_allowed") == 0) {
            record->bikes_allowed = parse_bike_allowance(field_values[i]);
            continue;
        }
    }
}

int equal_trip(const trip_t *a, const trip_t *b) {
    return (!strcmp(a->route_id, b->route_id) &&
             !strcmp(a->service_id, b->service_id) &&
             !strcmp(a->id, b->id) &&
             !strcmp(a->headsign, b->headsign) &&
             !strcmp(a->short_name, b->short_name) &&
             !strcmp(a->block_id, b->block_id) &&
             !strcmp(a->shape_id, b->shape_id) &&
             a->direction_id == b->direction_id &&
             a->wheelchair_accessible == b->wheelchair_accessible &&
             a->bikes_allowed == b->bikes_allowed);
}