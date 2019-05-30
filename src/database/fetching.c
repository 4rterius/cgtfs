#include "database/fetching.h"

int fetch_all_agencies_db(feed_db_t *db, agency_t **records) {
    
    agency_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "agency");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "agency_id, agency_name,"
                    "agency_url, agency_timezone,"
                    "agency_lang, agency_phone,"
                    "agency_fare_url, agency_email "
                "FROM `agency`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_agency(&record);

        strcpy(record.id, sqlite3_column_text(stmt, 0));
        strcpy(record.name, sqlite3_column_text(stmt, 1));
        strcpy(record.url, sqlite3_column_text(stmt, 2));
        strcpy(record.timezone, sqlite3_column_text(stmt, 3));
        strcpy(record.lang, sqlite3_column_text(stmt, 4));
        strcpy(record.phone, sqlite3_column_text(stmt, 5));
        strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
        strcpy(record.email, sqlite3_column_text(stmt, 7));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }
    
    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_calendar_dates_db(feed_db_t *db, calendar_date_t **records) {
    
    calendar_date_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "calendar_dates");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "service_id, date, exception_type "
                "FROM `calendar_dates`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_calendar_date(&record);

        strcpy(record.service_id, sqlite3_column_text(stmt, 0));
        strcpy(record.date, sqlite3_column_text(stmt, 1));
        record.exception_type = (exception_type_t)sqlite3_column_int(stmt, 2);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }
    
    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_calendar_records_db(feed_db_t *db, calendar_record_t **records) {
    
    calendar_record_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "calendar");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "service_id,"
                    "monday, tuesday, wednesday, thursday, friday, saturday, sunday,"
                    "start_date, end_date "
                "FROM `calendar`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_calendar_record(&record);

        strcpy(record.service_id, sqlite3_column_text(stmt, 0));
        record.monday = sqlite3_column_int(stmt, 1);
        record.tuesday = sqlite3_column_int(stmt, 2);
        record.wednesday = sqlite3_column_int(stmt, 3);
        record.thursday = sqlite3_column_int(stmt, 4);
        record.friday = sqlite3_column_int(stmt, 5);
        record.saturday = sqlite3_column_int(stmt, 6);
        record.sunday = sqlite3_column_int(stmt, 7);
        strcpy(record.start_date, sqlite3_column_text(stmt, 8));
        strcpy(record.end_date, sqlite3_column_text(stmt, 9));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }
    
    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_fare_attributes_db(feed_db_t *db, fare_attributes_t **records) {
    
    fare_attributes_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "fare_attributes");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "fare_id, price, currency_type, payment_method,"
                    "transfers, agency_id, transfer_duration "
                "FROM `fare_attributes`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_fare_attributes(&record);

        strcpy(record.fare_id, sqlite3_column_text(stmt, 0));
        record.price = sqlite3_column_double(stmt, 1);
        strcpy(record.currency_type, sqlite3_column_text(stmt, 2));
        record.payment_method = (payment_method_t)sqlite3_column_int(stmt, 3);
        record.transfers = (transfers_state_t)sqlite3_column_int(stmt, 4);
        strcpy(record.agency_id, sqlite3_column_text(stmt, 5));
        record.transfer_duration = sqlite3_column_double(stmt, 6);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }
    
    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_fare_rules_db(feed_db_t *db, fare_rule_t **records) {
    
    fare_rule_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "fare_rules");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "fare_id, route_id, origin_id, destination_id, contains_id "
                "FROM `fare_rules`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_fare_rule(&record);

        strcpy(record.fare_id, sqlite3_column_text(stmt, 0));
        strcpy(record.route_id, sqlite3_column_text(stmt, 1));
        strcpy(record.origin_id, sqlite3_column_text(stmt, 2));
        strcpy(record.destination_id, sqlite3_column_text(stmt, 3));
        strcpy(record.contains_id, sqlite3_column_text(stmt, 4));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }
    
    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_feed_info_db(feed_db_t *db, feed_info_t **records) {
    
    feed_info_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "feed_info");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "feed_publisher_name, feed_publisher_url, feed_lang,"
                    "feed_start_date, feed_end_date, feed_version,"
                    "feed_contact_email, feed_contact_url "
                "FROM `feed_info`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_feed_info(&record);

        strcpy(record.feed_publisher_name, sqlite3_column_text(stmt, 0));
        strcpy(record.feed_publisher_url, sqlite3_column_text(stmt, 1));
        strcpy(record.feed_lang, sqlite3_column_text(stmt, 2));
        strcpy(record.feed_start_date, sqlite3_column_text(stmt, 3));
        strcpy(record.feed_end_date, sqlite3_column_text(stmt, 4));
        strcpy(record.feed_version, sqlite3_column_text(stmt, 5));
        strcpy(record.feed_contact_email, sqlite3_column_text(stmt, 6));
        strcpy(record.feed_contact_url, sqlite3_column_text(stmt, 7));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }
    
    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_frequencies_db(feed_db_t *db, frequency_t **records) {
    
    frequency_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "frequencies");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "trip_id, start_time, end_time,"
                    "headway_secs, exact_times "
                "FROM `frequencies`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_frequency(&record);

        strcpy(record.trip_id, sqlite3_column_text(stmt, 0));
        strcpy(record.start_time, sqlite3_column_text(stmt, 1));
        strcpy(record.end_time, sqlite3_column_text(stmt, 2));
        record.headway_secs = sqlite3_column_int(stmt, 3);
        record.exact_times = (time_exactness_t)sqlite3_column_int(stmt, 4);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }
    
    sqlite3_finalize(stmt);
    return record_count;
}

