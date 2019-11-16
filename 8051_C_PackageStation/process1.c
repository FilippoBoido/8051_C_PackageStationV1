#include "processVars.h"
#include "io.h"
#include "utilities.h"

void process1(uchar* procHandshake)
{
	switch (step1)
	{
		case 0:

			startConveyors = true;

			step1 = 10;

			break;

		case 10:

			if(fTrig(packageDetected))
			{ 
				packageCounter++;
				palletizerConvForw = true;
			}

			if (packageCounter > MAX_COUNTER)
			{
				packageCounter = 0;		

				step1 = 20;
			}

			break;

		case 20:
	
			retVal = delay(4000, &palletizerTimer);
			if (retVal == 1)
			{
				retVal = 0;
				palletizerTimer = 0;
				startConveyors = false;

				step1 = 30;
			}

			break;

		case 30:

			retVal = delay(1000, &palletizerTimer);
			if (retVal == 1)
			{
				retVal = 0;
				palletizerTimer = 0;
				palletizerPush = true;

				step1 = 40;
			}

			break;

		case 40:

			retVal = delay(1500, &palletizerTimer);
			if (retVal == 1)
			{
				retVal = 0;
				palletizerTimer = 0;
				palletizerPush = false;

				step1 = 50;
			}

			break;

		case 50:

			if(secondRound == true)
			{
				secondRound = false;
				step1 = 60;
				
			}
			else
			{
				secondRound = true;
				step1 = 0;
			}

			break;
		
		case 60:

			break;
	};
}