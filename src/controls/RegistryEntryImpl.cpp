#include "RegistryEntry.h"

RegistryEntry::RegistryEntry(int controlID, int eventID){
this->eventID = eventID;
this->controlID = controlID;
}

int getControlID(){
return controlID;
}

int getEventID(){
return eventID;
}

void setEventID(int subID){
this->eventID = subID;
}
