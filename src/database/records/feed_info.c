#include "database/records/feed_info.h"

feed_db_status_t store_feed_info_db(feed_info_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO feed_info ("
                    "feed_publisher_name, feed_publisher_url, feed_lang,"
                    "feed_start_date, feed_end_date, feed_version,"
                    "feed_contact_email, feed_contact_url"
                ") values ("
                    "?1, ?2, ?3,"
                    "?4, ?5, ?6,"
                    "?7, ?8"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->feed_publisher_name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->feed_publisher_url, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->feed_lang, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, record->feed_start_date, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, record->feed_end_date, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, record->feed_version, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, record->feed_contact_email, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, record->feed_contact_url, -1, SQLITE_STATIC);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}