#include <gui/terminal_screen/TerminalView.hpp>
#include <gui/terminal_screen/TerminalPresenter.hpp>

TerminalPresenter::TerminalPresenter(TerminalView& v)
    : view(v)
{

}

void TerminalPresenter::activate()
{

}

void TerminalPresenter::deactivate()
{

}

void TerminalPresenter::clearLogMessages()
{
    model->clearLogMessages();
}

void TerminalPresenter::onButtonClearLogTextClicked()
{
    clearLogMessages();
}

void TerminalPresenter::notifyLogTextChanged(const std::string & logText)
{
    view.updateLogText(logText);
}

void TerminalPresenter::notifyClearLogMessages()
{
    view.clearLogText();
}
