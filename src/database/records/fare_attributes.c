#include "database/records/fare_attributes.h"

feed_db_status_t store_fare_attributes_db(fare_attributes_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO fare_attributes ("
                    "fare_id, price, currency_type, payment_method,"
                    "transfers, agency_id, transfer_duration"
                ") values ("
                    "?1, ?2, ?3, ?4,"
                    "?5, ?6, ?7"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->fare_id, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, record->price);
    sqlite3_bind_text(stmt, 3, record->currency_type, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, (int)record->payment_method);
    sqlite3_bind_int(stmt, 5, (int)record->transfers);
    sqlite3_bind_text(stmt, 6, record->agency_id, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 7, record->transfer_duration);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}