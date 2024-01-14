#include <iostream>
using namespace std;
class date
{
    int day;
    int month;
    int year;
    int hour;
    int min;
    public:
    date();
    void setdateandtime();
    void display();
    bool validate(date,int);
};