#include "database/records/calendar.h"

feed_db_status_t store_calendar_record_db(calendar_record_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO calendar ("
                    "service_id,"
                    "monday, tuesday, wednesday, thursday, friday, saturday, sunday,"
                    "start_date, end_date"
                ") values ("
                    "?1,"
                    "?2, ?3, ?4, ?5, ?6, ?7, ?8,"
                    "?9, ?10"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->service_id, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, (int)record->monday);
    sqlite3_bind_int(stmt, 3, (int)record->tuesday);
    sqlite3_bind_int(stmt, 4, (int)record->wednesday);
    sqlite3_bind_int(stmt, 5, (int)record->thursday);
    sqlite3_bind_int(stmt, 6, (int)record->friday);
    sqlite3_bind_int(stmt, 7, (int)record->saturday);
    sqlite3_bind_int(stmt, 8, (int)record->sunday);
    sqlite3_bind_text(stmt, 9, record->start_date, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, record->end_date, -1, SQLITE_STATIC);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}