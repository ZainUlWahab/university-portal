#include <iostream>
#include <fstream>
#include <iomanip>
#include "teacher.h"
using namespace std;
class student : public person
{
    string* rollnum;
    string* coursenames;
    string currentuser;
    char** courses;
    public:
    student();
    ~student();
    void importdata();
    void importcoursenames();
    void importcourses();
    void displayrollnum();
    void displaystudentname();
    void generateusername();
	void displayusername();
	void generatepassword();
	void displaypassword();
    void displaycourses();
    bool validateusername(string);
    bool validatepassword(string);
    void changepassword();
    void currentdetails();
    int getcurrentstudentindex();
    void setcurrentuser(string);
    void takequiz();
    bool checkcourse(int);
    char getcourse(int,int);
    string getname(int);
};