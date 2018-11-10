typedef enum WheelchairAccessible {
    UNKNOWN,
    POSSIBLE,
    NOT_POSSIBLE
} wheelchair_accessible_t;

typedef enum BikesAllowed {
    UNKNOWN,
    POSSIBLE,
    NOT_POSSIBLE
} bikes_allowed_t;

typedef struct Trip {
    char id[64];
    char route_id[64];
    char service_id[64];
    char headsign[64];
    char short_name[64];
    unsigned int direction_id;
    char block_id[64];
    char shape_id[64];
    wheelchair_accessible_t wheelchair_accessible;
    bikes_allowed_t bikes_allowed;
} trip_t;
