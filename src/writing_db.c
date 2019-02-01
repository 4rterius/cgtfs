#include "writing_db.h"

feed_db_status_t write_agency_db(agency_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO agency ("
                    "agency_id, agency_name,"
                    "agency_url, agency_timezone,"
                    "agency_lang, agency_phone,"
                    "agency_fare_url, agency_email"
                ") values ("
                    "?1, ?2, ?3, ?4, ?5, ?6, ?7, ?8"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->url, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, record->timezone, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, record->lang, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, record->phone, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, record->fare_url, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, record->email, -1, SQLITE_STATIC);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}