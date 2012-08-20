/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 -------- Lisence -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 */

#ifndef ArdOSC_patternmatch_h
#define ArdOSC_patternmatch_h

#define kMaxPatternMatch    50
#define kMaxSinks 50

#include "OSCMessage.h"
#include "Arduino.h"

/// OscMessageSinks are notified if a message with their adress is received
class OscMessageSink{
public:
	virtual const __FlashStringHelper* getAdress()=0;
	virtual void digestMessage(OSCMessage *_mes)=0;
};

class Pattern{
	
private:
    
    typedef void (*AdrFunc)(OSCMessage*);

    
    AdrFunc adrFunc[kMaxPatternMatch];
    OscMessageSink* sinks[kMaxPatternMatch];

	
	char *addr[kMaxPatternMatch];

    uint8_t patternNum;
	uint8_t sinkNum; 
public:
    
    Pattern();
    ~Pattern();
 
    
	void addOscAddress(char *_adr , AdrFunc _func );
	void addOscMessageSink(OscMessageSink* sink );
    void execFunc(uint8_t _index,OSCMessage *_mes);
    
    void paternComp(OSCMessage *_mes);
   
    friend class OSCServer;
};


#endif
