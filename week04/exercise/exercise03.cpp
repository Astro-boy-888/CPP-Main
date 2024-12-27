#include <iostream>
using namespace std;

enum Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
enum Weather {Sunny, Cloudy, Rainy, Snowy};

struct DayInfo 
{
    Day day;
    Weather weather;
};

bool canTravel(DayInfo info) 
{
    // TODO: 判断这天是否适合旅行
    if (info.day == Sunday || info.day == Saturday)
    {
        if (info.weather == Sunny || info.weather == Cloudy)
        {
            return true;
        }
        return false;
    }
    return false;
}

int main() {
    DayInfo Today = {Monday,Sunny};
    if (canTravel(Today))
    {
        cout << "Yes, I can travel today." << endl;
    }
    else
    {
        cout << "Sorry, I can't travel today." << endl;
    }
    return 0;
}
