
 /* FOMO  */

#include "FOMO.h"
#include <avr/power.h>

FOMO::FOMO(boolean debug) {

};

int FOMO::add_sensor(void (*update_function)(void), unsigned long interval) {
  int id = ID_NOT_AVAILABLE;

  for(byte i = 0; i < 255; i++)
    if(this->sensors[i].empty) {
      id = i;
      this->sensors[i].empty = false;
    }

  if(id == ID_NOT_AVAILABLE) {
    return ID_NOT_AVAILABLE;
  } else { 
    Sensor sensor;
    sensor.update_function  = *update_function;
    sensor.id = (uint8_t)id;
    if(interval) {
      sensor.interval = interval;
      int process_id = this->add_process(update_function, interval);
     
      if(process_id == PROCESS_ID_NOT_AVAILABLE)
        return PROCESS_ID_NOT_AVAILABLE;

      sensor.process_id = (uint8_t)process_id;
    }

    this->sensors[id] = sensor;
    return id;  
  }
};

int FOMO::disable_sensor(uint8_t id) {
  this->sensors[id].empty = true;
}