// int fetch_all_routes_db(feed_db_t *db, route_t **records) {
    
//     agency_t record;
//     feed_db_status_t res;

//     int record_count = count_rows(db, "agency");
//     int i = 0;

//     if (record_count < 1) {
//         return record_count;
//     }

//     sqlite3_stmt *stmt;
//     char qr[] = "SELECT "
//                     "agency_id, agency_name,"
//                     "agency_url, agency_timezone,"
//                     "agency_lang, agency_phone,"
//                     "agency_fare_url, agency_email "
//                 "FROM `agency`;";

//     sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

//     *records = malloc(record_count * sizeof(**records));

//     while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//         init_agency(&record);

//         strcpy(record.id, sqlite3_column_text(stmt, 0));
//         strcpy(record.name, sqlite3_column_text(stmt, 1));
//         strcpy(record.url, sqlite3_column_text(stmt, 2));
//         strcpy(record.timezone, sqlite3_column_text(stmt, 3));
//         strcpy(record.lang, sqlite3_column_text(stmt, 4));
//         strcpy(record.phone, sqlite3_column_text(stmt, 5));
//         strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
//         strcpy(record.email, sqlite3_column_text(stmt, 7));

//         (*records)[i] = record;
//         i++;

//         if (i >= record_count)
//             break;
//     }
    
//     sqlite3_finalize(stmt);
//     return record_count;
// }

// int fetch_all_shapes_db(feed_db_t *db, shape_t **records) {
    
//     agency_t record;
//     feed_db_status_t res;

//     int record_count = count_rows(db, "agency");
//     int i = 0;

//     if (record_count < 1) {
//         return record_count;
//     }

//     sqlite3_stmt *stmt;
//     char qr[] = "SELECT "
//                     "agency_id, agency_name,"
//                     "agency_url, agency_timezone,"
//                     "agency_lang, agency_phone,"
//                     "agency_fare_url, agency_email "
//                 "FROM `agency`;";

//     sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

//     *records = malloc(record_count * sizeof(**records));

//     while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//         init_agency(&record);

//         strcpy(record.id, sqlite3_column_text(stmt, 0));
//         strcpy(record.name, sqlite3_column_text(stmt, 1));
//         strcpy(record.url, sqlite3_column_text(stmt, 2));
//         strcpy(record.timezone, sqlite3_column_text(stmt, 3));
//         strcpy(record.lang, sqlite3_column_text(stmt, 4));
//         strcpy(record.phone, sqlite3_column_text(stmt, 5));
//         strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
//         strcpy(record.email, sqlite3_column_text(stmt, 7));

//         (*records)[i] = record;
//         i++;

//         if (i >= record_count)
//             break;
//     }
    
//     sqlite3_finalize(stmt);
//     return record_count;
// }

// int fetch_all_stop_times_db(feed_db_t *db, stop_time_t **records) {
    
//     agency_t record;
//     feed_db_status_t res;

//     int record_count = count_rows(db, "agency");
//     int i = 0;

//     if (record_count < 1) {
//         return record_count;
//     }

//     sqlite3_stmt *stmt;
//     char qr[] = "SELECT "
//                     "agency_id, agency_name,"
//                     "agency_url, agency_timezone,"
//                     "agency_lang, agency_phone,"
//                     "agency_fare_url, agency_email "
//                 "FROM `agency`;";

//     sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

//     *records = malloc(record_count * sizeof(**records));

//     while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//         init_agency(&record);

