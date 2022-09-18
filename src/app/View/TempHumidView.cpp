#include "TempHumidView.h"

TempHumidView::TempHumidView(LCD *lcd, PWM *pwm)
{
    this->lcd = lcd;
    this->pwm = pwm;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff1[30];
    char buff2[30];
    sprintf(buff1, "%.1fC", temp, '%');
    lcd->WriteStringXY(0, 10, buff1);
    if(temp < 27)
    {
        sprintf(buff2, " %.1f%C     ", humid, '%');
        lcd->WriteStringXY(1, 9, buff2);
        printf("%s %s\n", buff1, buff2);
    }
    else if(temp >= 27)
    {
        lcd->WriteStringXY(1, 9, "warning");  
        // pwm->Write(40);
        printf("%s\n", buff1);  
    }
}