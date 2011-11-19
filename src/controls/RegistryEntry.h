//This class is just a hack until there is a better way of doing key value 
//stores in memory with sufficient abstraction and efficiency, and not a 
//sacrifice between the two
#ifndef REGISTRY_ENTRY_H
#define REGISTRY_ENTRY_H

class RegistryEntry{
public: 
RegistryEntry(int controlID, int eventID);
int getControlID();
int getEventID();

void setEventID(int subID);

private:
static int controlID;
static int eventID;

};

#endif
