#include "truefalse.h"
#include "fstream"
truefalse::truefalse()
{
    questions = new string*[11];
    for(int i=0;i<11;i++)
    {
        questions[i] = new string[5];
    }
    answers = new char*[11];
    for(int i=0;i<11;i++)
    {
        answers[i] = new char[5];
    }
}
void truefalse::importdata()
{
    ifstream a;
    string temp;
    a.open("truefalse.txt",ios::in);
    getline(a,temp);
    for(int i=0,j=0,k=0;i<130;i++)
    {
        if(i%2==1 && temp!="NEXT")
        {
            if(k>4)
            {
                k=0;
                j++;
            }
            questions[j][k]=temp;
            k++;
            getline(a,temp);
        }
        else
        {
            getline(a,temp);
        }
    }
    a.close();
    //ifstream a;
    a.open("truefalse.txt",ios::in);
    getline(a,temp);
    for(int i=0,j=0,k=0;i<130;i++)
    {
        if(i%2==0 && (temp[0]=='0' || temp[0]=='1'))
        {
            if(k>4)
            {
                k=0;
                j++;
            }
            answers[j][k]=temp[0];
            k++;
            getline(a,temp);
        }
        else
        {
            getline(a,temp);
        }
    }
}
void truefalse::display()
{
    cout<<"Questions : "<<endl;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<questions[i][j]<<endl;
        }
    }
    cout<<"Answers : "<<endl;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<answers[i][j]<<endl;
        }
    }
}
string truefalse::getquestion(int index1,int index2)
{
    return questions[index1][index2];
}
char truefalse::getanswer(int index1,int index2)
{
    return answers[index1][index2];
}