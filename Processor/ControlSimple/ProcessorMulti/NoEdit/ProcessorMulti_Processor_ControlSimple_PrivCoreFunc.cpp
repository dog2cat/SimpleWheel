//Generally you need not to program this file.

#include "ProcessorMulti_Processor_ControlSimple_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=ProcessorMulti_Processor_ControlSimple_INPUTPORTSSIZE;
	outputPortsNumber=ProcessorMulti_Processor_ControlSimple_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_ControlSimple_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_ControlSimple_Vars());
	/*======No Need to Program======*/
}

