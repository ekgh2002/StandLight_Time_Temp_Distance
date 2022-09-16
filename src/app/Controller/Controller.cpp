#include "Controller.h"
#include <iostream>

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService)
{
    service = serv;
    clockService = clockServ;
    lightState = LIGHT_OFF;
    this->tempHumidService = tempHumidService;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }
    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }
    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();        //  1초간격으로 event만 발생
    }
    if (strBtn == "panpowerbutton")
    {
        service->updateState("panpowerbutton");
        // printf("hi");
    }
    if (strBtn == "onoffbt")
    {
        service->updateState("onoffbt");
        // printf("hi");
    }
}

void  Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
    service->updateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}

