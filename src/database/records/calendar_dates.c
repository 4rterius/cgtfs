#include "database/records/calendar_dates.h"

feed_db_status_t store_calendar_dates_db(calendar_date_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO calendar_dates ("
                    "service_id, date, exception_type"
                ") values ("
                    "?1, ?2, ?3"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->service_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->date, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, (int)record->exception_type);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}