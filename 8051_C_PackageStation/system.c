#include <reg51.h>
#include "sot.h"
#include "system.h"

bit __systemError;// = 0xA7;
bit __protocolError;// = 0xB2;


uchar counterRead = 1;
uchar counterWrite = 1;

bit sendSotPayload;

struct ST_SotPayload stSotPayloadOut;
struct ST_SotPayload stSotPayloadIn;
struct ST_SotPayload stEmptyPayload;


void init(void)
{
	__protocolError = 0;
	__systemError = 0;
	
	//standard configuration at start
	P0 = 0xFF;
	P1 = 0x00;
	P2 = 0x00;
	P3 = 0x03;

	SCON = 0x52;
	PCON = 0x80;
	TMOD = 0;
	TMOD |= 0x21;
	TH1 = 245;
	TR1 = 1;
	
	counterWrite = 1;
	counterRead = 1;
	sendSotPayload = 0;
				
}

void cycleStart(void)
{
	//Zeit zurücksetzen					
	TR0 = 0;					
	//1ms cycle					
	TL0 = 0xBF;
	TH0 = 0xFC;
	TF0 = 0;
	
	//starte den Timer
	TR0 = 1;
	
}

/*
	When the message has been received, counterRead equals PAYLOAD_RECEIVED (11).
	After processing input data of the payload, counterRead must be set to 1.

*/
uchar serialReceiveChar(void)
{
	P2 = counterRead;
	if(RI)
	{
		if(counterRead <= PAYLOAD_LENGTH)
		{
			stSotPayloadIn.aSotPayload[counterRead] = SBUF;
			
			counterRead++;
			RI = 0;
		}
		else
		{
			//wait for the system to send payload to master
			if(stSotPayloadIn.aSotPayload[PAYLOAD_LENGTH] == '@')
			{		
				//End message received
				return 1;
			}
			else
			{
				__protocolError = 1;
				return 2;
			}
		}		
	}
	
	return 0;
}

void serialSendChar(void)
{
	if(sendSotPayload)
	{
		if(TI)
		{
			SBUF = stSotPayloadOut.aSotPayload[counterWrite];
			if(counterWrite == PAYLOAD_LENGTH)
			{
				sendSotPayload = 0;
				counterWrite = 1;
			}
			else
				counterWrite++;
			
			TI = 0;
		}
	}
}

uchar waitEndCycle(void)
{
	/*
	 	check if tf0 is already set before starting the wait_end_cycle loop
	 	if tf0 is alread set it means that we have exceeded the cycle limit
	 	this will set the cycleTimeError and stop the machine
	
	*/
	if(!TF0)
	{
		//uchar retVal;
		
		//retVal = serialReceiveChar();
		//if(retVal == 1)
		//	__debugSignal1 = 1;
		
		//serialSendChar();
		while(!TF0);
		
		return 1;
	}
	else
	{
		__systemError = 1;
		return 2;
	}
}

uchar delay(uint delayInMs, uint* delayBuffer)
{
	//Null pointer exception
	if (delayBuffer == 0)
		return -1;

	if (delayInMs > *delayBuffer)
	{
		*delayBuffer = *delayBuffer+1;
		return 0;
	}
	else
	{
		return 1;
	}

}
