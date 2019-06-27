#include <stdio.h>

#include "feed.h"
#include "database/database.h"


int row_callback(void *, int column_count, char **data, char **column_names);


// Example 2: 
// Store gtfs folder as a database and
// query it for 10 stop_time records within the next 10 minutes.
void some_database_manipulation(void) {
    printf("\n // TODO: fix error message handling in _exec(..)!\n");
    return;
    feed_db_t database;
    feed_db_status_t result;

    result = init_feed_db(&database, "example2.db", 1);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to create/open a test database: %s !\n",
            database.error_msg);
        free_feed_db(&database);
        return;
    }

    result = setup_feed_db(&database, 0);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to create the layout of the test database: %s !\n",
            database.error_msg);
        free_feed_db(&database);
        return;
    }

    result = store_feed_db("../tests/data/pocono_pony", &database, NULL);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to store a test gtfs directory: data/pocono_pony: %s !\n", 
            database.error_msg);
        free_feed_db(&database);
        return;
    }

    char *error_msg;

    printf("\n  %-8s | %-12s\n", "stop_id", "arrival_time");
    printf("  --------   ------------\n");
    database.rc = sqlite3_exec(database.conn,
        "SELECT stop_id, arrival_time "
        "FROM stop_times "
        "WHERE arrival_time "
            "BETWEEN time('now', 'localtime') "
            "AND time('now', '+10 minutes', 'localtime') "
        "LIMIT 10;",
        row_callback,
        NULL, &error_msg);
    
    if (error_msg != NULL)
        printf("Error while executing query: %s !\n", error_msg);
    

    printf("Done.\n");
    free_feed_db(&database);
}

int row_callback(void *param, int column_count, char **data, char **column_names) {
    if (column_count < 2)
        return 1;
    
    printf("  %-8s | %-12s\n", data[0], data[1]);
    return 0;
}

int main() {
    some_database_manipulation();
    return 0;
}