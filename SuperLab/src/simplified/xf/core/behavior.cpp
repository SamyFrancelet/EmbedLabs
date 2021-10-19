#include <cassert>
#include "xf/xf.h"
#include "xf/timeout.h"
#include "xf/initialevent.h"
#include "xf/behavior.h"

// TODO: Implement code for XFBehavior class

XFBehavior::XFBehavior()
{
    pDispatcher_ = interface::XFDispatcher::getInstance();
}

XFBehavior::~XFBehavior()
{

}

void XFBehavior::startBehavior()
{
    GEN(XFInitialEvent);
}

void XFBehavior::pushEvent(XFEvent *pEvent, bool fromISR)
{
    pEvent->setBehavior(this);
    pDispatcher_->pushEvent(pEvent, fromISR);
}

bool XFBehavior::deleteOnTerminate() const
{
    return deleteOnTerminate_;
}

void XFBehavior::setDeleteOnTerminate(bool deleteBehaviour)
{
    deleteOnTerminate_ = deleteBehaviour;
}

const XFEvent *XFBehavior::getCurrentEvent() const
{
    return pCurrentEvent_;
}

interface::XFDispatcher *XFBehavior::getDispatcher()
{
    return pDispatcher_;
}

const XFTimeout *XFBehavior::getCurrentTimeout()
{
    //return dynamic_cast<const XFTimeout*>(pCurrentEvent_);
	return reinterpret_cast<const XFTimeout*>(pCurrentEvent_);
}

void XFBehavior::setCurrentEvent(const XFEvent *pEvent)
{
    pCurrentEvent_ = pEvent;
}

XFBehavior::TerminateBehavior XFBehavior::process(const XFEvent *pEvent)
{
    setCurrentEvent(pEvent);
    XFEventStatus evStatus = processEvent();
    if(pEvent->deleteAfterConsume() &&
    		(evStatus == XFEventStatus::Consumed || evStatus == XFEventStatus::Terminate)) {
    	delete pEvent;
    }
    return (deleteOnTerminate() && evStatus == XFEventStatus::Terminate);
}
