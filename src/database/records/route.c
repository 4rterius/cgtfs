#include "database/records/route.h"

feed_db_status_t store_route_db(route_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO routes ("
                    "route_id, agency_id,"
                    "route_short_name, route_long_name, route_desc, route_type,"
                    "route_url,"
                    "route_color, route_text_color,"
                    "route_sort_order"
                ") values ("
                    "?1, ?2,"
                    "?3, ?4, ?5, ?6,"
                    "?7,"
                    "?8, ?9,"
                    "?10"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->agency_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->short_name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, record->long_name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, record->desc, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, (int)record->type);
    sqlite3_bind_text(stmt, 7, record->url, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, record->color, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, record->text_color, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 10, record->sort_order);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}