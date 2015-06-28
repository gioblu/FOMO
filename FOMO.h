
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
#endif

#define FULL_OPERATIONAL           1
#define HIBERNATION                0
#define NO_PROBLEM                 3
#define TOO_MUCH_PROBLEMS          4
#define DONE                       5

class FOMO {

  public:
    FOMO();
    
    Data    data;
    State   state;
    uint8_t problems[20]; 
    
    int  report_problem(byte problem);
    void hibernation();
    void full_operational();
    void update();
  
  private:

};
