#include <reg51.h>
#include "io.h"
#include "processVars.h"
#include "processFunctions.h"
#include "process1.h"
#include "process2.h"

void main(void)
{
	init();
	initIOs();
	
	while (1)
	{

		cycleStart();
		
		if (safetyOK == true)
		{
			if (startButton == true)
			{
				runLight();
				process1(&procHandshake);
				process2(&procHandshake);

			}
			else
			{
				noLight();
				stopConveyors();
				stopElevators();
				stopPalletizer();
			}	
		}
		else
		{
			stopConveyors();
			stopElevators();
			stopPalletizer();
			errorLight();
		}

		
		waitEndCycle();
		
	}
}


