#include "quiz.h"
#include <iomanip>
quiz::quiz()
{
    marks = new float[216]{0};
    attendance = new char[216];
    for(int i=0;i<216;i++)
    {
        attendance[i]='A';
    }
    created=0;
    b.importdata();
    b.generateusername();
    c.importdata();
    c.importcoursenames();
    c.importcourses();
}
void quiz::setquiz(string tempteacher)
{
    b.setcurrentuser(tempteacher);
    a.importdata();
    mcq.importquestions();
    mcq.importoptionsandanswers();
    subj.import();
    // b.importdata();
    // b.setcurrentuser("Suzuki_201");
    x:
    cout<<"Enter num of T/F you want in your quiz : ";
    cin>>this->numof_tf;
    if(this -> numof_tf >5 || this-> numof_tf == 0)
    {
        cout<<"Num of questions cannot exceed number of questions available or cannot be zero. Please choose a number between 1-5."<<endl;
        goto x;
    }
    cout<<"Enter num of MCQS you want in your quiz : ";
    cin>>this->numofmcqs;
    if(this -> numofmcqs >5 || this-> numofmcqs == 0)
    {
        cout<<"Num of questions cannot exceed number of questions available or cannot be zero. Please choose a number between 1-5."<<endl;
        goto x;
    }
    cout<<"Enter num of subjective questions you want in your quiz : ";
    cin>>this->numofsubj;
    if(this -> numofsubj >5 || this-> numofsubj == 0)
    {
        cout<<"Num of questions cannot exceed number of questions available or cannot be zero. Please choose a number between 1-5."<<endl;
        goto x;
    }
    totalnoquestions = numof_tf + numofmcqs + numofsubj;
    questionsselected = new string[totalnoquestions];
    answersselected = new string [totalnoquestions];
    optionsselected = new string[totalnoquestions];
    marks = new float[216]{0};
    attendance = new char[216];
    for(int i=0;i<216;i++)
    {
        attendance[i]='A';
    }
}
void quiz::randomize()
{
    srand(time(0));
    int indexT=0;
    for(int i=0;i<11;i++)
    {
        if (b.getcurrentuser() == b.getusernames()[i])
        {
            indexT = i;
            break;
        }
    }
    currentcourse = b.getcourse(indexT);
    int arr[totalnoquestions];
    int temp;
    int counter=0;
    int randotemp;
    if(numof_tf>numofmcqs && numof_tf>numofsubj)
    {
        randotemp = numof_tf;
    }
    else if(numofmcqs>numof_tf && numofmcqs>numofsubj)
    {
        randotemp = numofmcqs;
    }
    else
    {
        randotemp = numofsubj;
    }
    for(int i=0;i<randotemp;i++)
    {
        lmao:
        temp = rand()%5;
        if(temp != arr[0] && temp != arr[1] && temp != arr[2] && temp != arr[3] && temp != arr[4])
        {
            arr[i]=temp;
        }
        else
        {
            goto lmao;
        }
    }
    for(int i=0;i<numof_tf;i++)
    {
        questionsselected[i] = a.getquestion(indexT,arr[i]);
        answersselected[i] = a.getanswer(indexT,arr[i]);
        counter=i;
    }
    for(int i=0,j=counter+1;i<numofmcqs;i++,j++)
    {
        questionsselected[j] = mcq.getquestion(indexT,arr[i]);
        answersselected[j] = mcq.getanswer(indexT,arr[i]);
        optionsselected[j] = mcq.getoption(indexT,arr[i]);
        // cout<<"jeff"<<endl;
        counter=j;
    }
    for(int i=0,j=counter+1;i<numofsubj;i++,j++)
    {
        questionsselected[j] = subj.getquestion(indexT,arr[i]);
        answersselected[j] = subj.getanswer(indexT,arr[i]);
        // cout<<"jeff"<<endl;
        // counter=i;
    }
}
void quiz::displayrandomquestions()
{
    cout<<"These are your questions selected for your quiz: "<<endl;
    for(int i=0;i<totalnoquestions;i++)
    {
        cout<<i+1<<". "<<questionsselected[i]<<endl;
    }
}
void quiz::displayrandomanswers()
{
    cout<<"Answers : "<<endl;
    for(int i=0;i<totalnoquestions;i++)
    {
        cout<<i+1<<". "<<answersselected[i]<<endl;
    }
}
void quiz::displayteachercourse()
{
    cout<<"Teacher : "<<b.getcurrentuser()<<endl;
    cout<<"Course : "<<currentcourse<<endl;
}
Teacher quiz::getTeacher()
{
    return b;
}
void quiz::setbool(int a)
{
    this -> created = a;
}
int quiz::getbool()
{
    return created;
}
int quiz::getnumoftf()
{
    return numof_tf;
}
int quiz::getnumofmcqs()
{
    return numofmcqs;
}
int quiz::getnumofquestions()
{
    return (numof_tf + numofmcqs);
}
void quiz::displayquestiontostudent(int i)
{
    cout<<questionsselected[i]<<endl;
}
void quiz::checkanswertf(char answer,int i,int studentindex)
{
    if(answer == answersselected[i][0])
    {
        marks[studentindex]+=1;
    }
}
void quiz::checkanswermcq(char answer,int i,int studentindex)
{
    int answerindex=0;
    if(answer=='A' || answer=='a')
    {
        answerindex=0;
    }
    if(answer=='B' || answer=='b')
    {
        answerindex=1;
    }
    if(answer=='C' || answer=='c')
    {
        answerindex=2;
    }
    if(answer=='D' || answer=='d')
    {
        answerindex=3;
    }
    string* options;
    options = new string[4];
    int counter=0;
    for(int j=0;optionsselected[i][j]!='\0';j++)
    {
        if(optionsselected[i][j]!=',')
        {
            options[counter]+=optionsselected[i][j];
        }
        else
        {
            counter++;
        }
    }
    if(options[answerindex] == answersselected[i])
    {
        marks[studentindex]+=1;
    }
}
float quiz::getmarks(int index)
{
    return marks[index];
}
void quiz::generatemarksheet(int index)
{
    ofstream a;
    a.open("marksheet.txt",ios::out | ios::trunc);
    a<<"Name\t\t\t\t\t\tMarks"<<endl;
    for(int i=0;i<216;i++)
    {
        string temp="";
        if(c.getcourse(i,index)=='1')
        {
            for(int j=0;c.getname(i)[j]!='\0';j++)
            {
                temp+=c.getname(i)[j];
            }
            a<<left<<setw(30)<<temp<<setw(30)<<left<<marks[i]<<endl;
            // a<<c.getname(i)<<" == "<<marks[i]<<endl;
        }
    }
}
void quiz::setattendance(int index)
{
    attendance[index]='P';
}
void quiz::generateattendacesheet(int index)
{
    ofstream a;
    a.open("attendace.txt",ios::out | ios::trunc);
    a<<"Name\t\t\t\t\t\tAttendance"<<endl;
    for(int i=0;i<216;i++)
    {
        string temp="";
        if(c.getcourse(i,index)=='1')
        {
            for(int j=0;c.getname(i)[j]!='\0';j++)
            {
                temp+=c.getname(i)[j];
            }
            a<<left<<setw(30)<<temp<<setw(30)<<left<<attendance[i]<<endl;
        }
    }
}
void quiz::clear()
{
    for(int i=0;i<totalnoquestions;i++)
    {
        questionsselected[i]="";
        answersselected[i]="";
    }
}
void quiz::displayoptions(int index)
{
    int comma=0;
    bool flag=1;
    for(int i=0;optionsselected[index][i]!='\0';i++)
    {
        if(flag)
        {
            cout<<(char)(65+comma)<<". ";
        }
        if(optionsselected[index][i]!=',')
        {
            flag=0;
            cout<<optionsselected[index][i];
        }
        else
        {
            flag=1;
            cout<<endl;
            comma++;
        }
        
    }
    cout<<endl;
}
int quiz::getnumofsubj()
{
    return numofsubj;
}
void quiz::checkanswersubj(string answer,int i,int studentindex)
{
    float tempmarks=0;
    tempmarks = answer.length();
    tempmarks*=0.01;
    if(tempmarks>=3)
    {
        marks[studentindex]+=3;
    }
    else
    {
        marks[studentindex]+=tempmarks;
    }
}
void quiz::generateanalytics(int index)
{
    // Draw the bar chart
    for(int i=0;i<216;i++)
    {
        string temp="";
        if(c.getcourse(i,index)=='1')
        {
            for(int j=0;c.getname(i)[j]!='\0';j++)
            {
                temp+=c.getname(i)[j];
            }
            cout<<setw(25)<<left<<temp;
            cout<<setw(5)<<"===";
            for(int j=0;j<marks[i] * 5;j++)
            {
                cout<<setw(2)<<right<<">";
            }
            cout<<endl;
        }
    }
}