#include <iostream>
#include <fstream>
using namespace std;
class subjective
{
    string** questions;
    string** answers;
    public:
    subjective();
    void import();
    void display();
    string getquestion(int,int);
    string getanswer(int,int);
};