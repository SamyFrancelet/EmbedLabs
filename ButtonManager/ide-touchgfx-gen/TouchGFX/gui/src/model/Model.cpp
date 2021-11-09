#include "config/touchgfx-config.h"
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() :
    modelListener(0),
    logTextChanged_(false)
{

}

void Model::initialize(
#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)            // Used to get a compilable project for the students!
                       ButtonEventsHandler & buttonEventsHandler
#endif // TOUCHGFX_ENABLED
                      )
{
#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
    // Subscribe to button events
    bool success = buttonEventsHandler.subscribe(this);
    assert(success);
#endif // TOUCHGFX_ENABLED
}

/**
 * The tick method is called regularly by the TouchGFX task
 */
void Model::tick()
{
    if (logTextChanged_)
    {
        logTextChanged_ = false;
        if (logMessages_.size() > 0)
        {
            logTextTotal_.clear();

            // Add all log messages to logTextTotal_
            // New messages are at the beginning of the list, but
            // need to be at the end in logTextTotal_
            for (std::string str : logMessages_)
            {
                logTextTotal_.insert(0, str);
            }

            modelListener->notifyLogTextChanged(logTextTotal_);
        }
        else
        {
            modelListener->notifyClearLogMessages();
        }
    }
}


void Model::addLogMessage(const std::string & logMessage)
{
    logMessages_.push_front(logMessage);

    // Remove an old message if list is too big
    if (logMessages_.size() > MAX_MESSAGES)
    {
        logMessages_.pop_back();
    }

    // Tell UI task that logText did change
    logTextChanged_ = true;
}

void Model::clearLogMessages()
{
    logMessages_.clear();
    logTextTotal_.clear();

    // Tell UI task that logText did change
    logTextChanged_ = true;
}

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
void Model::onButtonShortPressed(ButtonIndex buttonIndex)
{
    std::string logMessage("Button ");

    logMessage += std::to_string(buttonIndex);
    logMessage += " short pressed\n";

    addLogMessage(logMessage);
}

void Model::onButtonLongPressed(ButtonIndex buttonIndex)
{
    std::string logMessage("Button ");

    logMessage += std::to_string(buttonIndex);
    logMessage += " long pressed\n";

    addLogMessage(logMessage);
}
#endif // TOUCHGFX_ENABLED
