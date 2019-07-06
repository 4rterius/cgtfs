#include "database/records/stop_time.h"

feed_db_status_t store_stop_time_db(stop_time_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO stop_times ("
                    "trip_id, arrival_time, departure_time,"
                    "stop_id, stop_sequence, stop_headsign,"
                    "pickup_type, drop_off_type,"
                    "shape_dist_traveled, timepoint"
                ") values ("
                    "?1, ?2, ?3,"
                    "?4, ?5, ?6,"
                    "?7, ?8,"
                    "?9, ?10"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->trip_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->arrival_time, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->departure_time, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, record->stop_id, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, record->stop_sequence);
    sqlite3_bind_text(stmt, 6, record->stop_headsign, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, (int)record->pickup_type);
    sqlite3_bind_int(stmt, 8, (int)record->dropoff_type);
    sqlite3_bind_double(stmt, 9, record->shape_dist_traveled);
    sqlite3_bind_int(stmt, 10, (int)record->timepoint);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}