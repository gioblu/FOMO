
/* Necessary data types */

typedef struct {
  float         latitude;
  float         longitude;
  int           altitude;
} Position;


typedef struct {
  int          inside;
  int          board;
  int          outside;
} Temperature;


typedef struct {
  uint8_t      battery_voltage;
  uint8_t      input_voltage;
  int          light;
  float        heading;
  Position     position;
  int          pressure; 
  int          speed;
  Temperature  temperature; 
} Data;


typedef struct {
  unsigned long duration;
  uint8_t       mode;
  uint8_t       phase;
} State;