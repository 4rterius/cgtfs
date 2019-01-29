#include "reading_db.h"

feed_db_status_t read_all_agencies_db(FILE *fp, feed_db_t *db) {

    agency_t record;

    char **record_values = NULL;
    int record_count = count_lines(fp) - 1;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);
    
    if (record_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (record_count < 0) ? -1 : 0;
    }

    // PLAN: Create table if doesn't exist.

    for (int i = 0; i < record_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_agency(&record, field_count, (const char **)field_names, (const char **)record_values);
            // PLAN: Write record into the database.

            free_cstr_arr(record_values, field_count);
        }
    }

    free_cstr_arr(field_names, field_count);
    return record_count;
}