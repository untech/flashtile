#include "RegistryEntry.h"

RegistryEntry::RegistryEntry(int controlID, int eventID){
this->eventID = eventID;
this->controlID = controlID;
}

int RegistryEntry::getControlID(){
return controlID;
}

int RegistryEntry::getEventID(){
return eventID;
}

void RegistryEntry::setEventID(int subID){
this->eventID = subID;
}
