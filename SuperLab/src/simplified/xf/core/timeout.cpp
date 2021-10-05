#include "xf/timeout.h"

// TODO: Implement code for XFTimeout class

XFTimeout::XFTimeout(int id, int interval, interface::XFBehavior *pBehavior)
    :XFEvent(Timeout, id, pBehavior)
{
    interval_ = interval;
}

bool XFTimeout::operator ==(const XFTimeout &timeout) const
{
    return (this->pBehavior_ == timeout.pBehavior_);
}

bool XFTimeout::deleteAfterConsume() const
{
    // ToDo
    return false;
}
