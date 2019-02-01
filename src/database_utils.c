#include "database_utils.h"

feed_db_status_t cgtfs_db_create_table(const char *name, int field_num, const char **field_names,
        const char *key_field,  feed_db_t *db) {
    char sql[STATEMENT_BUF_LEN];
    int i = 0;
    
    snprintf(sql, STATEMENT_BUF_LEN, "CREATE TABLE %s (\n");

    for (i = 0; i < field_num - 1; i++) {
        if (!strcmp(key_field, field_names[i]))
            snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT PRIMARY KEY NOT NULL,", field_names[i]);
        else
            snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT,", field_names[i]);
    }

    if (!strcmp(key_field, field_names[i]))
        snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT PRIMARY KEY NOT NULL", field_names[i]);
    else
        snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT", field_names[i]);

    snprintf(sql, STATEMENT_BUF_LEN, "\n%s);", sql);
    
    db->rc = sqlite3_exec(db->conn, sql, NULL, NULL, &(db->error_msg));
    if (db->rc) {
        free(db->error_msg);
        db->error_msg = sqlite3_errmsg(db->conn);
        return FEED_DB_ERROR;
    }
}