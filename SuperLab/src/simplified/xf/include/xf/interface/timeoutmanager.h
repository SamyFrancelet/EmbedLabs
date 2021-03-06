#ifndef XF_INTERFACE_TIMEOUTMANAGER_H
#define XF_INTERFACE_TIMEOUTMANAGER_H

#include <cstdint>
#include <functional>

namespace interface {
    class XFBehavior;
}
class XFTimeout;

namespace interface {

/**
 * @brief Interface for TimerManager classes (and some few 'tick' stuff already provided).
 *
 * The TimeoutManager is responsible to handle timeouts used
 * in state machines. It decrements them accordingly and inject
 * them back to the state machine when timeouted.
 *
 * <b>Requirements:</b>
 * - Implements the Singleton pattern
 * - Handle timeouts (hold, decrement, re-inject)
 */
class XFTimeoutManager
{
public:
    virtual ~XFTimeoutManager() = default;

    static XFTimeoutManager * getInstance();	///< Returns a pointer to the single instance of TimeoutManager.

    /**
     * Sets the time interval in milliseconds in which the timeout manager
     * should handle the timeouts.
     */
    virtual void initialize(int32_t tickInterval)
    {
        tickInterval_ = tickInterval;
    }

    /**
     * @brief Returns tick interval in milliseconds.
     */
    virtual int32_t getTickInterval() const
    {
        return tickInterval_;
    }

    /**
     * Starts the timeout manager.
     */
    virtual void start(std::function<void(uint32_t)> startTimeoutManagerTimer = nullptr) = 0;

    /**
     * Adds a timeout to the timeout manager.
     *
     * \param timeoutId The timeout id known by the reactive parameter. Is needed by the reactive part to uniquely identify the timeout.
     * \param interval The time in milliseconds to wait until the timeout expires.
     * \param pBehavior The reactive instance where to inject the timeout when it timeouts.
     */
    virtual void scheduleTimeout(int32_t timeoutId, int32_t interval, interface::XFBehavior * pBehavior) = 0;

    /**
     * Removes all timeouts corresponding the given parameters.
     */
    virtual void unscheduleTimeout(int32_t timeoutId, interface::XFBehavior * pBehavior) = 0;

    /** \brief Called periodically with a delay defined by TimeoutManager::_tickInterval.
     *
     * On each call to this method, TimeoutManager::_tickInterval will be removed from the
     * timeouts.
     * When a timeout expires it is pushed back to the dispatcher. To which
     * dispatcher it must be given is known by the reactive instance to which the timeout
     * belongs.
     */
    virtual void tick() = 0;

protected:
    XFTimeoutManager() :
        tickInterval_(0)
    {}

    virtual void addTimeout(XFTimeout * pNewTimeout) = 0;	///< Adds the timeout to the list of timeouts.

protected:
    int32_t tickInterval_;						///< Interval in milliseconds the TimeoutManager is decrementing the timeouts.
};

} // namespace interface
#endif // XF_INTERFACE_TIMEOUTMANAGER_H
