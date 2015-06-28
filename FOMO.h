
 /* FOMO */

#ifndef FOMO_h
  #define FOMO_h

  #if defined(ARDUINO) && (ARDUINO >= 100)
    #include "Arduino.h"
  #else
    #include "WProgram.h"
    #include "WConstants.h"
  #endif
  
  #include "includes/data_types.h"
  #include "includes/Agenda/Agenda.h"
  #include "includes/Low-Power/LowPower.h"   
#endif

#define FULL_OPERATIONAL           1
#define HIBERNATION                0
#define ID_NOT_AVAILABLE           2
#define PROCESS_ID_NOT_AVAILABLE  -1
#define NO_PROBLEM                 3
#define TOO_MUCH_PROBLEMS          4

class FOMO {

  public:
    FOMO(boolean debug);
    
    Agenda  scheduler;
    Data    data;
    State   state;
    uint8_t problems[20]; 
    Sensor  sensors[20];

    int  add_sensor(void (*update_function)(void), unsigned long interval);
    int  remove_sensor(uint8_t id);
    int  activate_sensor(uint8_t id);
    int  deactivate_sensor(uint8_t id);
    int  report_problem(byte problem);
    void hibernation_mode();
    void full_operational_mode();
  
  private:
    void update_duration();

};
