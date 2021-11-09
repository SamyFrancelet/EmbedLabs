#ifndef TERMINALPRESENTER_HPP
#define TERMINALPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TerminalView;

class TerminalPresenter : public touchgfx::Presenter, public ModelListener
{
    friend class TerminalView;
public:
    TerminalPresenter(TerminalView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TerminalPresenter() {};

protected:
    void clearLogMessages();

    /**
     * Methods below are called by the associated view.
     */
    void onButtonClearLogTextClicked();

    /**
     * Notify methods below are asynchronously called by the
     * TouchGFX UI task to update the LCD display
     */
    void notifyLogTextChanged(const std::string & logText) override;
    void notifyClearLogMessages() override;

private:
    TerminalPresenter();

    TerminalView& view;
};

#endif // TERMINALPRESENTER_HPP
