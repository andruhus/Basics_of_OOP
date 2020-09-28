//
// Created by aaade on 25.09.2020.
//

#ifndef HOMEWORK_TIME_H
#define HOMEWORK_TIME_H


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


    void SetTime(const int &new_hour, const int &new_minute, const int &new_second);

};
#endif //HOMEWORK_TIME_H
