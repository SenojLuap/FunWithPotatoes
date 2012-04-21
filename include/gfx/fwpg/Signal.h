// Signal.h by Paul Jones on 4.19.2012

#pragma once
#ifndef PJ_FWP_GFX_FWPG_SIGNAL_H
#define PJ_FWP_GFX_FWPG_SIGNAL_H

#include <string>
#include "FWPGComponent.h"

struct Signal {
  FWPGComponent *source;
  std::string signal;
  Signal(FWPGComponent *source, const std::string signal);
};

#endif // PJ_FWP_GFX_FWPG_SIGNAL_H