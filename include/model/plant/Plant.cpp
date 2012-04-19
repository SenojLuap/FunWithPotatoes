// Plant.h by Paul Jones on 4.14.2012
/* The Plant class is the base class for all crop-like plants such as Corn and
 * Potato. */

#pragma once
#ifndef PJ_FWP_MODEL_PLANT_PLANT_H
#define PJ_FWP_MODEL_PLANT_PLANT_H

#include <cstdint>

class Plant {
  uint8_t growth_;
  uint8_t fertilization_;
  uint32_t ghostTimer_;
  bool identified;
  //GameEngine *gameEngine;
  Plant *infector_;
public:
  // TODO Verify type used for time
  virtual void tick(uint32_t msec)=0;
};

#endif // PJ_FWP_MODEL_PLANT_PLANT_H