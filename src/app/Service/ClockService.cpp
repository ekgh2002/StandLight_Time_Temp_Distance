#include "ClockService.h"
#include <iostream>
#include <wiringPi.h>

ClockService::ClockService(ClockView *clockview)
{
    curTime = 0;
    this->clockView = clockview;
    clockstate = CLOCK;
}

ClockService::~ClockService()
{}

void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    clockView->updateTime(timeDate);
}

void ClockService::clockselect(std::string strState3)
{
    switch(clockstate)
    {
        case CLOCK:
        if (strState3 == "clockbutton")
        {
            clockstate = Timer;
            clockView->setclockstate(clockstate);
            printf("hi\n");
        }
        break;

        case Timer:
        if (strState3 == "clockbutton")
        {
            clockstate = CLOCK;
            clockView->setclockstate(clockstate);
            printf("hello\n");
        }
        break;
    }

}