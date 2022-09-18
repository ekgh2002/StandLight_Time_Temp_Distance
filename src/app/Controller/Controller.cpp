#include "Controller.h"
#include <iostream>

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService)
{
    service = serv;
    clockService = clockServ;
    lightState = LIGHT_OFF;
    motorState = PAN_OFF;
    warningactive = 0;
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
    if (strBtn == "onoffbt")
    {
        service->updatemotorState("onoffbt");
        service->updatewarningState("onoffbt");
        // printf("hi");
    }
    if (strBtn == "clockbutton")
    {
        clockService->clockselect("clockbutton");
        // printf("hi");
    }
    if (strBtn == "panpowerbutton")
    {
        service->updatemotorState("panpowerbutton");
        service->updatewarningState("panpowerbutton");
        // printf("hi");
    }
}

void  Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
    //service->updateEvent(dhtData);

}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}

