#include <reg51.h>

#ifndef IO_H
#define IO_H

sbit safetyOK					 			 		= P0^0;
sbit palletizerElevMoving		 		= P0^1;
sbit pallElevBackLimit			 		= P0^2;
sbit pallElevFrontLimit		 	 		= P0^3;
sbit elevatorRightLimit		 	 		= P0^4;
sbit elevatorLeftLimit			 		= P0^5;
sbit startButton				 		 		= P0^6;
sbit packageDetected			 	 		= P0^7;

sbit startConveyors			 		 		= P1^0;
sbit palletizerChainBack		 		= P1^1;
sbit palletizerChainForw		 		= P1^2;
sbit palletizerConvBack		 	 		= P1^3;
sbit palletizerConvForw		 	 		= P1^4;
sbit palletizerOpen			 		 		= P1^5;
sbit palletizerClamp			 	 		= P1^6;
sbit palletizerElevatorDown	 		= P1^7;

sbit palletizerElevatorUp		 		= P2^0;
sbit palletizerPush			 		 		= P2^1;
sbit palletizerElevMoveLimit 		= P2^2;
sbit startRollerConveyors		 		= P2^3;
sbit emitter1								 		= P2^4;
sbit emitter2								 		= P2^5;
sbit greenLight							 		= P2^6;
sbit redLight								 		= P2^7;

sbit serialRx								 		= P3^0;
sbit serialTx								 		= P3^1;
sbit siren									 		= P3^2;
sbit elevatorUp							 		= P3^3;
sbit elevatorDown						 		= P3^4;
sbit elevatorBack						 		= P3^5;
sbit elevatorForw						 		= P3^6;
sbit startButtonLight				 		= P3^7;

#endif