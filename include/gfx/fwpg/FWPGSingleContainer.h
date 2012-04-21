// FWPGSingleContainer.h by Paul Jones on 4.21.2012

#pragma once
#ifndef PJ_FWP_GFX_FWPG_FWPGSINGLECONTAINER_H
#define PJ_FWP_GFX_FWPG_FWPGSINGLECONTAINER_H

#include "FWPGContainer.h"

class FWPGSingleContainer : public FWPGContainer {
  FWPGComponent *child_;
  uint16_t padding_;
public:
  void add(FWPGComponent *com);
  FWPGComponent *getContents();
  uint16_t getMinWidth();
  uint16_t getMinHeight();
  FWPGSingleContainer() : padding_(0), child_(NULL) {}
  FWPGSingleContainer(uint16_t padding) : padding_(padding), child_(NULL) {}
};

#endif // PJ_FWP_GFX_FWPG_FWPGSINGLECONTAINER_H