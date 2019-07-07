/**
 * @file
 * @brief    No-code-file for documentation structure purposes.
 */


/**
 * @defgroup    Core    Core layer
 * @brief       CGTFS' basic functionality.
 */

/**
 * @defgroup    Database    Database layer
 * @brief       CGTFS' database functionality.
 */

/**
 * @defgroup    Utilities    Utilities
 * @brief       All utilitary functionality
 *
 * Things which are not directly related to GTFS
 * but are crucial for the library operation.
 */

/**
 * @defgroup    Helpers    Helpers
 * @brief       Minor auxiliary functionality
 *
 * Things which are not directly related to GTFS
 * and are not important enough
 * to be considered utilitary.
 */



/**
 * @ingroup     Core
 * @defgroup    Core__FeedEntity    Feed entity
 * @brief       The core entity representing a GTFS feed.
 */


/**
 * @ingroup     Core
 * @defgroup    Core__Entity    GTFS entities
 * @brief       Functions which handle GTFS entities.
 */

/**
 * @ingroup     Core__Entity
 * @defgroup    Core__EntityTypes    Types
 * @brief       Structures representing basic GTFS entities.
 */

/**
 * @ingroup     Core__Entity
 * @defgroup    Core__EntityList    Entities handling
 * @brief       Functionality related to each particular entity.
 *
 * For each type of entity, CGTFS provides the following:
 *
 *   - typedef'ed structure (T);
 *   - `init_T(T *)` function which initializes the struct's fields
 *     with default values (strings with "", numerics with 0,
 *     enumerations with default values);
 *   - `read_T(T *, int, const char **, const char**)` function which can fill the structure from
 *     an array of field names and field values (provided in the same order);
 *   - typedef'ed enums for field enumerations (when present),
 *     and functions for parsing the enumeration value from c-strings.
 */

/**
 * @ingroup     Core
 * @defgroup    Core__EntityFileReading    Batch entity reading
 * @brief       Functions to parse entire feed files into record arrays.
 */


/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__Agency    Agency
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__CalendarDate    Calendar date
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__CalendarRecord    Calendar record
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__FareAttributes    Fare attributes
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__FareRule    Fare rule
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__FeedInfo    Feed information
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__Frequency    Frequency
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__Route    Route
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__Shape    Shape
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__StopTime    Stop time
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__Stop    Stop
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__Transfer    Transfer
 */

/**
 * @ingroup     Core__EntityList
 * @defgroup    Core__EntityList__Trip    Trip
 */



/**
 * @ingroup     Database
 * @defgroup    Database__Types    Types
 * @brief       Core types used in feed database manipulation.
 */

/**
 * @ingroup     Database
 * @defgroup    Database__FeedEntity    Feed entity
 * @brief       The core entity around the database connection.
 */

/**
 * @ingroup     Database
 * @defgroup    Database__EntityStoring    Entity storing
 * @brief       Functions which store enitities
 *              into the feed database on a singular basis.
 */

/**
 * @ingroup     Database
 * @defgroup    Database__TableOps    Table operations
 * @brief       Functions for manipulating entire feed database tables.
 */

/**
 * @ingroup     Database__TableOps
 * @defgroup    Database__TableFetching    Fetching
 * @brief       Functions for retrieving entire database tables.
 */

/**
 * @ingroup     Database__TableOps
 * @defgroup    Database__TableStoring    Storing
 * @brief       Functions for storing entire database tables.
 */



/**
 * @ingroup     Utilities
 * @defgroup    Utilities__File    File utilities
 * @brief       File I/O utilities.
 */

/**
 * @ingroup     Utilities
 * @defgroup    Utilities__Memory    Memory utilities
 * @brief       Memory handling utilities.
 */

/**
 * @ingroup     Utilities Database
 * @defgroup    Utils__Database    Database utilities
 * @brief       Database-related utilities
 */

