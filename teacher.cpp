#include "teacher.h"
#include <unistd.h>
Teacher::Teacher()
{
	courses = new string[11];
	coursecodes = new string[11];
	name = new string[11];
	username = new string[11];
	password = new string[11];
	name[0] = "Ayesha Kamran";
	name[1] = "Hassan Raza";
	name[2] = "Fardeen Farhat";
	name[3] = "Adil Majeed";
	name[4] = "Ibaad Ahmed";
	name[5] = "Abdullah Mazhar";
	name[6] = "Sahal Saeed";
	name[7] = "Asher Khan";
	name[8] = "Essam Wali";
	name[9] = "Noorzai Khan";
	name[10] = "Haider Niazi";
}
Teacher::~Teacher()
{
	delete [] courses;
	delete [] coursecodes;
	delete [] name;
	delete [] username;
	delete [] password;
}
void Teacher::importdata()
{
	ifstream a;
	string temp;
	a.open("Course Registration Data - Sheet1.csv",ios::in);
	getline(a,temp);
	// cout<<temp<<endl;
	for(int i=0,j=0;temp[i]!='\0';i++)
	{
		if(temp[i]==',' && i>2)
		{
			j++;
		}
		if(temp[i]!=',')
		{
			courses[j]+=temp[i];
		}
	}
	getline(a,temp);
	for(int i=0,j=0;temp[i]!='\0';i++)
	{
		if(temp[i]==',' && i>24)
		{
			j++;
		}
		if(temp[i]!=',' && i>24)
		{
			coursecodes[j]+=temp[i];
		}
	}
}
void Teacher::displaycourses()
{
	cout<<"Courses : "<<endl;
	for(int i=0;i<11;i++)
	{
		cout<<i+1<<"- "<<courses[i]<<endl;
	}
}
void Teacher::displaycoursecodes()
{
	cout<<"Course Codes : "<<endl;
	for(int i=0;i<11;i++)
	{
		cout<<i+1<<"- "<<coursecodes[i]<<endl;
	}
}
void Teacher::generateusername()
{
	for(int i=0;i<11;i++)
	{
		for(int j=0;name[i][j]!=' ';j++)
		{
			username[i]+=name[i][j];
		}
		username[i]+='_';
		for(int j=3;coursecodes[i][j]!='\0';j++)
		{
			username[i]+=coursecodes[i][j];
		}
	}
}
void Teacher::displayusername()
{
	cout<<"Username : "<<endl;
	for(int i=0;i<11;i++)
	{
		cout<<i<<"- "<<username[i]<<endl;
	}
}
void Teacher::generatepassword()
{
	for(int i=0;i<11;i++)
	{
		for(int j=0;name[i][j]!=' ';j++)
		{
			password[i]+=name[i][j];
		}
		char temp;
		for(int k=1;k<4;k++)
		{
			temp = k + 48;
			password[i]+=temp;
		}
	}
}
void Teacher::displaypassword()
{
	for(int i=0;i<11;i++)
	{
		cout<<i<<"- "<<password[i]<<endl;
	}
}
bool Teacher::validateusername(string a)
{
	for(int i=0;i<11;i++)
	{
		if(this->username[i]==a)
		{
			return 1;
		}
	}
	return 0;
}
bool Teacher::validatepassword(string a)
{
	for(int i=0;i<11;i++)
	{
		if(this->password[i]==a)
		{
			return 1;
		}
	}
	return 0;
}
void Teacher::setcurrentuser(string temp)
{
	this -> currentuser = temp;
}
string Teacher::getcurrentuser()
{
	return this -> currentuser;
}
string* Teacher::getusernames()
{
	return this -> username;
}
string Teacher::getcourse(int index)
{
	return courses[index];
}
int Teacher::getcurrentteacherindex()
{
	int indexT=0;
    for(int i=0;i<11;i++)
    {
        if (currentuser == username[i])
        {
            indexT = i;
            break;
        }
    }
	return indexT;
}
void Teacher::changepassword()
{
	string password;
	char* passwordchar;
	x:
	cout<<"Enter the new password you would like to enter."<<endl;
	cout<<"Criterias : "<<endl;
	cout<<"1. Minimum 6 length"<<endl;
	cout<<"2. Must Contain Uppercase, Lowercase, numeric digit and a special character"<<endl;
	passwordchar = getpass("New Password :");
	password = passwordchar;
	int check1=0;
	int check2=0;
	int check3=0;
	int check4=0;
	int check5=0;
    if(password.length()>=6)
	{
		check1=1;
	}
	for(int i=0;password[i]!='\0';i++)
	{
		if(isupper(password[i]))
		{
			check2=1;
		}
		else if(islower(password[i]))
		{
			check3=1;
		}
		else if(isdigit(password[i]))
		{
			check4=1;
		}
        else
        {
            check5=1;
        }
		
	}
	if(check1 && check2 && check3 && check4 && check5)
	{
		this->password[getcurrentteacherindex()] = password;
		cout<<"Password Successfully created."<<endl;
	}
	else
	{
		cout<<"Invalid password format. Please make sure to complete all the criterias."<<endl;
		goto x;
	}
}
void Teacher::currentdetails()
{
	cout<<"Name : "<<name[getcurrentteacherindex()]<<endl;
	cout<<"Course : "<<courses[getcurrentteacherindex()]<<endl;
	cout<<"Course Code : "<<coursecodes[getcurrentteacherindex()]<<endl;
	cout<<"Username : "<<username[getcurrentteacherindex()]<<endl;
	cout<<"Password : "<<password[getcurrentteacherindex()]<<endl;
}
