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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_agency(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_agency_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_calendar_date(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_calendar_dates_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_calendar_records_db(FILE *fp, feed_db_t *db) {

    calendar_record_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_calendar_record(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_calendar_record_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_fare_attributes_db(FILE *fp, feed_db_t *db) {

    fare_attributes_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_fare_attributes(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_fare_attributes_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_fare_rules_db(FILE *fp, feed_db_t *db) {

    fare_rule_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_fare_rule(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_fare_rule_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_feed_info_db(FILE *fp, feed_db_t *db) {

    feed_info_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_feed_info(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_feed_info_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_frequencies_db(FILE *fp, feed_db_t *db) {

    frequency_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_frequency(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_frequency_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_routes_db(FILE *fp, feed_db_t *db) {

    route_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_route(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_route_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_shapes_db(FILE *fp, feed_db_t *db) {

    shape_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_shape(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_shape_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_stop_times_db(FILE *fp, feed_db_t *db) {

    stop_time_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_stop_time(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_stop_time_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_stops_db(FILE *fp, feed_db_t *db) {

    stop_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_stop(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_stop_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_transfers_db(FILE *fp, feed_db_t *db) {

    transfer_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_transfer(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_transfer_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}

int store_all_trips_db(FILE *fp, feed_db_t *db) {

    trip_t record;
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

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    if ((res = begin_transaction(db)) == FEED_DB_ERROR) {
        free_cstr_arr(field_names, field_count);
        return -1;
    }
    #endif
    
    for (int i = 0; i < lines_count; i++) {
        if (read_record(fp, field_count, &record_values) > 0) {
            read_trip(&record, field_count, (const char **)field_names, (const char **)record_values);
            res = store_trip_db(&record, db);

            // free_cstr_arr(record_values, field_count);

            if (res == FEED_DB_SUCCESS)
                record_count++;
            else
                break;
        }
        free_cstr_arr(record_values, field_count);
    }

    #ifndef CGTFS_STORING_BATCH_TRANSACTIONS_OFF
    end_transaction(db);
    #endif

    free_cstr_arr(field_names, field_count);
    return record_count;
}
