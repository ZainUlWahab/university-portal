#include <iostream>
#include "truefalse.h"
#include "mcqs.h"
#include "date.h"
// #include "teacher.h"
#include "student.h"
#include "subjective.h"
#include <time.h>
using namespace std;
class quiz
{
    subjective subj;
    mcqs mcq;
    truefalse a;
    Teacher b;
    student c;
    string currentcourse;
    int created;
    float* marks;
    int numof_tf;
    int numofmcqs;
    int numofsubj;
    int totalnoquestions;
    string* questionsselected;
    string* answersselected;
    string* optionsselected;
    char* attendance;
    public:
    quiz();
    Teacher getTeacher();
    void setquiz(string);
    void randomize();
    void displayrandomquestions();
    void displayrandomanswers();
    void displayteachercourse();
    void setbool(int);
    int getbool();
    int getnumoftf();
    int getnumofsubj();
    int getnumofquestions();
    int getnumofmcqs();
    void displayquestiontostudent(int);
    void checkanswertf(char,int,int);
    void checkanswermcq(char,int,int);
    void checkanswersubj(string,int,int);
    float getmarks(int);
    void generatemarksheet(int);
    void setattendance(int);
    void generateattendacesheet(int);
    void clear();
    void displayoptions(int);
    void generateanalytics(int);
};