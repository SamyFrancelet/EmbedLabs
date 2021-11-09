#ifndef TERMINALVIEW_HPP
#define TERMINALVIEW_HPP

#include <string>
#include <gui_generated/terminal_screen/TerminalViewBase.hpp>
#include <gui/terminal_screen/TerminalPresenter.hpp>

class TerminalView : public TerminalViewBase
{
    friend class TerminalPresenter;
public:
    TerminalView();
    virtual ~TerminalView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    void onButtonClearLogTextClicked() override;

    /**
     * Methods below must only be called by the Presenter or
     * the TouchGfx UI task.
     */
    void updateLogText(const std::string & str);
    void clearLogText();

protected:
    bool autoScrollText_;
};

#endif // TERMINALVIEW_HPP
