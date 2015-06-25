
/* Necessary data types */

typedef struct {
  unsigned long duration;
  uint8_t       phase;
  uint8_t[20]   problems; 
 } Mission;


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
  uint8_t      mode;
  Mission      mission;
  Sensor[20]   sensors;
  Data         data;
} State;


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
