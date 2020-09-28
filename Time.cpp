//
// Created by aaade on 25.09.2020.
//

#include "Time.h"
#include <string>
#include <stdexcept>
#include <iostream>
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

void Time::SetTime(int new_hour,int new_minute,int new_second)
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

Date::Date() {
    year = 2020;
    month = 0;
    day = 1;
    IsLeap();
}

bool Date::IsLeap() {
    bool res = true;

    // Here we define the year
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year% 400 == 0){
                res = true;
            }
            else{
                res = false;
            }

        }
        else{
            res = true;
        }
    }
    else{
        res = false;
    }
    // Then we modify daysInMonth
    if(res){
        daysInMonth[1]++;
    }
    return res;
}

bool Date::IsCorrectDate() {
    // the year is always correct
    bool res = abs(UTC) < 13;
    res = res&&(month < 12 && month >= 0);
    res = res&&(day <= daysInMonth[month] && day > 0);
    res = res&&CheckHour(hour);
    res = res&&CheckMinute(minute);
    res = res&&CheckMinute(second);
    return res;
}

void Date::SetDate(int y, int m, int d, int h, int minut, int s) {
    year = y;
    IsLeap();
    month = m;
    if(day > daysInMonth[month] || day <= 0)
        throw logic_error("Day value is invalid: " + to_string(d));
    SetTime(h,minut,s);
}

void Date::PrintDate() {
    cout << year << " Years; ";
    cout << month << " Month; ";
    cout << day << " Days; ";
    cout << hour << " Hours; ";
    cout << minute << " Minutes; ";
    cout << second << " Seconds; ";
}

void Date::Increase(int y, int m, int d, int h, int minut, int s) {
    second += s;
    if(second > 59)
    {
        second %= 60;
        minute += 1;
    }
    minute += minut;
    if(minute > 59)
    {
        minute %= 60;
        hour += 1;
    }
    hour += h;
    if(hour > 23)
    {
        hour %= 24;
        day += 1;
    }
    day += d;
    if(day >= daysInMonth[month]){
        day %= daysInMonth[month];
        month++;
    }
    month += m;
    if(month > 11){
        month %= 12;
        year++;
    }
    year += y;
}

int Date::GetSecond() {
    return second;
}

int Date::GetMinute() {
    return minute;
}

int Date::GetHour() {
    return hour;
}

int Date::GetDay() {
    return day;
}

int Date::GetMonth() {
    return month;
}

int Date::GetYear() {
    return year;
}