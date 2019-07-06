#include "database/records/transfers.h"

feed_db_status_t store_transfer_db(transfer_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO transfers ("
                    "from_stop_id, to_stop_id, transfer_type, min_transfer_time"
                ") values ("
                    "?1, ?2, ?3, ?4"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->from_stop_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->to_stop_id, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, (int)record->transfer_type);
    sqlite3_bind_int(stmt, 4, record->min_transfer_time);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}