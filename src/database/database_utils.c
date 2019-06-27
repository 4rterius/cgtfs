#include "database/database_utils.h"

int count_rows(feed_db_t *db, const char *table_name) {   
    int count = -1; 
    sqlite3_stmt *stmt;
    
    int query_buf_len = 25 + strlen(table_name);
    char *query_buf = malloc(sizeof(char) * query_buf_len);
    snprintf(query_buf, query_buf_len, "SELECT count(*) FROM `%s`;", table_name);

    sqlite3_prepare_v2(db->conn, query_buf, -1, &stmt, NULL);
    db->rc = sqlite3_step(stmt);

    if (db->rc == SQLITE_ROW) {
        count = sqlite3_column_int(stmt, 0);
    } else {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
    }

    sqlite3_finalize(stmt);
    free(query_buf);
    return count;
}


feed_db_status_t begin_transaction(feed_db_t *db) {
    char *err_msg = 0;
    db->rc = sqlite3_exec(db->conn, "BEGIN TRANSACTION;", NULL, NULL, &err_msg);
    
    if (db->rc != SQLITE_OK) {
        db->error_msg = strdup(err_msg);
        free(err_msg);
        return FEED_DB_ERROR;
    }

    return FEED_DB_SUCCESS;
}

feed_db_status_t end_transaction(feed_db_t *db) {
    char *err_msg = 0;
    db->rc = sqlite3_exec(db->conn, "END TRANSACTION;", NULL, NULL, &err_msg);
    
    if (db->rc != SQLITE_OK) {
        db->error_msg = strdup(err_msg);
        free(err_msg);
        return FEED_DB_ERROR;
    }

    return FEED_DB_SUCCESS;
}


// feed_db_status_t cgtfs_db_create_table(const char *name, int field_num, const char **field_names,
//         const char *key_field,  feed_db_t *db) {
//     char sql[STATEMENT_BUF_LEN];
//     int i = 0;
    
//     snprintf(sql, STATEMENT_BUF_LEN, "CREATE TABLE %s (\n");

//     for (i = 0; i < field_num - 1; i++) {
//         if (!strcmp(key_field, field_names[i]))
//             snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT PRIMARY KEY NOT NULL,", field_names[i]);
//         else
//             snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT,", field_names[i]);
//     }

//     if (!strcmp(key_field, field_names[i]))
//         snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT PRIMARY KEY NOT NULL", field_names[i]);
//     else
//         snprintf(sql, STATEMENT_BUF_LEN, "%s TEXT", field_names[i]);

//     snprintf(sql, STATEMENT_BUF_LEN, "\n%s);", sql);
    
//     db->rc = sqlite3_exec(db->conn, sql, NULL, NULL, &(db->error_msg));
//     if (db->rc)
//         return FEED_DB_ERROR;
//     return FEED_DB_SUCCESS;
// }