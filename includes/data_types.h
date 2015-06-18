
/* Necessary data types */

typedef struct {
  float latitude;
  float longitude;
  int   altitude;
 } Position;

typedef struct {
  int x;
  int y;
  int z;
 } Heading;

typedef struct {
  int inside;
  int board;
  int outside;
 } Temperature;

typedef struct {
  uint8_t     mode;
  Heading     heading;
  Position    position;
  int         speed;
  uint8_t     fv_panel_voltage;
  uint8_t     battery_voltage;
  int         pressure; 
  Temperature temperature; 
  uint8_t     light;
 } State;