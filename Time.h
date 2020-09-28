//
// Created by aaade on 25.09.2020.
//

#ifndef HOMEWORK_TIME_H
#define HOMEWORK_TIME_H
#include <vector>
using namespace std;






class Time {
protected:
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
    int month;
    int year;
    int UTC;
    vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31 };
public:
    Date();
    bool IsLeap();
    bool IsCorrectDate();
    void SetDate(int y,int m,int d,int h,int minut,int s);
    void PrintDate();
    void Increase(int y,int m,int d,int h,int minut,int s);
    void Decrease(int y,int m,int d,int h,int minut,int s);
    void Week_Day();

    int GetYear();
    int GetMonth();
    int GetDay();
    int GetHour();
    int GetMinute();
    int GetSecond();
    int GetUTC();

    

};

Date operator-(Date d1,Date d2);

#endif //HOMEWORK_TIME_H
