#include "MasterControlImpl.h"


//definitions go here

void MasterControlImpl::pumpQueue(){
//get top list element
BaseEvent* t_evntPtr = eventQueue.back();
eventQueue.pop_back();

//compare to registry and find controller


}

void MasterControlImpl::pushToQueue(BaseEvent* event){
std::vector<BaseEvent*>::iterator t_it = eventQueue.begin();
eventQueue.insert(t_it, event);
}


