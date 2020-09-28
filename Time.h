//
// Created by aaade on 25.09.2020.
//

#ifndef HOMEWORK_TIME_H
#define HOMEWORK_TIME_H
#include <vector>
using namespace std;

enum Month
{
    January = 0,
    February = 1,
    March  = 2,
    April = 3,
    May = 4,
    June = 5,
    July = 6,
    August = 7,
    September = 8,
    October = 9,
    November = 10,
    December = 11
};

class Time {
private:
    int hour;
    int minute;
    int second;

    bool CheckHour(int new_hour);

    // it also works for seconds as well
    bool CheckMinute(int new_minute);


public:
    Time();


    void SetTime(int new_hour,int new_minute,int new_second);

};

class Date : public Time
{
private:

    int day;
    Month month;
    int year;

    vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31 };
public:
    Date();

};



#endif //HOMEWORK_TIME_H
