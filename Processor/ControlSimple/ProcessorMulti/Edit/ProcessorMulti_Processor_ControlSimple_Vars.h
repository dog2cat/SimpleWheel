//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_CONTROLSIMPLE_VARS_H
#define PROCESSORMULTI_PROCESSOR_CONTROLSIMPLE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_ControlSimple_Vars ProcessorMulti_Processor_ControlSimple_Vars
	\ingroup ProcessorMulti_Processor_ControlSimple
	\brief ProcessorMulti_Processor_ControlSimple_Vars defines the Vars in ProcessorMulti_Processor_ControlSimple.
*/

/*! \addtogroup ProcessorMulti_Processor_ControlSimple_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_ControlSimple_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_ControlSimple
*/

//*******************Please add other headers below*******************


#include "ProcessorMulti_Processor_ControlSimple_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_ControlSimple_Vars 
	\brief The Vars of ProcessorMulti_Processor_ControlSimple.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_ControlSimple_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_ControlSimple_Vars()
		\brief The constructor of ProcessorMulti_Processor_ControlSimple_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_ControlSimple_Vars() 
	{
        WheelBase = 0.576;
        WheelRadius = 0.1735;
        assignedSpeed = 0.5;
        left_vel = right_vel = 0;
        KpAngle = 7.0;
        targetSpeed = lastSpeed = lowSpeedThresh = highSpeedThresh = 0;
        speedAcc = 0.02;
	}
	/*! \fn ~ProcessorMulti_Processor_ControlSimple_Vars()
		\brief The destructor of ProcessorMulti_Processor_ControlSimple_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_ControlSimple_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double WheelBase, WheelRadius;
    double assignedSpeed, targetSpeed;
    double left_vel, right_vel;
    double KpAngle;
    double lastSpeed, lowSpeedThresh, highSpeedThresh;
    double speedAcc;
};

/*! @}*/ 

#endif