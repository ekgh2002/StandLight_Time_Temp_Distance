#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H
#include <time.h>
#include "ClockView.h"

#pragma once

class ClockService
{

private:
    time_t curTime;
    ClockView *clockView;

public:
    ClockService(ClockView *view);
    virtual ~ClockService();
    void updateEvent();

};

#endif