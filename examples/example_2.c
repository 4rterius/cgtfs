#include <stdio.h>

#include "feed.h"
#include "database/database.h"


int row_callback(void *, int column_count, char **data, char **column_names);


/**
 * Example 2: 
 * 
 * Store gtfs folder as a database and
 * query it for first 10 stop_time records
 * with arrival time within the next 10 minutes.
 */

// The querying itself is done via SQL.
// CGTFS only handles creating the database,
// setting up the layout and filling it with
// feeds' data.
const char *sql_query = 
    "SELECT stop_id, trip_id, arrival_time "
    "FROM stop_times "
    "WHERE arrival_time "
        "BETWEEN time('now', 'localtime') "
        "AND time('now', '+10 minutes', 'localtime') "
    "LIMIT 10;";

void some_database_manipulation(void) {
    char *error_msg = NULL;

    feed_db_t database;
    feed_db_status_t result;

    // Database connection initialization.
    //
    // This function sets up default values
    // for the connection struct
    // and opens the connection.
    //
    // Calling free_feed_db(..) is recommended as soon
    // as the connection is no longer needed.
    //
    // Opening the connection again is preferred to 
    // keeping stuff open and, thus, locked.
    //
    // The sign in `result < FEED_DB_SUCCESS` allows
    // the result of operation to be FEED_DB_PARTIAL (see docs),
    // though for now, it only really matters with store_feed_db(..) .
    result = init_feed_db(&database, "example2.db", 1);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to create/open a test database: %s !\n", database.error_msg);
        goto clearup;
    }

    // Database layout setup.
    //
    // This function is, basically, a wrapper around a giant SQL query.
    // Ideally, it is done every once in a set time interval (day, probably),
    // as there is no need to do it every time some information is needed.
    //
    // Every time the database is updated,
    // it must be deleted (left to the developer).
    //
    // This function is most likely to be followed by store_feed_db(..) .
    result = setup_feed_db(&database, 0);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to create the layout of the test database: %s !\n", database.error_msg);
        goto clearup;
    }

    // Feed storing.
    // 
    // This function reads every feed file 
    // and reads its records directly into the database,
    // without an intermediate array.
    //
    // Unless CGTFS_STORING_BATCH_TRANSACTIONS_OFF is defined, each
    // file's contents are stored in a single transaction.
    //
    // Both FEED_DB_SUCCESS and FEED_DB_PARTIAL are acceptable results.
    // Use equality sign only if your feed has records in EVERY possible
    // feed file.
    result = store_feed_db("../tests/data/pocono_pony", &database, NULL);
    if (result < FEED_DB_SUCCESS) {
        printf("Failed to store a test gtfs directory: data/pocono_pony: %s !\n", database.error_msg);
        goto clearup;
    }

    // The querying itself.
    database.rc = sqlite3_exec(database.conn, sql_query, row_callback, NULL, &error_msg);
    if (error_msg != NULL) {
        printf("Error while executing query: %s !\n", error_msg);
        goto clearup;
    }
    
    printf("Success.\n");

    clearup:
    sqlite3_free(error_msg);
    free_feed_db(&database);
}

int row_callback(void *param, int column_count, char **data, char **column_names) {
    if (column_count < 3)
        return 1;
    
    printf("<stop %s>\n", data[0]);
    printf("  Arrival time:  %s\n", data[2]);
    printf("  Trip id:       %s\n", data[1]);

    return 0;
}

int main() {
    some_database_manipulation();
    return 0;
}