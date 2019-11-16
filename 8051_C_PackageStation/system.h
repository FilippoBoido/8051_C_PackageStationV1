#ifndef SYSTEM_H
#define SYSTEM_H

#define PAYLOAD_LENGTH 			10
#define PAYLOAD_RECEIVED		11

typedef unsigned char uchar;
typedef unsigned int uint;

enum { false, true };

extern bit __systemError;// = 0xA7;
extern bit __protocolError;// = 0xB2;


extern uchar counterRead;
extern uchar counterWrite;

extern bit sendSotPayload;
 
extern struct ST_SotPayload stSotPayloadOut;
extern struct ST_SotPayload stSotPayloadIn;
extern struct ST_SotPayload stEmptyPayload;


extern void init(void);
extern void cycleStart(void);


/*
	When the message has been received, counterRead equals PAYLOAD_RECEIVED (11).
	After processing input data of the payload, counterRead must be set to 1.

*/
extern uchar serialReceiveChar(void);
extern void serialSendChar(void);
extern uchar waitEndCycle(void);
extern uchar delay(uint delayInMs, uint* delayBuffer);

#endif