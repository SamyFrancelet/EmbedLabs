#include <string.h>
#include <assert.h>
#include "trace/trace.h"
#include "gui.h"
#include "TouchGFX/gui/include/gui/mainview_screen/MainViewView.hpp"
#include "TouchGFX/gui/include/gui/model/Model.hpp"

#define TOUCH_THREAD_STACK_SIZE     2048

namespace oscilloscope {

Gui* Gui::_instance = nullptr;

Gui::Gui() :
    _pGuiObserver(nullptr),
    _redLedOn(false),
    _xAxisPixelsPerField(0)
{
	if(_instance==nullptr){
		    _instance = this;
		}
}

Gui* Gui::getInstance() {
	return _instance;
}

bool Gui::registerObserver(interface::GuiObserver * pGuiObserver)
{
    if (!_pGuiObserver and pGuiObserver)
    {
        _pGuiObserver = pGuiObserver;
        return true;
    }
    return false;
}

void Gui::start()
{
    startBehavior();
}

void Gui::drawGraphPoints(uint16_t * values, uint16_t count, float xScale /* = 1 */)
{
	Model* model = Model::getInstance();
	if(model!=nullptr){
		model->setGraphPoints(values, count, xScale);
	}
}

bool Gui::isRedLedEnabled() const
{
    return _redLedOn;
}

void Gui::setRedLed(bool enable)
{
    _redLedOn = enable;
}

bool Gui::isOscilloscopePageEnabled() const
{
	return true;
}

void Gui::setTimeDivisionText(std::string text)
{
	Model* model = Model::getInstance();
	if(model!=nullptr){
		model->setDivTimLabel(text);
	}
}

void Gui::setFreqGenWaveformText(std::string text)
{
	Model* model = Model::getInstance();
	if(model!=nullptr){
		model->setModeSignal(text);
	}
}

void Gui::setFreqGenFrequencyText(std::string text)
{
	Model* model = Model::getInstance();
	if(model!=nullptr){
		model->setFreqSignal(text);
	}
}

XFEventStatus Gui::processEvent()
{
#if (PORT_IDF_STM32CUBE != 0)
    //GEN(XFNullTransition);
#endif
    return XFEventStatus::Consumed;
}

void Gui::onButtonTimePlusPressed()
{
    _pGuiObserver->onButtonTimePlusPressed();
}

void Gui::onButtonTimeMinusPressed()
{
    _pGuiObserver->onButtonTimeMinusPressed();
}

}   // namespace oscilloscope