//         strcpy(record.id, sqlite3_column_text(stmt, 0));
//         strcpy(record.name, sqlite3_column_text(stmt, 1));
//         strcpy(record.url, sqlite3_column_text(stmt, 2));
//         strcpy(record.timezone, sqlite3_column_text(stmt, 3));
//         strcpy(record.lang, sqlite3_column_text(stmt, 4));
//         strcpy(record.phone, sqlite3_column_text(stmt, 5));
//         strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
//         strcpy(record.email, sqlite3_column_text(stmt, 7));

//         (*records)[i] = record;
//         i++;

//         if (i >= record_count)
//             break;
//     }
    
//     sqlite3_finalize(stmt);
//     return record_count;
// }

// int fetch_all_stops_db(feed_db_t *db, stop_t **records) {
    
//     agency_t record;
//     feed_db_status_t res;

//     int record_count = count_rows(db, "agency");
//     int i = 0;

//     if (record_count < 1) {
//         return record_count;
//     }

//     sqlite3_stmt *stmt;
//     char qr[] = "SELECT "
//                     "agency_id, agency_name,"
//                     "agency_url, agency_timezone,"
//                     "agency_lang, agency_phone,"
//                     "agency_fare_url, agency_email "
//                 "FROM `agency`;";

//     sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

//     *records = malloc(record_count * sizeof(**records));

//     while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//         init_agency(&record);

//         strcpy(record.id, sqlite3_column_text(stmt, 0));
//         strcpy(record.name, sqlite3_column_text(stmt, 1));
//         strcpy(record.url, sqlite3_column_text(stmt, 2));
//         strcpy(record.timezone, sqlite3_column_text(stmt, 3));
//         strcpy(record.lang, sqlite3_column_text(stmt, 4));
//         strcpy(record.phone, sqlite3_column_text(stmt, 5));
//         strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
//         strcpy(record.email, sqlite3_column_text(stmt, 7));

//         (*records)[i] = record;
//         i++;

//         if (i >= record_count)
//             break;
//     }
    
//     sqlite3_finalize(stmt);
//     return record_count;
// }

// int fetch_all_transfers_db(feed_db_t *db, transfer_t **records) {
    
//     agency_t record;
//     feed_db_status_t res;

//     int record_count = count_rows(db, "agency");
//     int i = 0;

//     if (record_count < 1) {
//         return record_count;
//     }

//     sqlite3_stmt *stmt;
//     char qr[] = "SELECT "
//                     "agency_id, agency_name,"
//                     "agency_url, agency_timezone,"
//                     "agency_lang, agency_phone,"
//                     "agency_fare_url, agency_email "
//                 "FROM `agency`;";

//     sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

//     *records = malloc(record_count * sizeof(**records));

//     while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//         init_agency(&record);

//         strcpy(record.id, sqlite3_column_text(stmt, 0));
//         strcpy(record.name, sqlite3_column_text(stmt, 1));
//         strcpy(record.url, sqlite3_column_text(stmt, 2));
//         strcpy(record.timezone, sqlite3_column_text(stmt, 3));
//         strcpy(record.lang, sqlite3_column_text(stmt, 4));
//         strcpy(record.phone, sqlite3_column_text(stmt, 5));
//         strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
//         strcpy(record.email, sqlite3_column_text(stmt, 7));

//         (*records)[i] = record;
//         i++;

//         if (i >= record_count)
//             break;
//     }
    
//     sqlite3_finalize(stmt);
//     return record_count;
// }

// int fetch_all_trips_db(feed_db_t *db, trip_t **records) {
    
//     agency_t record;
//     feed_db_status_t res;

//     int record_count = count_rows(db, "agency");
//     int i = 0;

//     if (record_count < 1) {
//         return record_count;
//     }

//     sqlite3_stmt *stmt;
//     char qr[] = "SELECT "
//                     "agency_id, agency_name,"
//                     "agency_url, agency_timezone,"
//                     "agency_lang, agency_phone,"
//                     "agency_fare_url, agency_email "
//                 "FROM `agency`;";

//     sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

//     *records = malloc(record_count * sizeof(**records));

//     while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//         init_agency(&record);

//         strcpy(record.id, sqlite3_column_text(stmt, 0));
//         strcpy(record.name, sqlite3_column_text(stmt, 1));
//         strcpy(record.url, sqlite3_column_text(stmt, 2));
//         strcpy(record.timezone, sqlite3_column_text(stmt, 3));
//         strcpy(record.lang, sqlite3_column_text(stmt, 4));
//         strcpy(record.phone, sqlite3_column_text(stmt, 5));
//         strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
//         strcpy(record.email, sqlite3_column_text(stmt, 7));

//         (*records)[i] = record;
//         i++;

//         if (i >= record_count)
//             break;
//     }
    
//     sqlite3_finalize(stmt);
//     return record_count;
// }
