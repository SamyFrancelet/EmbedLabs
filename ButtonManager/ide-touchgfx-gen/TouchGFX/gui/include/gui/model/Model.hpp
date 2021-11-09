#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <list>
#include "config/touchgfx-config.h"

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)    // Used to get a compilable project for the students!
#include "mdw/button/buttoneventshandler.h"
#endif // TOUCHGFX_ENABLED

class ModelListener;

/**
 * @brief Model containing data used by the GUI view(s).
 */
class Model
#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)    // Used to get a compilable project for the students!
        : public interface::ButtonEventsHandlerObserver
#endif // TOUCHGFX_ENABLED
{
public:
    Model();

    void initialize(
#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
                    ButtonEventsHandler & buttonEventsHandler
#endif // TOUCHGFX_ENABLED
                   );

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void addLogMessage(const std::string & logMessage);
    void clearLogMessages();

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
protected:
    void onButtonShortPressed(ButtonIndex buttonIndex) override;
    void onButtonLongPressed(ButtonIndex buttonIndex) override;
#endif // TOUCHGFX_ENABLED

protected:
    ModelListener* modelListener;

    static constexpr const uint32_t MAX_MESSAGES = 50;

    std::list<std::string> logMessages_;    ///< Log messages
    std::string logTextTotal_;              ///< String containing all log messages to display, provided to the model listener.
    bool logTextChanged_;                   ///< True when one or more log messages were added.
};

#endif // MODEL_HPP
