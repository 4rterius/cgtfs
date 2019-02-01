#include "writing_db.h"

feed_db_status_t write_agency_db(agency_t *record, feed_db_t *db) {
    sqlite3_stmt *statement;
    char sql[STATEMENT_BUF_LEN];

    snprintf(sql, STATEMENT_BUF_LEN, "");

    db->rc = sqlite3_prepare_v2(&(db->conn), sql, strlen(sql) + 1, &statement, NULL);
}