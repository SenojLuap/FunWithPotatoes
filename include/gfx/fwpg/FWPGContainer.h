// FWPGContainer.h by Paul Jones on 4.21.2012

#pragma once
#ifndef PJ_FWP_GFX_FWPG_FWPGCONTAINER_H
#define PJ_FWP_GFX_FWPG_FWPGCONTAINER_H

#include "FWPGComponent.h"

class FWPGContainer : public FWPGComponent {
public:
  virtual void add(FWPGComponent *com) = 0;
};

#endif // PJ_FWP_GFX_FWPG_FWPGCONTAINER_H