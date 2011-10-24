//name: IEvent
//author: Stevie
//purpose: A controller which is bound to an event enum/struct type
enum EVENT{
INVALID = 0,
RENDER = 1,
SYSTEM = 2, 
ENTITY = 3
};

class BaseController{
public:
EVENT EventType;

virtual void dispatchEvent() = 0; //dispatches the event using controller

private:
virtual void Execute() = 0; 


};
