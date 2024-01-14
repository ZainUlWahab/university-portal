#include <iostream>
using namespace std;
class truefalse
{
    string** questions;
    char** answers;
    public:
    truefalse();
    void importdata();
    void display();
    string getquestion(int,int);
    char getanswer(int,int);
};