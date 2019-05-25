#include "database/database.h"

feed_db_status_t init_feed_db(feed_db_t *db, const char *db_path, int writable) {
    db->path = strdup(db_path);
    db->rc = -1;
    db->error_msg = NULL;
    db->open = 0;
    
    db->rc = sqlite3_open_v2(db_path, &(db->conn),
        writable ? (SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE) : (SQLITE_OPEN_READONLY),
        NULL);

    if (db->rc) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        return FEED_DB_ERROR;
    }

    db->open = 1;
    return FEED_DB_SUCCESS;
}

feed_db_status_t free_feed_db(feed_db_t *db) {
    free(db->path);
    free(db->error_msg);

    db->rc = sqlite3_close(db->conn);
    if (db->rc != SQLITE_OK) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        return FEED_DB_ERROR;
    }

    db->open = 0;
    return FEED_DB_SUCCESS;
}

feed_db_status_t setup_feed_db(feed_db_t *db) {
    char sql[] = ""
        "CREATE TABLE agency ( "
        "	agency_id TEXT, "
        "	agency_name TEXT PRIMARY KEY NOT NULL, "
        "	agency_url TEXT NOT NULL, "
        "	agency_timezone TEXT NOT NULL, "
        "	agency_lang TEXT, "
        "	agency_phone TEXT, "
        "	agency_fare_url TEXT, "
        "	agency_email TEXT "
        ");\n"
        "CREATE TABLE stops ( "
        "	stop_id TEXT PRIMARY KEY NOT NULL, "
        "	stop_code TEXT, "
        "	stop_name TEXT NOT NULL, "
        "	stop_desc TEXT, "
        "	stop_lat DOUBLE NOT NULL, "
        "	stop_lon DOUBLE NOT NULL, "
        "	zone_id TEXT, "
        "	stop_url TEXT, "
        "	location_type INT, "
        "	parent_station TEXT, "
        "	stop_timezone TEXT, "
        "	wheelchair_boarding INT "
        ");\n"
        "CREATE TABLE routes ( "
        "	route_id TEXT PRIMARY KEY NOT NULL, "
        "	agency_id TEXT, "
        "	route_short_name TEXT, "
        "	route_long_name TEXT, "
        "	route_desc TEXT, "
        "	route_type INT NOT NULL, "
        "	route_url TEXT, "
        "	route_color TEXT, "
        "	route_text_color TEXT, "
        "	route_sort_order INT "
        ");\n"
        "CREATE TABLE trips ( "
        "	route_id TEXT NOT NULL, "
        "	service_id TEXT NOT NULL, "
        "	trip_id TEXT PRIMARY KEY NOT NULL, "
        "	trip_headsign TEXT, "
        "	trip_short_name TEXT, "
        "	direction_id INT, "
        "	block_id TEXT, "
        "	shape_id TEXT, "
        "	wheelchair_accessible INT, "
        "	bikes_allowed INT "
        ");\n"
        "CREATE TABLE stop_times ( "
        "	trip_id TEXT NOT NULL, "
        "	arrival_time TEXT NOT NULL, "
        "	departure_time TEXT NOT NULL, "
        "	stop_id TEXT NOT NULL, "
        "	stop_sequence INT NOT NULL, "
        "	stop_headsign TEXT, "
        "	pickup_type INT, "
        "	drop_off_type INT, "
        "	shape_dist_traveled REAL, "
        "	timepoint INT "
        ");\n"
        "CREATE TABLE calendar ( "
        "	service_id TEXT PRIMARY KEY NOT NULL, "
        "	monday INT NOT NULL, "
        "	tuesday INT NOT NULL, "
        "	wednesday INT NOT NULL, "
        "	thursday INT NOT NULL, "
        "	friday INT NOT NULL, "
        "	saturday INT NOT NULL, "
        "	sunday INT NOT NULL, "
        "	start_date TEXT NOT NULL, "
        "	end_date TEXT NOT NULL "
        ");\n"
        "CREATE TABLE calendar_dates ( "
        "	service_id TEXT NOT NULL, "
        "	date TEXT NOT NULL, "
        "	exception_type INT NOT NULL "
        ");\n"
        "CREATE TABLE fare_attributes ( "
        "	fare_id TEXT NOT NULL, "
        "	price REAL NOT NULL, "
        "	currency_type TEXT NOT NULL, "
        "	payment_method INT NOT NULL, "
        "	transfers INT NOT NULL, "
        "	agency_id TEXT, "
        "	transfer_duration INT "
        ");\n"
        "CREATE TABLE fare_rules ( "
        "	fare_id TEXT NOT NULL, "
        "	route_id TEXT, "
        "	origin_id TEXT, "
        "	destination_id TEXT, "
        "	contains_id TEXT "
        ");\n"
        "CREATE TABLE shapes ( "
        "	shape_id TEXT PRIMARY KEY NOT NULL, "
        "	shape_pt_lat DOUBLE NOT NULL, "
        "	shape_pt_lon DOUBLE NOT NULL, "
        "	shape_pt_sequence INT NOT NULL, "
        "	shape_dist_traveled REAL "
        ");\n"
        "CREATE TABLE frequencies ( "
        "	trip_id TEXT NOT NULL, "
        "	start_time TEXT NOT NULL, "
        "	end_time TEXT NOT NULL, "
        "	headway_secs INT NOT NULL, "
        "	exact_times INT "
        ");\n"
        "CREATE TABLE transfers ( "
        "	from_stop_id TEXT NOT NULL, "
        "	to_stop_id TEXT NOT NULL, "
        "	transfer_type INT NOT NULL, "
        "	min_transfer_time INT "
        ");\n"
        "CREATE TABLE feed_info ( "
        "	feed_publisher_name TEXT NOT NULL, "
        "	feed_publisher_url TEXT NOT NULL, "
        "	feed_lang TEXT NOT NULL, "
        "	feed_start_date TEXT, "
        "	feed_end_date TEXT, "
        "	feed_version TEXT, "
        "	feed_contact_email TEXT, "
        "	feed_contact_url TEXT "
        "); ";
    
    db->rc = sqlite3_exec(db->conn, sql, NULL, NULL, &(db->error_msg));

    if (db->rc)
        return FEED_DB_ERROR;
    return FEED_DB_SUCCESS;
}