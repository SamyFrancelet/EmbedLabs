#ifndef OSCILLOSCOPECONTROLLER_H
#define OSCILLOSCOPECONTROLLER_H

#include <assert.h>
#include <string>
#include "xf/behavior.h"
#include "interface/guiobserver.h"

namespace oscilloscope {
    class Gui;

typedef enum
{
    TDIV_MIN = 0,
    TDIV_500us,
    TDIV_1ms,
    TDIV_2ms,
    TDIV_5ms,
    TDIV_10ms,
    TDIV_MAX
} TDivValue;

typedef struct
{
    TDivValue tdivValue;
    std::string text;
} TDivOption;

/**
 * @brief The Oscilloscope Controller
 *
 * Responsible to provide and update oscilloscope data. All input
 * (touch screen, signal measurement data) comes to the controller
 * and updates then the view(s) accordingly.
 */
class Controller : public XFBehavior,
                   public interface::GuiObserver
{
public:
	Controller();
	virtual ~Controller() {}

	static Controller & getInstance();

	void initialize(Gui & gui, uint16_t * adcValuesBuffer, uint32_t adcValuesBufferSize);

	void start();

	inline TDivValue getTDivValue() const { return _tdivValue; }

	bool triggerOn() const { return _trig; }

	// XFReactive interface implementation
protected:
	XFEventStatus processEvent() override;

	// GuiObserver interface implementation
protected:
    void onButtonTimePlusPressed() override;
    void onButtonTimeMinusPressed() override;
    void onButtonTriggerPressed() override;
    uint32_t getTDivCount() const override { return 8; };

protected:
	void doShowAnalogSignal();
	void doButtonTimePlusPressed();
	void doButtonTimeMinusPressed();
	void doButtonTriggerPressed();
	inline Gui & gui() const { assert(_pGui); return *_pGui; }

	std::string getText(TDivValue tdivValue);

protected:
	static Controller * _pInstance;

	Gui * _pGui;
	uint16_t * _adcValuesBuffer;
	uint32_t _adcValuesBufferSize;

	bool _trig;

	const int TIMEOUT_ID = 0;
	const int TIMEOUT_INTERVAL = 20;

	const int BTN_PLUS_ID = 0;
	const int BTN_MINUS_ID = 1;
	const int BTN_TRIG_ID = 2;

	TDivValue _tdivValue;

	static const TDivOption _tdivOptions[];
};

}   // namespace oscilloscope
#endif // OSCILLOSCOPECONTROLLER_H
