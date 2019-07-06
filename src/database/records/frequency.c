#include "database/records/frequency.h"

feed_db_status_t store_frequency_db(frequency_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO frequencies ("
                    "trip_id, start_time, end_time,"
                    "headway_secs, exact_times"
                ") values ("
                    "?1, ?2, ?3,"
                    "?4, ?5"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->trip_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->start_time, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->end_time, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, record->headway_secs);
    sqlite3_bind_int(stmt, 5, (int)record->exact_times);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}