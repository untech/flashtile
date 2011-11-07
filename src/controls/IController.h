//name: IEvent
//author: Stevie
//purpose: A controller which is bound to an event enum/struct type

class BaseController{
public:

virtual void dispatchEvent() = 0; //dispatches the event using controller
//make sure you set the subID in the inherited constructor or weird stuff will happen
virtual void getSubID() = 0;

private:
virtual void Setup() = 0;
virtual void Execute() = 0; 

static int subID = 0;
};
