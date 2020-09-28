//
// Created by aaade on 25.09.2020.
//

#include "Time.h"
#include <string>
#include <stdexcept>
using namespace std;

bool Time::CheckHour(int new_hour)
{
    return new_hour >= 0 && new_hour < 24;
}

bool Time::CheckMinute(int new_minute)
{
    return new_minute >= 0 && new_minute < 60;
}

Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
};

void Time::SetTime(const int& new_hour, const int& new_minute, const int& new_second)
{
    if (CheckHour(new_hour) && CheckMinute(new_minute) && CheckMinute(new_second))
    {
        hour = new_hour;
        minute = new_minute;
        second = new_second;
    }
    else
    {
        if (!CheckHour(new_hour))
            throw logic_error("Hour value is invalid: " + to_string(new_hour));
        if (!CheckMinute(new_minute))
            throw logic_error("Minute value is invalid: " + to_string(new_minute));
        if (!CheckMinute(new_second))
            throw logic_error("Second value is invalid: " + to_string(new_second));
    }
}