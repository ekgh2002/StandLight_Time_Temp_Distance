#include "ClockView.h"

ClockView::ClockView(LCD *Lcd)
{
    this->lcd = Lcd;  //  this 내객체에서 선언되어있는 변수 lcd 매개변수에서 들어오는 lcd
    //timeDate = 0;
}

ClockView::~ClockView()
{
}

void ClockView::updateTime(struct tm *timeData)
{
    char buff[30];
    sprintf(buff, "%02d:%02d:%02d",
    timeData->tm_hour,
    timeData->tm_min,
    timeData->tm_sec);
    lcd->WriteStringXY(1, 0, buff);
}
