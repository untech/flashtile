//Name: IEvent.h
//Author: Stevie Frederick
//Desription: Simple interface for most Base Event definition for use in the
//MasterControl mini-kernel

//Class auto-generation

class BaseEvent{
public:
virtual int getSubID() = 0;

private:
static int subID;

};
