#include "database/records/stop.h"

feed_db_status_t store_stop_db(stop_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO stops ("
                    "stop_id, stop_code, stop_name, stop_desc,"
                    "stop_lat, stop_lon,"
                    "zone_id, stop_url,"
                    "location_type, parent_station, stop_timezone, wheelchair_boarding,"
                    "level_id, platform_code"
                ") values ("
                    "?1, ?2, ?3, ?4,"
                    "?5, ?6,"
                    "?7, ?8,"
                    "?9, ?10, ?11, ?12,"
                    "?13, ?14"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->code, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, record->desc, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 5, record->lat);
    sqlite3_bind_double(stmt, 6, record->lon);
    sqlite3_bind_text(stmt, 7, record->zone_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, record->url, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 9, (int)record->location_type);
    sqlite3_bind_text(stmt, 10, record->parent_station, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 11, record->timezone, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 12, (int)record->wheelchair_boarding);
    sqlite3_bind_text(stmt, 13, record->level_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 14, record->platform_code, -1, SQLITE_STATIC);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}