#include "xf/initialevent.h"

// TODO: Implement code for XFInitialEvent class 
XFInitialEvent::XFInitialEvent()
    :XFEvent(XFEventType::Initial, 0, nullptr) // Prolly must be modified
{

}

bool XFInitialEvent::deleteAfterConsume() const
{
    return true;
}
