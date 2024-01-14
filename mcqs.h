#include <iostream>
using namespace std;
class mcqs
{
    string** questions;
    string** answers;
    string** options;
    public:
    mcqs();
    void importquestions();
    void importoptionsandanswers();
    void display();
    string getquestion(int,int);
    string getanswer(int,int);
    string getoption(int,int);
};