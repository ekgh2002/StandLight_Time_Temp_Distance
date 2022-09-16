#include "Service.h"
#include <iostream>
#include <wiringPi.h>

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    panstate = PAN_OFF;
    bDistanceLight = false;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
             if(strState == "onoffbt")
             {
                lightState = PAN_ON;
                view->setState(lightState);
             }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(strState == "onoffbt")
            {
            lightState = PAN_ON;
            view->setState(lightState);
            }
            if (bDistanceLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(strState == "onoffbt")
            {
            lightState = PAN_ON;
            view->setState(lightState);
            }
            if (bDistanceLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(strState == "onoffbt")
            {
            lightState = PAN_ON;
            view->setState(lightState);
            }
            if (bDistanceLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
            
        break;

        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(strState == "onoffbt")
            {
            lightState = PAN_ON;
            view->setState(lightState);
            }
            if (bDistanceLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;              
            }
            if(strState == "onoffbt")
            {
            lightState = PAN_ON;
            view->setState(lightState);
            }
            if (bDistanceLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
        break;

        case PAN_OFF:
            if(strState == "onoffbt")
            {
                lightState = PAN_ON;
                view->setState(lightState);
            }     
        break;

        case PAN_ON:
            if(strState == "onoffbt")
            {
                lightState = PAN_OFF;
                view->setState(lightState);
            }
            if(strState == "panpowerbutton")
            {
                lightState = PAN2;
                view->setState(lightState);
            }  
        break;

        case PAN1:
            if(strState == "onoffbt")
            {
                lightState = PAN_OFF;
                view->setState(lightState);
            }
            if(strState == "panpowerbutton")
            {
                lightState = PAN2;
                view->setState(lightState);
            }    
        break;

        case PAN2:
            if(strState == "onoffbt")
            {
                lightState = PAN_OFF;
                view->setState(lightState);
            }
            if(strState == "panpowerbutton")
            {
                lightState = PAN3;
                view->setState(lightState);
            }    
        break;

        case PAN3:
            if(strState == "onoffbt")
            {
                lightState = PAN_OFF;
                view->setState(lightState);
            }
            if(strState == "panpowerbutton")
            {
                lightState = PAN1;
                view->setState(lightState);
            }
        break;

    }
}


void Service::updateEvent(DHT_Data dhtData)
{
    float temp;
    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);

    if(temp > 26)
    {
        lightState = LIGHT_OFF;
    }
    

    view->setState(lightState);
    // view->lightwarning(dhtData);
}

void Service::updateDistance(int distance)
{

    static int distance_count = 0;
    printf("distance : %d\n", distance);
    if (distance < 0)
    {
        distance_count = distance_count+1;
    }
    else if(distance > 0)
    {
        distance_count = 0;
    }
    
    if (distance_count > 4)
    {
        bDistanceLight = false;
        view->setState(LIGHT_OFF);
        distance_count = 0;
    }
    else
    {
        bDistanceLight = true;
        view->setState(lightState);
    }
}