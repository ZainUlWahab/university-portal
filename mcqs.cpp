#include "mcqs.h"
#include <fstream>
mcqs::mcqs()
{
    questions = new string*[11];
    for(int i=0;i<11;i++)
    {
        questions[i] = new string[5];
    }
    answers = new string*[11];
    for(int i=0;i<11;i++)
    {
        answers[i] = new string[5];
    }
    options = new string*[11];
    for(int i=0;i<11;i++)
    {
        options[i] = new string[5];
    }
}
void mcqs::importquestions()
{
    ifstream a;
    string temp;
    a.open("mcqs.txt",ios::in);
    getline(a,temp);
    // cout<<temp;
    for(int i=0,j=0,k=0;i<350;i++)
    {
        if(k>4)
        {
            k=0;
            j++;
        }
        if(temp[0]=='W' && temp!="Walkthrough")
        {
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
}
void mcqs::importoptionsandanswers()
{
    ifstream a;
    string temp;
    a.open("mcqs.txt",ios::in);
    getline(a,temp);
    for(int i=0,j=0,k=0;i<350;i++)
    {
        if(k>4)
        {
            k=0;
            j++;
        }
        if(temp[0]=='W')
        {
            if(temp=="Walkthrough")
            {
                options[j][k]=temp;
            }
            else
            {
                getline(a,temp);
                i++;
                options[j][k]=temp;
            }
            options[j][k]+=',';
            getline(a,temp);
            i++;
            options[j][k]+=temp;
            options[j][k]+=',';
            getline(a,temp);
            i++;
            options[j][k]+=temp;
            options[j][k]+=',';
            getline(a,temp);
            i++;
            options[j][k]+=temp;
            getline(a,temp);
            for(int m=8;temp[m]!='\0';m++)
            {
                answers[j][k]+=temp[m];
            }
            k++;
        }
        else
        {
            getline(a,temp);
        }
    }
}
void mcqs::display()
{
    cout<<"Questions : "<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<i<<endl;
        for(int j=0;j<5;j++)
        {
            cout<<j<<". "<<questions[i][j];
            cout<<endl;
        }
    }
    cout<<"Options : "<<endl;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<options[i][j]<<endl;
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
string mcqs::getquestion(int index1,int index2)
{
    return questions[index1][index2];
}
string mcqs::getanswer(int index1,int index2)
{
    return answers[index1][index2];
}
string mcqs::getoption(int index1,int index2)
{
    return options[index1][index2];
}