// SignalListener.h by Paul Jones on 4.19.2012

#pragma once
#ifndef PJ_FWP_GFX_FWPG_SIGNALLISTENER_H
#define PJ_FWP_GFX_FWPG_SIGNALLISTENER_H

struct Signal;

class SignalListener {
public:
  virtual void onSignal(Signal sig)=0;
};

#endif // PJ_FWP_GFX_FWPG_SIGNALLISTENER_H