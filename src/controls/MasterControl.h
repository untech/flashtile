//File: Master Control
//Author: Stevie
//Desription: The Master Control serves as an interface to the main controls
//of a micro-engine. The pipe to and from the input queue is the heaviest
//device. A plan is already in place to have the device schedule tasks for 
//concurrency, and optimizing dispatch-to-invoke calltimes. 


//The core idea of this class is to take events and resolve them to a control
//mechanism that can invoke calls onto the model and renderer. This master
//would be considered main() to some as it serves as the entry point hook to 
//the engine
#ifndef MASTERCONTROL_H
#define MASTERCONTROL_H


 #include "IController.h"
 #include "IEvent.h"
 #include "RegistryEntry.h"
 
class MasterControl{
public:
//Queue control
virtual void pumpQueue() = 0;
virtual void pushToQueue(BaseEvent* event) = 0;
virtual void dumpQueue() = 0;

//Controller aggregation and assignment
virtual void addController(BaseController* controller) = 0;
virtual void removeController(int iD) = 0;

//the two master controllers
virtual void assignRender(int (*renderFunc)(void)) = 0;
virtual void assignFrame(int (*frameFunc)(void)) = 0;

//hillside
virtual void registerController(BaseEvent* event, int iD) = 0;
virtual void unregisterController(int iD) = 0;


};

extern MasterControl* createMiniKernel();

#endif
