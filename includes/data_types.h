
/* Necessary data types */

typedef struct {
  float         latitude;
  float         longitude;
  int           altitude;
} Position;


typedef struct {
  int          x;
  int          y;
  int          z;
} Heading;


typedef struct {
  int          inside;
  int          board;
  int          outside;
} Temperature;


typedef struct {
  uint8_t      battery_voltage;
  uint8_t      fv_panel_voltage;
  int          light;
  Heading      heading;
  Position     position;
  int          pressure; 
  int          speed;
  Temperature  temperature; 
} Data;


typedef struct {
  uint8_t      process_id;
  uint8_t      sensor_id;
  void         (*update_function)();
  boolean      empty;
} Sensor;


typedef struct {
  Data          data;
  unsigned long duration;
  uint8_t       mode;
  uint8_t       phase;
  uint8_t       problems[20]; 
  Sensor        sensors[20];
} State;