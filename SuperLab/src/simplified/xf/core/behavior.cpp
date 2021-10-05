#include <cassert>
#include "xf/xf.h"
#include "xf/timeout.h"
#include "xf/initialevent.h"
#include "xf/behavior.h"

// TODO: Implement code for XFBehavior class

XFBehavior::XFBehavior()
{

}

XFBehavior::~XFBehavior()
{

}

void XFBehavior::startBehavior()
{

}

void XFBehavior::pushEvent(XFEvent *pEvent, bool fromISR)
{

}

bool XFBehavior::deleteOnTerminate() const
{

}

void XFBehavior::setDeleteOnTerminate(bool deleteBehaviour)
{

}

const XFEvent *XFBehavior::getCurrentEvent() const
{

}

interface::XFDispatcher *XFBehavior::getDispatcher()
{

}

const XFTimeout *XFBehavior::getCurrentTimeout()
{

}

void XFBehavior::setCurrentEvent(const XFEvent *pEvent)
{

}

XFBehavior::TerminateBehavior XFBehavior::process(const XFEvent *pEvent)
{

}
