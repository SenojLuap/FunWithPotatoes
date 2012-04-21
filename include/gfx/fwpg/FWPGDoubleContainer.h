// FWPGDoubleContainer.h by Paul Jones on 4.21.2012

#pragma once
#ifndef PJ_FWP_GFX_FWPG_FWPGDOUBLECONTAINER_H
#define PJ_FWP_GFX_FWPG_FWPGDOUBLECONTAINER_H

#include "FWPGContainer.h"

class FWPGDoubleContainer : public FWPGContainer {
  FWPGComponent *child1_, *child2_;
  uint16_t externalPadding_, individualPadding_;
  bool horizontal_;
public:
  // If the first child hasn't been assigned, this will assign 'com' to the
  // first child. Othewise, it assigns it to the second child
  void add(FWPGComponent *com);

  // Assigns com to the respective child
  void add1(FWPGComponent *com);
  void add2(FWPGComponent *com);

  uint16_t getMinWidth();
  uint16_t getMinHeight();

  FWPGComponent *get1();
  FWPGComponent *get2();

  void setVisible(bool visible, bool cascade);

  FWPGDoubleContainer(bool horizontal = false, uint16_t externalPadding = 0,
      uint16_t individualPadding = 0) : horizontal_(horizontal),
      externalPadding_(externalPadding), individualPadding_(individualPadding),
      child1_(NULL), child2_(NULL) {}
};

#endif // PJ_FWP_GFX_FWPG_FWPGDOUBLECONTAINER_H