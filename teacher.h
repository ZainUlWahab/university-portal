#include <iostream>
#include <fstream>
#include <iomanip>
#include "person.h"
using namespace std;
class Teacher : public person
{
	string* courses;
	string* coursecodes;
	string currentuser;
	public:
	Teacher();
	~Teacher();
	void importdata();
	void displaycourses();
	void displaycoursecodes();
	void generateusername();
	void displayusername();
	void generatepassword();
	void displaypassword();
	bool validateusername(string);
    bool validatepassword(string);
	void setcurrentuser(string);
	string getcurrentuser();
	string* getusernames();
	string getcourse(int);
	void changepassword();
	int getcurrentteacherindex();
	void currentdetails();
};