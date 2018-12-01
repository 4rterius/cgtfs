#include "agency.h"

agency_t empty_agency(void) {
    agency_t agency;
    strcpy(agency.id, "");
    strcpy(agency.name, "");
    strcpy(agency.url, "");
    strcpy(agency.timezone, "");
    strcpy(agency.lang, "");
    strcpy(agency.phone, "");
    strcpy(agency.fare_url, "");
    strcpy(agency.email, "");
    agency.is_null = 1;
    return agency;
}

agency_t make_agency(int field_count, char **field_names, char **field_values) {
    agency_t agency = empty_agency();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(agency.id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_name") == 0) {
            strcpy(agency.name, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_url") == 0) {
            strcpy(agency.url, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_timezone") == 0) {
            strcpy(agency.timezone, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_lang") == 0) {
            strcpy(agency.lang, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_phone") == 0) {
            strcpy(agency.phone, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_fare_url") == 0) {
            strcpy(agency.fare_url, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_email") == 0) {
            strcpy(agency.email, field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        agency.is_null = 1;
    else
        agency.is_null = 0;

    return agency;
}
