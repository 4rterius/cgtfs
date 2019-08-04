#include "records/stop.h"

location_type_t parse_location_type(const char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return LT_STOP;
    else if (strcmp(value, "1") == 0)
        return LT_STATION;
    else if (strcmp(value, "2") == 0)
        return LT_STATION_ENTRANCE_EXIT;
    else
        return LT_NOT_SET;
}

wheelchair_boarding_t parse_wheelchair_boarding(const char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return WB_UNKNOWN_OR_INHERITED;
    else if (strcmp(value, "1") == 0)
        return WB_SOME;
    else if (strcmp(value, "2") == 0)
        return WB_NOT_POSSIBLE;
    else
        return WB_NOT_SET;
}

void init_stop(stop_t *record){
    strcpy(record->id, "");
    strcpy(record->code, "");
    strcpy(record->name, "");
    strcpy(record->desc, "");
    record->lat = 0.0;
    record->lon = 0.0;
    strcpy(record->zone_id, "");
    strcpy(record->url, "");
    record->location_type = LT_STOP;
    strcpy(record->parent_station, "");
    strcpy(record->timezone, "");
    record->wheelchair_boarding = WB_UNKNOWN_OR_INHERITED;
    strcpy(record->level_id, "");
    strcpy(record->platform_code, "");
}

void read_stop(stop_t *record, int field_count, const char **field_names, const char **field_values) {
    init_stop(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "stop_id") == 0) {
            strcpy(record->id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "stop_code") == 0) {
            strcpy(record->code, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "stop_name") == 0) {
            strcpy(record->name, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "stop_desc") == 0) {
            strcpy(record->desc, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "stop_lat") == 0) {
            record->lat = strtod(field_values[i], NULL);  // TODO: same as shape.c:26
            continue;
        }
        if (strcmp(field_names[i], "stop_lon") == 0) {
            record->lon = strtod(field_values[i], NULL);  // TODO: same as shape.c:26
            continue;
        }
        if (strcmp(field_names[i], "zone_id") == 0) {
            strcpy(record->zone_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "stop_url") == 0) {
            strcpy(record->url, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "location_type") == 0) {
            record->location_type = parse_location_type(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "parent_station") == 0) {
            strcpy(record->parent_station, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "stop_timezone") == 0) {
            strcpy(record->timezone, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "wheelchair_boarding") == 0) {
            record->wheelchair_boarding = parse_wheelchair_boarding(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "level_id") == 0) {
            strcpy(record->level_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "platform_code") == 0) {
            strcpy(record->platform_code, field_values[i]);
            continue;
        }
    }
}

int equal_stop(const stop_t *a, const stop_t *b) {
    return (!strcmp(a->id, b->id) &&
             !strcmp(a->code, b->code) &&
             !strcmp(a->name, b->name) &&
             !strcmp(a->desc, b->desc) &&
             !strcmp(a->zone_id, b->zone_id) &&
             !strcmp(a->url, b->url) &&
             !strcmp(a->parent_station, b->parent_station) &&
             !strcmp(a->timezone, b->timezone) &&
             !strcmp(a->level_id, b->level_id) &&
             !strcmp(a->platform_code, b->platform_code) &&
             a->lat == b->lat &&
             a->lon == b->lon &&
             a->location_type == b->location_type &&
             a->wheelchair_boarding == b->wheelchair_boarding);
}