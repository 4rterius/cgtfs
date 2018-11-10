typedef enum LocationType {
    STOP,
    STATION,
    STATION_ENTRANCE_EXIT
} location_type_t;

typedef enum WheelchairBoarding {
    UNKNOWN,
    SOME,
    NOT_POSSIBLE
} wheelchair_boarding_t;

typedef struct Stop {
    char id[64];
    char code[64];
    char name[64];
    char desc[512];
    long double lat;
    long double lon;
    char zone_id[64];
    char url[128];
    location_type_t location_type;
    int parent_station;
    char timezone[64];
    wheelchair_boarding_t wheelchair_boarding;
} stop_t;
