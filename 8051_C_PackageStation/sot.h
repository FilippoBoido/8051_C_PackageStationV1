#ifndef SOT_H
#define SOT_H

struct ST_SotPayload 
{
		unsigned char aSotPayload[11];
};

enum 
{ 
	eSotOut_Status = 1,
	eSotOut_Info,
	eSotOut_Ind,
	eSotOut_Req,
	eSotOut_P0,
	eSotOut_P1,
	eSotOut_P2,
	eSotOut_P3,
	eSotOut_EndMes = 10
};

enum
{
	eSotIn_SlaveMode = 1,
	eSotIn_Command,
	eSotIn_IOConfig,
	eSotIn_P0,
	eSotIn_P1,
	eSotIn_P2,
	eSotIn_P3,
	eSotIn_EndMes = 10
};

enum
{
	eSotIOConfig_0In4Out = 1,
	eSotIOConfig_1In3Out,
	eSotIOConfig_2In2Out,
	eSotIOConfig_3In1Out,
	eSotIOConfig_4In0Out
};

enum
{
	eSotSlaveMode_zombie = 1,
	eSotSlaveMode_independent
};

#endif