#include "agency.h"

void init_agency(agency_t *record) {
    strcpy(record->id, "");
    strcpy(record->name, "");
    strcpy(record->url, "");
    strcpy(record->timezone, "");
    strcpy(record->lang, "");
    strcpy(record->phone, "");
    strcpy(record->fare_url, "");
    strcpy(record->email, "");
    record->is_null = 1;
}

void read_agency(agency_t *record, int field_count, const char **field_names, const char **field_values) {
    init_agency(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(record->id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_name") == 0) {
            strcpy(record->name, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_url") == 0) {
            strcpy(record->url, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_timezone") == 0) {
            strcpy(record->timezone, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_lang") == 0) {
            strcpy(record->lang, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_phone") == 0) {
            strcpy(record->phone, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_fare_url") == 0) {
            strcpy(record->fare_url, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_email") == 0) {
            strcpy(record->email, field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}
