
 /* FOMO  */

#include "FOMO.h"

FOMO::FOMO() {

};


void FOMO::update() {
  this->state.duration = millis() / 1000;
};


int FOMO::report_problem(byte problem) {
  for(byte i = 0; i < 20; i++)
    if(this->problems[i] == NO_PROBLEM) {
      this->problems[i] = problem;
      return DONE;
    }
  return TOO_MUCH_PROBLEMS;
};


void FOMO::hibernation() {
  this->state.mode = HIBERNATION;
};


void FOMO::full_operational() {
  this->state.mode = FULL_OPERATIONAL;
};

