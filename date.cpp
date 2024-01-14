#include "date.h"
date::date()
{
    year=0;
    month=0;
    day=0;
    hour=0;
    min=0;
}
void date::setdateandtime()
{
    cout<<"Enter year : ";
    cin>> this -> year;
    monthy:
    cout<<"Enter month : ";
    cin>> this -> month;
    if(month>12 || month<1)
    {
        cout<<"Enter a valid month please."<<endl;
        goto monthy;
    }
    dayy:
    cout<<"Enter day : ";
    cin>> this -> day;
    if(day>31 || day<1)
    {
        cout<<"Enter a valid day please."<<endl;
        goto monthy;
    }
    houry:
    cout<<"Enter hour : ";
    cin>> this -> hour;
    if(hour>24 || hour<1)
    {
        cout<<"Enter a valid hour please."<<endl;
        goto houry;
    }
    cout<<"Enter min : ";
    cin>> this -> min;
    if(min>60)
    {
        hour+=1;
        min-=60;
    }
}
void date::display()
{
    cout<<"Date : "<<month<<"/"<<day<<"/"<<year<<endl;
    cout<<"Time : "<<hour<<":"<<min;
}
bool date::validate(date a,int duration)
{
    int temp = (this -> min + duration);
    if(a.year == this -> year)
    {
        if(a.month == this -> month)
        {
            if(a.day == this -> day)
            {
                if(a.hour == this -> hour)
                {
                    if(a.min == this -> min || ((this -> min >= a.min) && (this->min <= (a.min  + duration))))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}