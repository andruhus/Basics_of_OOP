//!
//! Created by aaade on 25.09.2020.
//!

#ifndef HOMEWORK_TIME_H
#define HOMEWORK_TIME_H
#include <vector>
#include <string>
using namespace std;





//! Time and Date were separated in the task, so I decided to separate it too
class Time {
protected:
    //! basic time attribute but they starts from 0
    int hour;
    int minute;
    int second;

    bool CheckHour(int my_hour);

    //! it also works for seconds as well
    bool CheckMinute(int my_minute);


public:
    Time();


    void SetTime(int new_hour,int new_minute,int new_second);

};

class Date : public Time
{
private:

    int day;//! it starts from 1
    int month;
    int year;
    int UTC;
    //! this will help us when we check the day
    vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31 };
public:
    //! The tasks in the first sentence
    Date();
    //!//! IsLeap function gives not only bool but also modifies daysInMonth
    bool IsLeap();
    bool IsCorrectDate();
    void SetDate(int y,int m,int d,int h,int minut,int s,int u);
    void PrintDate();
    //! The tasks in the second sentence
    void Increase(int y,int m,int d,int h,int minut,int s);
    void Decrease(int y,int m,int d,int h,int minut,int s);
    //! The tasks in the third sentence
    string Week_Day();

    //! Some necessary getters
    int GetYear();
    int GetMonth();
    int GetDay();
    int GetHour();
    int GetMinute();
    int GetSecond();
    int GetUTC();



};

Date operator-(Date d1,Date d2);
bool operator==(Date d1,Date d2);
#endif //!HOMEWORK_TIME_H

