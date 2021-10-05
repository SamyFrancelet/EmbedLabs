#include "xf/defaulttransition.h"

// TODO: Implement code for XFDefaultTransition class  

XFDefaultTransition::XFDefaultTransition(interface::XFBehavior *pBehavior)
    :XFEvent(DefaultTransition, 0, pBehavior) // Prolly must be modified
{

}

bool XFDefaultTransition::deleteAfterConsume() const
{

}
