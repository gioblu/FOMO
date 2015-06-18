
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
  Heading     heading;
  Posiiton    position;
  Temperature temperature; 
  uint8_t     fv_panel_voltage;
  uint8_t     battery_voltage;
  int         pressure; 
  uint8_t     light;
 } State;