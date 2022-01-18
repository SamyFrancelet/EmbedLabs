#include <gui/mainview_screen/MainViewView.hpp>

#include "app/gui.h"

MainViewView* MainViewView::_instance = nullptr;

MainViewView::MainViewView()
{
	if(_instance==nullptr){
	    _instance = this;
	}
}

MainViewView* MainViewView::getInstance() {
	return _instance;
}

void MainViewView::setupScreen()
{
    MainViewViewBase::setupScreen();
}

void MainViewView::tearDownScreen()
{
    MainViewViewBase::tearDownScreen();
}

void MainViewView::onBtnPlusPressed(){
	oscilloscope::Gui::getInstance()->onButtonTimePlusPressed();
}

void MainViewView::onBtnMinusPressed(){
	oscilloscope::Gui::getInstance()->onButtonTimeMinusPressed();
}

void MainViewView::onBtnTriggerPressed(){
	oscilloscope::Gui::getInstance()->onButtonTriggerPressed();
}

void MainViewView::setModeSignal(const std::string str){
	Unicode::fromUTF8((const unsigned char *)str.c_str(),labelSignalBuffer1,LABELSIGNALBUFFER1_SIZE);
	labelSignal.invalidate();
}

void MainViewView::setFreqSignal(const std::string str){
	Unicode::fromUTF8((const unsigned char *)str.c_str(),labelSignalBuffer2,LABELSIGNALBUFFER2_SIZE);
	labelSignal.invalidate();
}

void MainViewView::setLabelDivTime(const std::string str){
	Unicode::fromUTF8((const unsigned char *)str.c_str(),labelDivTimeBuffer,LABELDIVTIME_SIZE);
    labelDivTime.invalidate();
}

void MainViewView::drawGraph(uint16_t* values, uint16_t count){
	chart.clear();
	uint16_t numberOfPoints = count;
	uint16_t intervalBetweenPoints=1;
	if(numberOfPoints>400){
		numberOfPoints=400;
		intervalBetweenPoints=(count+1)/numberOfPoints;
	}
	chart.setGraphRangeX(0, numberOfPoints-1);
	chartMajorXAxisGrid.setInterval(numberOfPoints/8);
	for(int i=0;i<count;){
		chart.addDataPoint(values[i]);
		i += intervalBetweenPoints;
	}
	chart.invalidate();
}
