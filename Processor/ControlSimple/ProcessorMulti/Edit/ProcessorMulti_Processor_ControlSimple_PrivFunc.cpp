//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_ControlSimple_PrivFunc.h"
#include "../control.h"
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_ControlSimple_Params * params=(ProcessorMulti_Processor_ControlSimple_Params *)paramsPtr;
	ProcessorMulti_Processor_ControlSimple_Vars * vars=(ProcessorMulti_Processor_ControlSimple_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, lowSpeed);
    GetParamValue(xmlloader, params, midSpeed);
    GetParamValue(xmlloader, params, highSpeed);
    GetParamValue(xmlloader, params, stopPWM);

    GetParamValue(xmlloader, vars, WheelBase);
    GetParamValue(xmlloader, vars, WheelRadius);
    GetParamValue(xmlloader, vars, KpAngle);
    GetParamValue(xmlloader, vars, speedAcc);
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_ControlSimple_Params * params=(ProcessorMulti_Processor_ControlSimple_Params *)paramsPtr;
	ProcessorMulti_Processor_ControlSimple_Vars * vars=(ProcessorMulti_Processor_ControlSimple_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMulti_Processor_ControlSimple_Params * params=(ProcessorMulti_Processor_ControlSimple_Params *)paramsPtr;
	ProcessorMulti_Processor_ControlSimple_Vars * vars=(ProcessorMulti_Processor_ControlSimple_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	ProcessorMulti_Processor_ControlSimple_Params * params=(ProcessorMulti_Processor_ControlSimple_Params *)paramsPtr;
	ProcessorMulti_Processor_ControlSimple_Vars * vars=(ProcessorMulti_Processor_ControlSimple_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_ControlSimple_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_ControlSimple_Params * params=(ProcessorMulti_Processor_ControlSimple_Params *)paramsPtr;
	ProcessorMulti_Processor_ControlSimple_Vars * vars=(ProcessorMulti_Processor_ControlSimple_Vars *)varsPtr;
	inputDataSize=QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_Detect_Params, Data_Type = ProcessorMulti_Processor_Detect_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_ControlSimple_Params * params=(ProcessorMulti_Processor_ControlSimple_Params *)paramsPtr;
	ProcessorMulti_Processor_ControlSimple_Vars * vars=(ProcessorMulti_Processor_ControlSimple_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_Detect_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorInternalEvent_Sensor_Joystick_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<ProcessorMulti_Processor_Detect_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorInternalEvent_Sensor_Joystick_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Processor_ControlSimple_Data * outputdata=(ProcessorMulti_Processor_ControlSimple_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    SensorInternalEvent_Sensor_Joystick_Data* joystickdata = inputdata_1.front();
    ProcessorMulti_Processor_Detect_Data* pathdata = inputdata_0.front();

    if(pathdata->stop == 1)
    {
        vars->left_vel  = joystickdata->linear_vel + vars->WheelBase * joystickdata->angular_vel / 2;
        vars->right_vel = joystickdata->linear_vel - vars->WheelBase * joystickdata->angular_vel / 2;
        outputdata->left_motor = vars->left_vel * 1376.9 + 214.5;
        outputdata->right_motor = vars->right_vel * 1376.9 + 214.5;
        outputdata->isManualControl = 1;
        outputdata->left_vel = vars->left_vel;
        outputdata->right_vel = vars->right_vel;
        return 1;
    }

    short left_motor;
    short right_motor;

    double hx = cos(pathdata->start_x);
    double hy = sin(pathdata->start_y);
    double tx = pathdata->end_x, ty = pathdata->end_y;

    if(joystickdata->manual_control == 1)
    {
        vars->left_vel  = joystickdata->linear_vel + vars->WheelBase * joystickdata->angular_vel / 2;
        vars->right_vel = joystickdata->linear_vel - vars->WheelBase * joystickdata->angular_vel / 2;
        left_motor = vars->left_vel * 1376.9 + 214.5;
        right_motor = vars->right_vel * 1376.9 + 214.5;
        outputdata->left_vel = vars->left_vel;
        outputdata->right_vel = vars->right_vel;
    }
    else
    {
        vars->lastSpeed = vars->assignedSpeed;
        vars->assignedSpeed = params->midSpeed;

        //以固定的加速度来调节速度
        if(vars->lastSpeed != vars->assignedSpeed)
        {
            if(vars->lastSpeed < vars->assignedSpeed)
            {
                if(vars->speedAcc < 0) //加速过程，加速度大于0
                    vars->speedAcc = -vars->speedAcc;
                vars->lowSpeedThresh  = vars->lastSpeed;
                vars->highSpeedThresh = vars->assignedSpeed;
            }
            else
            {
                if(vars->speedAcc > 0) //减速过程，加速度小于0
                    vars->speedAcc = -vars->speedAcc;
                vars->lowSpeedThresh  = vars->assignedSpeed;
                vars->highSpeedThresh = vars->lastSpeed;
            }
            vars->targetSpeed = vars->lastSpeed;
        }
        //以固定的加速度来调节速度
        vars->targetSpeed = vars->targetSpeed + vars->speedAcc;

        vars->targetSpeed = vars->targetSpeed > vars->highSpeedThresh ?
                    vars->highSpeedThresh:vars->targetSpeed;

        vars->targetSpeed = vars->targetSpeed < vars->lowSpeedThresh ?
                    vars->lowSpeedThresh:vars->targetSpeed;


        generateControlCmd(vars, pathdata->start_x, pathdata->start_y, hx, hy, tx, ty);

        if(pathdata->stop == 1)
        {
            left_motor = right_motor = (short)params->stopPWM;
            outputdata->left_vel = outputdata->right_vel = 0;
        }
        else
        {
            left_motor = vars->left_vel * 1376.9 + 214.5;
            right_motor = vars->right_vel * 1376.9 + 214.5;

            outputdata->left_vel = vars->left_vel;
            outputdata->right_vel = vars->right_vel;
        }
    }

    outputdata->left_motor = left_motor;
    outputdata->right_motor = right_motor;
    outputdata->isManualControl = joystickdata->manual_control;
	return 1;
}

