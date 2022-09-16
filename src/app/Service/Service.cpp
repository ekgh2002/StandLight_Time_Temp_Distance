#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
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
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
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
            if (bDistanceLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
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
    printf("distance : %d\n", distance);

    if (distance < 0)
    {
        bDistanceLight = false;
        view->setState(LIGHT_OFF);
    }
    else
    {
        bDistanceLight = true;
        view->setState(lightState);
    }
}