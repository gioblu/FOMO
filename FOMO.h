
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
  #include "LowPower.h"   
#endif

#define FULL_OPERATIONAL  0
#define HIBERNATION       1

class FOMO {

  public:
    FOMO(boolean debug);
    
    Agenda scheduler;
    State  state;

  private:

};
