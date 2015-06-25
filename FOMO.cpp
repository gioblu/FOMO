
 /* FOMO  */

#include "FOMO.h"
#include <avr/power.h>

FOMO::FOMO(boolean debug) {


  this->add_process(this->update_duration, )

};

/* Add to instance_name.sensors a new sensor

   update_funciton: function that updates sensor value (you should write it by yourself)
   interval:        time interval between every update_function call */

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

/* Remove sensor from instance_name.sensors 
   (can't be reversed so please understand the implications of this)

   id: the id of the sensor you want to remove */

int FOMO::remove_sensor(uint8_t id) {
  this->sensors[id].empty = true;
};

/* Activate sensor update process 
   (can be deactivated with deactivate_sensor function)

   id: the id of the sensor you want to disable */


int FOMO::activate_sensor(uint8_t id) {
  return this->activate_process(this->sensors[id].process_id);
};


/* Deactivate sensor update process 
   (can be reactivated with activate_sensor function)

   id: the id of the sensor you want to activate */

int FOMO::deactivate_sensor(uint8_t id) {
  return this->deactivate_process(this->sensors[id].process_id);
};


int FOMO::report_problem(byte problem) {
  for(byte i = 0; i < 20; i++)
    if(this->state->mission->problems[i] == NO_PROBLEM) {
      this->state->mission->problems[i] = problem;
      return DONE;
    }
  return TOO_MUCH_PROBLEMS;
};