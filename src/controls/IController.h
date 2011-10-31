//name: IEvent
//author: Stevie
//purpose: A controller which is bound to an event enum/struct type

class BaseController{
public:

virtual void dispatchEvent(); //dispatches the event using controller

private:
virtual void Setup();
virtual void Execute(); 

};
