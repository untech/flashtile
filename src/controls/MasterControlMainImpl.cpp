#include "MasterControlImpl.h"

//This is for reference counting
MasterControlImpl* pICtl = 0;
int pIRef = 0;

//definitions go here

//TODO: Fuck I just realized I'm going to need a search function
//to search the registry index. This will be interalized in the 
//implementation

void MasterControlImpl::addController(BaseController* controller){
//create new registry entry and assign it a controller
RegistryEntry* regEntry = new RegistryEntry(controller->getSubID(),0);
std::vector<RegistryEntry*>::iterator r_it = indexRegistry.begin();
indexRegistry.insert(r_it, regEntry);


}

void MasterControlImpl::pumpQueue(){
//get top list element
BaseEvent* t_evntPtr = eventQueue.back();
eventQueue.pop_back();

//compare to registry and find controller
int tempID = t_evntPtr->getSubID();
//get controller from memory

}


void MasterControlImpl::pushToQueue(BaseEvent* event){
std::vector<BaseEvent*>::iterator t_it = eventQueue.begin();
eventQueue.insert(t_it, event);
}

MasterControl* createMiniKernel(){
return (MasterControl*)MasterControlImpl::InterfaceGet;
}

MasterControlImpl* MasterControlImpl::InterfaceGet(){
if(!pICtl)
pICtl = new MasterControlImpl();

pIRef++;
return pICtl;
}


int MasterControlImpl::SearchIndex(int subID){
//dummy placement
int index = -1;
//start pseudo code
//for(size of the vector){
//pull out element and check for subID
//}
return index;
}

void MasterControlImpl::Release(){
pIRef--;

if(!pICtl){
delete pICtl;
pIRef = 0;
}

}

MasterControlImpl::MasterControlImpl(){


}
