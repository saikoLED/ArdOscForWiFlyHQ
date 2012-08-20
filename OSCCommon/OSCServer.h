/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 -------- Lisence -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 */

#ifndef ArdOSC_OSCServer2_h
#define ArdOSC_OSCServer2_h


#include "OSCcommon.h"
#include "OSCMessage.h"
#include "OSCDecoder.h"
#include "Pattern.h"

#include "../WiFlyHQ/WiFlyHQ.h"



class OSCServer{
    
private:

    WiFly* wiFly;

    char _rcvData[kMaxRecieveData];

    OSCDecoder::OSCDecoder _decoder;
    Pattern::Pattern _adrMatch;

public:
    
    OSCServer(WiFly* wiFly);
    ~OSCServer(void);
    
    int availableCheck(void);

    //_adr osc address string pointer - "/ard/aaa"
    //_func callback function pointer
    void addCallback(char *_adr , Pattern::AdrFunc _func);
	void addOscMessageSink(OscMessageSink* sink );

};


#endif
