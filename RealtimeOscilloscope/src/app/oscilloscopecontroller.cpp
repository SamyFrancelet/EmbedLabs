#include <assert.h>
#include "trace/trace.h"
#include "xf/eventstatus.h"
#include "main.h"
#include "gui.h"
#include "oscilloscopecontroller.h"

typedef struct {
	uint32_t i;
	uint32_t value;
	uint32_t prevValue;
} debugStruct;

debugStruct arr[64];

uint32_t arrIndex = 0;

namespace oscilloscope {

Controller * Controller::_pInstance(nullptr);

const TDivOption Controller::_tdivOptions[] = {{TDIV_500us, "500 us / div"},
                                               {TDIV_1ms,     "1 ms / div"},
                                               {TDIV_2ms,     "2 ms / div"},
                                               {TDIV_5ms,     "5 ms / div"},
                                               {TDIV_10ms,   "10 ms / div"}};

Controller::Controller() :
    _pGui(nullptr),
    _adcValuesBuffer(nullptr),
	_adcValuesBufferSize(0),
	_trig(false),
	_tdivValue(TDIV_1ms)
{
    assert(!_pInstance);    // Only one instance of this class allowed!
    _pInstance = this;
}

//static
Controller & Controller::getInstance()
{
    assert(_pInstance);     // Create first an instance!
    return *_pInstance;
}

void Controller::initialize(Gui & gui, uint16_t * adcValuesBuffer, uint32_t adcValuesBufferSize)
{
    _pGui = &gui;
    _adcValuesBuffer = adcValuesBuffer;
    _adcValuesBufferSize = adcValuesBufferSize;

    gui.registerObserver(this);     // Get notified about GUI events
}

void Controller::start()
{
    startBehavior();
}

XFEventStatus Controller::processEvent()
{
    assert(_adcValuesBuffer);
    assert(_adcValuesBufferSize > 0);

	if (getCurrentEvent()->getEventType() == XFEvent::Initial)
	{
		scheduleTimeout(TIMEOUT_ID, TIMEOUT_INTERVAL);

		doShowAnalogSignal();
	}

	if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
		getCurrentTimeout()->getId() == TIMEOUT_ID)
	{
		scheduleTimeout(TIMEOUT_ID, TIMEOUT_INTERVAL);

		doShowAnalogSignal();
	}

	if (getCurrentEvent()->getEventType() == XFEvent::Event &&
		getCurrentEvent()->getId() == BTN_PLUS_ID)
	{
		doButtonTimePlusPressed();
	}

	if (getCurrentEvent()->getEventType() == XFEvent::Event &&
		getCurrentEvent()->getId() == BTN_MINUS_ID)
	{
		doButtonTimeMinusPressed();
	}

	if (getCurrentEvent()->getEventType() == XFEvent::Event &&
		getCurrentEvent()->getId() == BTN_TRIG_ID)
	{
		doButtonTriggerPressed();
	}

	return XFEventStatus::Consumed;
}

void Controller::onButtonTimePlusPressed()
{
	XFEvent* evButtonPlus =new XFEvent(XFEvent::Event, BTN_PLUS_ID, this);

	pushEvent(evButtonPlus);
}

void Controller::onButtonTimeMinusPressed()
{
	XFEvent* evButtonMinus =new XFEvent(XFEvent::Event, BTN_MINUS_ID, this);

	pushEvent(evButtonMinus);
}

void Controller::onButtonTriggerPressed()
{
	XFEvent* evButtonTrig = new XFEvent(XFEvent::Event, BTN_TRIG_ID, this);

	pushEvent(evButtonTrig);
}

void Controller::doShowAnalogSignal()
{
	static int pouet = 0;
	// Trying to add the trigger here is horrible and cause suffering all around the world
	/*if(triggerOn()) {
		uint32_t shift = 0;
		int i;
		for(i = 2; i < 2000; i++) {
			if(_adcValuesBuffer[i] >= 2000
					&& _adcValuesBuffer[i-2] < _adcValuesBuffer[i]) { // Around than 2^11, which is ~middle
				shift = i;
				break;
			}
		}
		arr[arrIndex].i = i;
		arr[arrIndex].value = _adcValuesBuffer[i];
		arr[arrIndex].prevValue = _adcValuesBuffer[i-2];

		arrIndex++;
		arrIndex %= 64;

		if(shift == 0) {
			// Do nothing
			pouet++;
		} else {
			gui().drawGraphPoints(_adcValuesBuffer+shift, ADC_VALUES_BUFFER_SIZE-shift);
		}

	} else {
		gui().drawGraphPoints(_adcValuesBuffer, ADC_VALUES_BUFFER_SIZE);
	}*/

	float scale = 1.0;
	switch(_tdivValue) {
	case TDIV_500us:
		scale = 20.0;
		break;
	case TDIV_1ms:
		scale = 10.0;
		break;
	case TDIV_2ms:
		scale = 4.0;
		break;
	case TDIV_5ms:
		scale = 2.0;
		break;
	case TDIV_10ms:
		scale = 1.0;
		break;
	default:
		scale = 1.0;
		break;
	}

	gui().drawGraphPoints(_adcValuesBuffer, ADC_VALUES_BUFFER_SIZE, scale);
}

void Controller::doButtonTimePlusPressed()
{
    if (_tdivValue < (TDIV_MAX - 1))
    {
        _tdivValue = (TDivValue)(_tdivValue + 1);

        gui().setTimeDivisionText(getText(_tdivValue));
    }
}

void Controller::doButtonTimeMinusPressed()
{
    if (_tdivValue > (TDIV_MIN + 1))
    {
        _tdivValue = (TDivValue)(_tdivValue - 1);

        gui().setTimeDivisionText(getText(_tdivValue));
    }
}

void Controller::doButtonTriggerPressed()
{
	_trig = !_trig;
}

std::string Controller::getText(TDivValue tdivValue)
{
    const uint32_t count = sizeof(_tdivOptions)/sizeof(_tdivOptions[0]);

    for (uint32_t i = 0; i < count; i++)
    {
        if (_tdivOptions[i].tdivValue == tdivValue)
        {
            return _tdivOptions[i].text;
        }
    }
    return "n/a";
}

}   // namespace oscilloscope
