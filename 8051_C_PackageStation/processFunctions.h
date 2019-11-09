void initIOs(void)
{
	startConveyors			 		 = false;
	palletizerChainBack		 	 = false;
	palletizerChainForw		 	 = false;
	palletizerConvBack		 	 = false;
	palletizerConvForw		 	 = false;
	palletizerOpen			 		 = false;
	palletizerClamp			 		 = false;
	palletizerElevatorDown	 = false;
	palletizerElevatorUp		 = false;
	palletizerPush			 		 = false;
	palletizerElevMoveLimit	 = false;
	startRollerConveyors		 = false;
	emitter1								 = false;
	emitter2								 = false;
	greenLight							 = false;
	redLight								 = false;
	siren										 = false;
	elevatorUp							 = false;
	elevatorDown						 = false;
	elevatorBack						 = false;
	elevatorForw						 = false;
	startButtonLight				 = false;
}

void stopConveyors(void)
{
	startConveyors = false;
	startRollerConveyors = false;	
}

void stopElevators(void)
{
	elevatorUp = false;
	elevatorDown = false;
	elevatorBack = false;
	elevatorForw = false;
}

void stopPalletizer(void)
{
	palletizerChainBack = false;
	palletizerChainForw = false;
	palletizerConvBack = false;
	palletizerConvForw = false;
	palletizerOpen = false;
	palletizerClamp = false;
	palletizerElevatorDown = false;
	palletizerElevatorUp = false;
	palletizerPush = false;
	palletizerElevMoveLimit = false;
}

void errorLight(void)
{
	redLight = true;
	greenLight = false;

}

void runLight(void)
{
	redLight = false;
	greenLight = true;
}

void noLight(void)
{
	redLight = false;
	greenLight = false;
}
