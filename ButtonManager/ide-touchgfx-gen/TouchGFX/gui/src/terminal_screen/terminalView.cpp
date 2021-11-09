#include <gui/terminal_screen/TerminalView.hpp>

TerminalView::TerminalView():
    autoScrollText_(true)
{

}

void TerminalView::setupScreen()
{
    TerminalViewBase::setupScreen();
}

void TerminalView::tearDownScreen()
{
    TerminalViewBase::tearDownScreen();
}

void TerminalView::onButtonClearLogTextClicked()
{
    // Forward event to presenter
    presenter->onButtonClearLogTextClicked();
}

void TerminalView::updateLogText(const std::string & str)
{
    Unicode::fromUTF8((const unsigned char *)str.c_str(), logText_Buffer, LOGTEXT__SIZE);
    logText_.resizeToCurrentTextWithAlignment();   // Update height of text area

    // Check if we always need to show the end of the logs (most recent logs)
    if (autoScrollText_)
    {
        auto scrollHeight = scrollableTextArea_.getHeight();
        auto textHeight = logText_.getTextHeight();

        if (logText_.getRotation() == TEXT_ROTATE_0)
        {
            if (textHeight > scrollHeight)
            {
                logText_.startMoveAnimation(logText_.getX(),                    // X value to scroll to
                                            -(textHeight - scrollHeight),       // Y value to scroll to
                                            2);                                 // Animation duration in ticks
            }
        }
        else if (logText_.getRotation() == TEXT_ROTATE_180)
        {
            if (textHeight > scrollHeight)
            {
                // Scroll to bottom is scrolling to y == 0
                logText_.startMoveAnimation(logText_.getX(), 0, 2);
            }
        }
    }

    logText_.invalidate();
}

void TerminalView::clearLogText()
{
    logText_Buffer[0] = '\0';

    if (logText_.getRotation() == TEXT_ROTATE_0)
    {
        logText_.resizeHeightToCurrentText();

        logText_.startMoveAnimation(logText_.getX(),            // X value to scroll to
                                    0,                          // Y value to scroll to
                                    2);                         // Animation duration in ticks
    }
    else if (logText_.getRotation() == TEXT_ROTATE_180)
    {
        logText_.resizeToCurrentTextWithAlignment();

        logText_.startMoveAnimation(logText_.getX(),                                            // X value to scroll to
                                    scrollableTextArea_.getHeight() - logText_.getHeight(),     // Y value to scroll to (in respect with rotated text)
                                    2);                                                         // Animation duration in ticks
    }

    logText_.invalidate();
    scrollableTextArea_.invalidate();
}

