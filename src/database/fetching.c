#include "database/fetching.h"

int fetch_all_agencies_db(feed_db_t *db, agency_t **records) {

    agency_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "agency");
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

    int record_count = count_rows_db(db, "calendar_dates");
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

    int record_count = count_rows_db(db, "calendar");
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

    int record_count = count_rows_db(db, "fare_attributes");
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

    int record_count = count_rows_db(db, "fare_rules");
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

    int record_count = count_rows_db(db, "feed_info");
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

    int record_count = count_rows_db(db, "frequencies");
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

int fetch_all_levels_db(feed_db_t *db, level_t **records) {

    level_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "levels");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "level_id, level_index, level_name "
                "FROM `levels`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_level(&record);

        strcpy(record.id, sqlite3_column_text(stmt, 0));
        record.index = sqlite3_column_double(stmt, 1);
        strcpy(record.name, sqlite3_column_text(stmt, 2));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_pathways_db(feed_db_t *db, pathway_t **records) {

    pathway_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "pathways");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "pathway_id, from_stop_id, to_stop_id,"
                    "pathway_mode, is_bidirectional, length, traversal_time, stair_count, max_slope, min_width,"
                    "signposted_as, reversed_signposted_as "
                "FROM `pathways`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_pathway(&record);

        strcpy(record.id, sqlite3_column_text(stmt, 0));
        strcpy(record.from_stop_id, sqlite3_column_text(stmt, 1));
        strcpy(record.to_stop_id, sqlite3_column_text(stmt, 2));
        record.mode = (pathway_mode_t)sqlite3_column_int(stmt, 3);
        record.is_bidirectional = (pathway_directions_t)sqlite3_column_int(stmt, 4);
        record.length = sqlite3_column_double(stmt, 5);
        record.traversal_time = sqlite3_column_double(stmt, 6);
        record.stair_count = sqlite3_column_double(stmt, 7);
        record.max_slope = sqlite3_column_double(stmt, 8);
        record.min_width = sqlite3_column_double(stmt, 9);
        strcpy(record.signposted_as, sqlite3_column_text(stmt, 10));
        strcpy(record.reversed_signposted_as, sqlite3_column_text(stmt, 11));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_routes_db(feed_db_t *db, route_t **records) {

    route_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "routes");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "route_id, agency_id,"
                    "route_short_name, route_long_name, route_desc, route_type,"
                    "route_url,"
                    "route_color, route_text_color,"
                    "route_sort_order "
                "FROM `routes`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_route(&record);

        strcpy(record.id, sqlite3_column_text(stmt, 0));
        strcpy(record.agency_id, sqlite3_column_text(stmt, 1));
        strcpy(record.short_name, sqlite3_column_text(stmt, 2));
        strcpy(record.long_name, sqlite3_column_text(stmt, 3));
        strcpy(record.desc, sqlite3_column_text(stmt, 4));
        record.type = (route_type_t)sqlite3_column_int(stmt, 5);
        strcpy(record.url, sqlite3_column_text(stmt, 6));
        strcpy(record.color, sqlite3_column_text(stmt, 7));
        strcpy(record.text_color, sqlite3_column_text(stmt, 8));
        record.sort_order = sqlite3_column_int(stmt, 9);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_shapes_db(feed_db_t *db, shape_t **records) {

    shape_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "shapes");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "shape_id,"
                    "shape_pt_lat, shape_pt_lon,"
                    "shape_pt_sequence, shape_dist_traveled "
                "FROM `shapes`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_shape(&record);

        strcpy(record.id, sqlite3_column_text(stmt, 0));
        record.pt_lat = sqlite3_column_double(stmt, 1);
        record.pt_lon = sqlite3_column_double(stmt, 2);
        record.pt_sequence = sqlite3_column_int(stmt, 3);
        record.dist_traveled = sqlite3_column_double(stmt, 4);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_stop_times_db(feed_db_t *db, stop_time_t **records) {

    stop_time_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "stop_times");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "trip_id, arrival_time, departure_time,"
                    "stop_id, stop_sequence, stop_headsign,"
                    "pickup_type, drop_off_type,"
                    "shape_dist_traveled, timepoint "
                "FROM `stop_times`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_stop_time(&record);

        strcpy(record.trip_id, sqlite3_column_text(stmt, 0));
        strcpy(record.arrival_time, sqlite3_column_text(stmt, 1));
        strcpy(record.departure_time, sqlite3_column_text(stmt, 2));
        strcpy(record.stop_id, sqlite3_column_text(stmt, 3));
        record.stop_sequence = sqlite3_column_int(stmt, 4);
        strcpy(record.stop_headsign, sqlite3_column_text(stmt, 5));
        record.pickup_type = (stop_type_t)sqlite3_column_int(stmt, 6);
        record.dropoff_type = (stop_type_t)sqlite3_column_int(stmt, 7);
        record.shape_dist_traveled = sqlite3_column_double(stmt, 8);
        record.timepoint = (timepoint_precision_t)sqlite3_column_int(stmt, 9);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_stops_db(feed_db_t *db, stop_t **records) {

    stop_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "stops");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "stop_id, stop_code, stop_name, stop_desc,"
                    "stop_lat, stop_lon,"
                    "zone_id, stop_url,"
                    "location_type, parent_station, stop_timezone, wheelchair_boarding, "
                    "level_id, platform_code "
                "FROM `stops`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_stop(&record);

        strcpy(record.id, sqlite3_column_text(stmt, 0));
        strcpy(record.code, sqlite3_column_text(stmt, 1));
        strcpy(record.name, sqlite3_column_text(stmt, 2));
        strcpy(record.desc, sqlite3_column_text(stmt, 3));
        record.lat = sqlite3_column_double(stmt, 4);
        record.lon = sqlite3_column_double(stmt, 5);
        strcpy(record.zone_id, sqlite3_column_text(stmt, 6));
        strcpy(record.url, sqlite3_column_text(stmt, 7));
        record.location_type = (location_type_t)sqlite3_column_int(stmt, 8);
        strcpy(record.parent_station, sqlite3_column_text(stmt, 9));
        strcpy(record.timezone, sqlite3_column_text(stmt, 10));
        record.wheelchair_boarding = (wheelchair_boarding_t)sqlite3_column_int(stmt, 11);
        strcpy(record.level_id, sqlite3_column_text(stmt, 12));
        strcpy(record.platform_code, sqlite3_column_text(stmt, 13));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_transfers_db(feed_db_t *db, transfer_t **records) {

    transfer_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "transfers");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "from_stop_id, to_stop_id, transfer_type, min_transfer_time "
                "FROM `transfers`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_transfer(&record);

        strcpy(record.from_stop_id, sqlite3_column_text(stmt, 0));
        strcpy(record.to_stop_id, sqlite3_column_text(stmt, 1));
        record.transfer_type = (transfer_type_t)sqlite3_column_int(stmt, 2);
        record.min_transfer_time = sqlite3_column_int(stmt, 3);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}

