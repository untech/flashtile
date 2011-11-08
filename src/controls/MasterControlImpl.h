//Class: Master Control Implementation
//Author: Stevie
//Description: Use this class as the main implementation of the master control
//and aggregate mini-kernel. Place extensions here if needed.

#include <vector.h>

class MasterControlImpl: public MasterControl{
public:
//Queue control
virtual void pumpQueue();
virtual void pushToQueue(BaseEvent* event);
virtual void dumpQueue();

//Controller aggregation and assignment
virtual int addController(BaseController* controller);
virtual void removeController(int iD);

//the two master controllers
virtual void assignRender(int (*renderFunc)(void));
virtual void assignFrame(int (*frameFunc)(void));

//hillside
virtual void registerController(BaseEvent* event, int iD);
virtual void unregisterController(int iD);

private:
std::vector<BaseEvent*> eventQueue;

std::vector<BaseController*> controllerRegistry;
std::vector<RegistryEntry> indexRegistry;

};