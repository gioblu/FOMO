
 /* FOMO */

#ifndef FOMO_h
  #define FOMO_h

  #if defined(ARDUINO) && (ARDUINO >= 100)
    #include "Arduino.h"
  #else
    #include "WProgram.h"
    #include "WConstants.h"
    #include "/includes/data_types.h"
  #endif
#endif


class FOMO {

  public:

    FOMO();
    State state;

  private:

};
