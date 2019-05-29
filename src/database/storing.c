#include "database/storing.h"

int store_all_agencies_db(FILE *fp, feed_db_t *db) {

    agency_t record;
    feed_db_status_t res;

    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);
    
    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_agency(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_agency_db(&record, db);

            free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
    }

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_calendar_dates_db(FILE *fp, feed_db_t *db) {

    calendar_date_t record;
    feed_db_status_t res;

    char **record_values = NULL;
    int lines_count = count_lines(fp) - 1;
    int record_count = 0;

    char **field_names = NULL;
    int field_count = read_header(fp, &field_names);
    
    if (lines_count < 1) {
        free_cstr_arr(field_names, field_count);
        free(record_values);
        return (lines_count < 0) ? -1 : 0;
    }
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_calendar_date(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_calendar_dates_db(&record, db);

            free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
    }

    free_cstr_arr(field_names, field_count);
    return record_count;
}