#include "subjective.h"
subjective::subjective()
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
}
void subjective::import()
{
    //Questions
    ifstream a;
    string temp;
    a.open("subjective.txt",ios::in);
    getline(a,temp);
    for(int i=0,j=0,k=0;i<130;i++)
    {
        if(k>4)
        {
            k=0;
            j++;
        }
        if(temp[0]=='Q' && temp!="\n")
        {
            for(int l=2;temp[l]!='\0';l++)
            {
                questions[j][k]+=temp[l];
            }
            k++;
            getline(a,temp);
        }
        else
        {
            getline(a,temp);
        }
    }
    a.close();
    //Answers
    a.open("subjective.txt",ios::in);
    getline(a,temp);
    for(int i=0,j=0,k=0;i<131;i++)
    {
        if(k>4)
        {
            k=0;
            j++;
        }
        if(temp[0]=='A' && temp[1]=='n' && temp[2]=='s')
        {
            for(int l=8;temp[l]!='\0';l++)
            {
                answers[j][k]+=temp[l];
            }
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
void subjective::display()
{
    // cout<<"Questions"<<endl;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<"Q. ";
            cout<<questions[i][j]<<endl;
            cout<<"Ans. ";
            cout<<answers[i][j]<<endl;
        }
        cout<<endl;
    }
}
string subjective::getquestion(int index1,int index2)
{
    return questions[index1][index2];
}
string subjective::getanswer(int index1,int index2)
{
    return answers[index1][index2];
}