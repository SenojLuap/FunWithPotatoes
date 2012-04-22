// FWPGVectorContainer.h by Paul Jones on 4.22.2012

#pragma once
#ifndef PJ_FWP_GFX_FWPG_FWPGVECTORCONTAINER_H
#define PJ_FWP_GFX_FWPG_FWPGVECTORCONTAINER_H

#include <boost\ptr_container\ptr_vector.hpp>
#include "FWPGContainer.h"

class FWPGVectorContainer : public FWPGContainer {
  boost::ptr_vector<FWPGComponent> children_;
  uint16_t externalPadding_, individualPadding_;
  bool horizontal_;
public:
  void add(FWPGComponent *com);
  FWPGComponent *get(size_t index);
  uint16_t getMinWidth();
  uint16_t getMinHeight();
  void setVisible(bool visible, bool cascade);
  FWPGVectorContainer(bool horizontal = false, uint16_t externalPadding = 0,
      uint16_t individualPadding = 0);
};

#endif