int fetch_all_trips_db(feed_db_t *db, trip_t **records) {

    trip_t record;
    feed_db_status_t res;

    int record_count = count_rows_db(db, "trips");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT "
                    "route_id, service_id, trip_id,"
                    "trip_headsign, trip_short_name,"
                    "direction_id, block_id, shape_id,"
                    "wheelchair_accessible, bikes_allowed "
                "FROM `trips`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_trip(&record);

        strcpy(record.route_id, sqlite3_column_text(stmt, 0));
        strcpy(record.service_id, sqlite3_column_text(stmt, 1));
        strcpy(record.id, sqlite3_column_text(stmt, 2));
        strcpy(record.headsign, sqlite3_column_text(stmt, 3));
        strcpy(record.short_name, sqlite3_column_text(stmt, 4));
        record.direction_id = sqlite3_column_int(stmt, 5);
        strcpy(record.block_id, sqlite3_column_text(stmt, 6));
        strcpy(record.shape_id, sqlite3_column_text(stmt, 7));
        record.wheelchair_accessible = (wheelchair_accessible_t)sqlite3_column_int(stmt, 8);
        record.bikes_allowed = (bikes_allowed_t)sqlite3_column_int(stmt, 9);

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    sqlite3_finalize(stmt);
    return record_count;
}
