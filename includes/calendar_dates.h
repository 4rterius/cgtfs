typedef enum ExceptionType {
    ADDED = 1,
    REMOVED = 2
} exception_type_t;

typedef struct CalendarDate {
    char service_id[64];
    char date[8];
    exception_type_t exception_type;
} calendar_date_t;
