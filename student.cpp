#include "student.h"
#include <unistd.h>
student::student()
{
    rollnum = new string[216];
    name = new string[216];
    username = new string[216];
	password = new string[216];
    coursenames = new string[11];
    courses = new char*[216];
    for(int i=0;i<216;i++)
    {
        courses[i] = new char[11];
    }
}
student::~student()
{
    delete [] rollnum;
    delete [] name;
    delete [] username;
    delete [] password;
    delete [] coursenames;
    for(int i=0;i<216;i++)
    {
        delete [] courses[i];
    }
    delete [] courses;
}
void student::importcoursenames()
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
			coursenames[j]+=temp[i];
		}
	}
	// getline(a,temp);
}
void student::importcourses()
{
    ifstream a;
    string temp1,temp2,temp;
    a.open("Course Registration Data - Sheet1.csv",ios::in);
    getline(a,temp1);
    getline(a,temp2);
    getline(a,temp);
    int commafound=0;
    for(int i=0,j=0,l=0;j<216;i++)
    {
        if(temp[i]==',')
        {
            commafound++;
        }
        if(commafound>=3)
        {
            if(temp[i]!=',' && l<11)
            {
                //cout<<temp[i]<<" ";
                courses[j][l]=temp[i];
                //cout<<courses[j][l];
                //cout<<l<<" ";
                l++;
            }
        }
        if(temp[i]=='\0')
        {
            j++;
            i=0;
            l=0;
            commafound=0;
            //cout<<endl;
            getline(a,temp);
        }
    }
}
void student::importdata()
{
    ifstream a;
    string temp1,temp2,temp;
    a.open("Course Registration Data - Sheet1.csv",ios::in);
    getline(a,temp1);
    getline(a,temp2);
    getline(a,temp);
    for(int i=0,j=0;j<216;i++)
    {
        if(j<=9)
        {
            if(temp[i]!=',' && (i>1 && i<11))
            {
                rollnum[j]+=temp[i];
            }
        }
        if(j>9)
        {
            if(temp[i]!=',' && (i>2 && i<12))
            {
                rollnum[j]+=temp[i];
            }
        }
        if(i>=11 && i<=13 && j<99)            
        {
            for(int k=0;temp[i]!=',';k++,i++)
            {
                name[j]+=temp[i];
            }
        }
        if(i>=11 && i<=13 && j>=99)            
        {
            for(int k=0;temp[i]!=',';k++,i++)
            {
                name[j]+=temp[i];
            }
        }
        if(temp[i]=='\0')
        {
            //Start
            //Changing the position of the student name characters one position to the left to replace the roll num accidentally coming inside the stuedent name
            if(j>=99)
            {
                int temp_count=0;
                for(int i=1;name[j][i]!='\0';i++)
                {
                    name[j][i-1] = name[j][i];
                    temp_count=i;
                }
                name[j][temp_count]='\0';
            }
            //Finish
            j++;
            i=0;
            getline(a,temp);
        }
    }
}
void student::displayrollnum()
{
    cout<<"Roll No. : "<<endl;
    for(int i=0;i<216;i++)
    {
        cout<<i<<" - "<<rollnum[i]<<endl;
    }
}
void student::displaystudentname()
{
    cout<<"Student Names. : "<<endl;
    for(int i=0;i<216;i++)
    {
        cout<<i<<" - "<<name[i]<<endl;
    }
}
void student::generateusername()
{
	for(int i=0;i<216;i++)
	{
		for(int j=0;name[i][j]!=' ' && name[i][j]!='\0';j++)
		{
			username[i]+=name[i][j];
		}
        username[i]+='_';
        for(int j=4;rollnum[i][j]!='\0';j++)
        {
            username[i]+=rollnum[i][j];
        }
	}
}
void student::displayusername()
{
	cout<<"Username : "<<endl;
	for(int i=0;i<216;i++)
	{
		cout<<i<<"- "<<username[i]<<endl;
	}
}
void student::generatepassword()
{
	for(int i=0;i<216;i++)
	{
		for(int j=0;name[i][j]!=' ' && name[i][j]!='\0';j++)
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
void student::displaypassword()
{
	for(int i=0;i<216;i++)
	{
		cout<<i<<"- "<<password[i]<<endl;
	}
}
void student::displaycourses()
{
    for(int i=0;i<216;i++)
    {
        cout<<name[i]<<" : ";
        for(int j=0;j<11;j++)
        {
            cout<<courses[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool student::validateusername(string a)
{
	for(int i=0;i<216;i++)
	{
		if(this->username[i]==a)
		{
			return 1;
		}
	}
	return 0;
}
bool student::validatepassword(string a)
{
	for(int i=0;i<216;i++)
	{
		if(this->password[i]==a)
		{
			return 1;
		}
	}
	return 0;
}
void student::setcurrentuser(string temp)
{
    this->currentuser = temp;
}
int student::getcurrentstudentindex()
{
	int indexT=0;
    for(int i=0;i<216;i++)
    {
        if (currentuser == username[i])
        {
            indexT = i;
            break;
        }
    }
	return indexT;
}
void student::changepassword()
{
    string password;
    char* passwordchar;
	x:
	cout<<"Enter the new password you would like to enter."<<endl;
	cout<<"Criterias : "<<endl;
	cout<<"1. Minimum 6 length"<<endl;
	cout<<"2. Must Contain Uppercase, Lowercase, numeric digit and a special character"<<endl;
	cout<<"New Password : ";
	passwordchar = getpass("Password :");
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
		this->password[getcurrentstudentindex()] = password;
		cout<<"Password Successfully created."<<endl;
	}
	else
	{
		cout<<"Invalid password format. Please make sure to complete all the criterias."<<endl;
		goto x;
	}
}
void student::currentdetails()
{
	cout<<"Name : "<<name[getcurrentstudentindex()]<<endl;
	cout<<"Username : "<<username[getcurrentstudentindex()]<<endl;
	cout<<"Password : "<<password[getcurrentstudentindex()]<<endl;
}
void student::takequiz()
{
    int option;
    cout<<"Which quiz would you like to give?"<<endl;
    for(int i=0;i<11;i++)
    {
        char temp = courses[getcurrentstudentindex()][i];
        if(temp=='1')
        {
            cout<<i+1<<". "<<coursenames[i]<<endl;
        }
    }
}
bool student::checkcourse(int choice)
{
    for(int i=0;i<11;i++)
    {
        char temp = courses[getcurrentstudentindex()][i];
        if(temp=='1')
        {
            if(choice==(i+1))
            {
                return 1;
            }
        }
    }
    return 0;
}
char student::getcourse(int i,int j)
{
    return courses[i][j];
}
string student::getname(int i)
{
    return name[i];
}