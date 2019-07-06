#include "database/records/trip.h"

feed_db_status_t store_trip_db(trip_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO trips ("
                    "route_id, service_id, trip_id,"
                    "trip_headsign, trip_short_name,"
                    "direction_id, block_id, shape_id,"
                    "wheelchair_accessible, bikes_allowed"
                ") values ("
                    "?1, ?2, ?3,"
                    "?4, ?5,"
                    "?6, ?7, ?8,"
                    "?9, ?10"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->route_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->service_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, record->headsign, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, record->short_name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, record->direction_id);
    sqlite3_bind_text(stmt, 7, record->block_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, record->shape_id, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 9, (int)record->wheelchair_accessible);
    sqlite3_bind_int(stmt, 10, (int)record->bikes_allowed);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}