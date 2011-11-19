//Class: Master Control Implementation
//Author: Stevie
//Description: Use this class as the main implementation of the master control
//and aggregate mini-kernel. Place extensions here if needed.
#ifndef MASTERCONTROLIMPL_H_
#define MASTERCONTROLIMPL_H_

#include <vector>
#include "MasterControl.h"

class MasterControlImpl: public MasterControl{
//interface exposed methods
public:
//Queue control
virtual void pumpQueue();
virtual void pushToQueue(BaseEvent* event);
virtual void dumpQueue();

//Controller aggregation and assignment
virtual void addController(BaseController* controller);
virtual void removeController(int iD);

//the two master controllers
virtual void assignRender(int (*renderFunc)(void));
virtual void assignFrame(int (*frameFunc)(void));

//hillside
virtual void registerController(BaseEvent* event, int iD);
virtual void unregisterController(int iD);

virtual void Release();

int SearchIndex(int ID);

//public for external interface instantiation 
static MasterControlImpl* InterfaceGet();

//Internally used functions should be private
//All member variables SHOULD be private
//try to maintain this privacy schema

private:
inline MasterControlImpl();

std::vector<BaseEvent*> eventQueue;

std::vector<BaseController*> controllerRegistry;
std::vector<RegistryEntry*> indexRegistry;

};

extern MasterControlImpl* pICtl;

#endif
