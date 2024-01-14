// #include "person.h"
#include "quiz.h"
#include <unistd.h>
// #include "teacher.h"
// #include "student.h"
using namespace std;
void menu()
{
	int duration;
	int choice=0;
	quiz quizzy[11];
	int currentteacherindex;
	date teacher_date[11];
	date student_date;
	y:
	cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║          WELCOME TO THE ZAIN EXAMINATION      ║" << endl;
    cout << "║                     PORTAL                    ║" << endl;
    cout << "╠═══════════════════════════════════════════════╣" << endl;
    cout << "║                                               ║" << endl;
    cout << "║              TEACHER PORTAL (0)               ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "║              STUDENT PORTAL (1)               ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "║              QUIT THE PORTAL (2)              ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;
    cout << "Option: ";
	cin>>choice;
	if(choice==0)
	{
		Teacher tch;
		tch.importdata();
		tch.generateusername();
		tch.generatepassword();
		string username;
		string password;
		char* passwordchar;
		teacherportal:
		cout << "╔═══════════════════════════════════════════════╗" << endl;
		cout << "║                                               ║" << endl;
		cout << "║       WELCOME TO THE ZAIN TEACHER PORTAL      ║" << endl;
		cout << "║                                               ║" << endl;
		cout << "╚═══════════════════════════════════════════════╝" << endl;
		beginningteacher:
		cout<<"Enter your username please"<<endl;
		cout<<"Format : name_coursecode(without the degree)"<<endl;
		cin>>username;
		if(tch.validateusername(username))
		{
			tch.setcurrentuser(username);
			cout<<"Enter your password please"<<endl;
			cout<<"Format : name123 (only if you haven't changed your password)"<<endl;
			passwordchar = getpass("Password :");
			password = passwordchar;
			if(tch.validatepassword(password))
			{
				cout<<"WELCOME! You have succesfully logged in."<<endl;
				z:
				cout << "╔═══════════════════════════════════════════════╗" << endl;
				cout << "║                MAKE QUIZ (1)                  ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║             CHANGE PASSWORD (2)               ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║               DISPLAY QUIZ (3)                ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║            GENERATE MARKSHEET (4)             ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║           GENERATE ATTENDANCE (5)             ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║           GENERATE ANALYTICS (6)              ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║         GO BACK TO TEACHER PORTAL (7)         ║" << endl;
				cout << "║═══════════════════════════════════════════════║" << endl;
				cout << "║          GO BACK TO LOGIN PORTAL (8)          ║" << endl;
				cout << "╚═══════════════════════════════════════════════╝" << endl;
				cout << "What menu would you like to go to? : " << endl;
				cin>>choice;
				if(choice==1)
				{
					if(quizzy[tch.getcurrentteacherindex()].getbool())
					{
						quizalreadycreated:
						cout<<"Quiz has already been created. Do you wish to create a new quiz? (0 = NO , 1 = YES)"<<endl;
						cin>>choice;
						if(choice==0)
						{
							cout<<"Taking you back to teacher login portal."<<endl;
							goto z;
						}
						else if(choice==1)
						{
							cout<<"Previous quiz cleared."<<endl;
							quizzy[tch.getcurrentteacherindex()].clear();
						}
						else
						{
							cout<<"Please choose a valid choice."<<endl;
							goto quizalreadycreated;
						}
					}
					currentteacherindex = tch.getcurrentteacherindex();
					cout<<"Enter the date and time you would like your quiz to start."<<endl;
					teacher_date[tch.getcurrentteacherindex()].setdateandtime();
					cout<<"Enter the duration of your quiz : ";
					cin>>duration;
					quizzy[tch.getcurrentteacherindex()].setquiz(username);
					quizzy[tch.getcurrentteacherindex()].randomize();
					cout<<endl;
					teacher_date[tch.getcurrentteacherindex()].display();
					cout<<endl<<"Duration : "<<duration<<endl;
					cout<<endl;
					quizzy[tch.getcurrentteacherindex()].displayteachercourse();
					cout<<endl;
					quizzy[tch.getcurrentteacherindex()].displayrandomquestions();
					cout<<endl;
					quizzy[tch.getcurrentteacherindex()].displayrandomanswers();
					cout<<endl;
					cout<<"Successfully Created Quiz. Taking you back to Teacher login now."<<endl<<endl;
					quizzy[tch.getcurrentteacherindex()].setbool(1);
					goto z;
				}
				else if(choice==2)
				{
					tch.changepassword();
					tch.currentdetails();
					goto z;
				}
				else if(choice==3)
				{
					if(quizzy[tch.getcurrentteacherindex()].getbool())
					{
						teacher_date[tch.getcurrentteacherindex()].display();
						cout<<endl;
						cout<<"Duration : "<<duration<<endl;
						quizzy[tch.getcurrentteacherindex()].displayteachercourse();
						cout<<endl;
						quizzy[tch.getcurrentteacherindex()].displayrandomquestions();
						cout<<endl;
						quizzy[tch.getcurrentteacherindex()].displayrandomanswers();
						cout<<endl;
						cout<<"Taking you back to teacher portal. Thank you."<<endl;
						goto z;
					}
					else
					{
						cout<<"No quiz created yet. Taking you back to teacher portal. Thank you."<<endl;
						goto z;
					}
					
				}
				else if(choice==4)
				{
					char temp;
					quizzy[tch.getcurrentteacherindex()].generatemarksheet(tch.getcurrentteacherindex());
					cout<<"Marks sheet generated :)"<<endl;
					lmao:
					cout<<"Enter 1 to continue"<<endl;
					cin>>temp;
					if(temp=='1')
					{
						goto z;
					}
					else
					{
						cout<<"You have to press 1 to continue :) "<<endl;
						goto lmao;
					}
				}
				else if(choice==5)
				{
					char temp;
					quizzy[tch.getcurrentteacherindex()].generateattendacesheet(tch.getcurrentteacherindex());
					cout<<"Attendace sheet generated :)"<<endl;
					lmao3:
					cout<<"Enter 1 to continue"<<endl;
					cin>>temp;
					if(temp=='1')
					{
						goto z;
					}
					else
					{
						cout<<"You have to press 1 to continue :) "<<endl;
						goto lmao3;
					}
				}
				else if(choice==6)
				{
					char temp;
					analyticting:
					quizzy[tch.getcurrentteacherindex()].generateanalytics(tch.getcurrentteacherindex());
					cout<<"Enter 1 to continue"<<endl;
					cin>>temp;
					if(temp=='1')
					{
						goto z;
					}
					else
					{
						cout<<"You have to press 1 to continue :) "<<endl;
						goto analyticting;
					}
					goto z;
				}
				else if(choice==7)
				{
					goto teacherportal;
				}
				else if(choice==8)
				{
					goto y;
				}
				else
				{
					cout<<"Choose a valid option please."<<endl;
					goto z;
				}
			}
			else
			{
				cout<<"Incorrect password. Please try again."<<endl;
				goto beginningteacher;
			}
		}
		else
		{
			cout<<"Incorrect username. Please try again."<<endl;
			goto beginningteacher;
		}
	}
	else if(choice==1)
	{
		student stud;
		stud.importdata();
		stud.importcourses();
		stud.importcoursenames();
		stud.generateusername();
		stud.generatepassword();
		string username;
		string password;
		char* passwordchar;
		studentportalting:
		cout << "╔═══════════════════════════════════════════════╗" << endl;
		cout << "║                                               ║" << endl;
		cout << "║       WELCOME TO THE ZAIN STUDENT PORTAL      ║" << endl;
		cout << "║                                               ║" << endl;
		cout << "╚═══════════════════════════════════════════════╝" << endl;
		beginningstudent:
		cout<<"Enter your username please"<<endl;
		cout<<"Format : name_rollnum(without the year and 'i')"<<endl;
		cin>>username;
		stud.setcurrentuser(username);
		if(stud.validateusername(username))
		{
			cout<<"Enter your password please"<<endl;
			cout<<"Format : name123 (only if you haven't changed your password)"<<endl;
			passwordchar = getpass("Password :");
			password = passwordchar;
			if(stud.validatepassword(password))
			{
				cout<<"WELCOME! You have succesfully logged in."<<endl;
				studentportal:
				cout << "╔═══════════════════════════════════════════════╗" << endl;
				cout << "║                TAKE QUIZ (1)                  ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║             CHANGE PASSWORD (2)               ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║        DISPLAY PERSONAL INFORMATION (3)       ║" << endl;
				cout << "╠═══════════════════════════════════════════════╣" << endl;
				cout << "║         GO BACK TO STUDENT PORTAL (4)         ║" << endl;
				cout << "║═══════════════════════════════════════════════║" << endl;
				cout << "║          GO BACK TO LOGIN PORTAL (5)          ║" << endl;
				cout << "╚═══════════════════════════════════════════════╝" << endl;
				cout << "What menu would you like to go to? : " << endl;
				cin>>choice;
				if(choice==1)
				{
					cout<<"Enter your current time "<<stud.getname(stud.getcurrentstudentindex())<<endl;
					student_date.setdateandtime();
					if(student_date.validate(teacher_date[currentteacherindex],duration))
					{
							cout<<"Welcome to your quiz. I hope you are prepared to attempt your quiz."<<endl;
							stud.takequiz();
							cout<<"Which quiz would you like to take? : ";
							cin>>choice;
							if(stud.checkcourse(choice))
							{
								if(quizzy[choice-1].getbool())
								{
									char answer;
									int counter;
									cout<<endl;
									student_date.display();
									cout<<endl;
									cout<<"Your quiz is from ";
									quizzy[choice-1].displayteachercourse();
									cout<<endl<<"Duration : "<<duration<<endl;
									cout<<"Quiz is starting. Please make sure to read the questions carefully. Good luck."<<endl;
									// quizzy[choice-1].displayrandomquestions();
									cout<<"True False"<<endl;
									for(int i=0;i<quizzy[choice-1].getnumoftf();i++)
									{
										questionstart:
										cout<<i+1<<". ";
										quizzy[choice-1].displayquestiontostudent(i);
										cout<<"Answer (1 == True , 0 == False): ";
										cin>>answer;
										if(answer!= '1' && answer!= '0' )
										{
											cout<<"Enter a valid answer please. Thank you."<<endl;
											goto questionstart;
										}
										quizzy[choice-1].checkanswertf(answer,i,stud.getcurrentstudentindex());
										counter=i;
									}
									cout<<"MCQS"<<endl;
									for(int i=counter+1,j=0;j<quizzy[choice-1].getnumofmcqs();i++,j++)
									{
										questionstartmcq:
										cout<<j+1<<". ";
										quizzy[choice-1].displayquestiontostudent(i);
										quizzy[choice-1].displayoptions(i);
										cout<<"Answer (A,B,C,D): ";
										cin>>answer;
										if(answer!= 'A' && answer!= 'a' && answer!= 'B' && answer!= 'b' && answer!= 'C' && answer!= 'c' && answer!= 'D' && answer!= 'd')
										{
											cout<<"Enter a valid answer please. Thank you."<<endl;
											goto questionstartmcq;
										}
										quizzy[choice-1].checkanswermcq(answer,i,stud.getcurrentstudentindex());
										counter=i;
									}
									cout<<"Subjective"<<endl;
									for(int i=counter+1,j=0;j<quizzy[choice-1].getnumofsubj();i++,j++)
									{
										string answersubj;
										cout<<j+1<<". ";
										quizzy[choice-1].displayquestiontostudent(i);
										cout<<"Answer: ";
										cin.ignore();
										getline(cin,answersubj);
										quizzy[choice-1].checkanswersubj(answersubj,i,stud.getcurrentstudentindex());
									}
									// char temp;
									cout<<"Marks : ("<<quizzy[choice-1].getmarks(stud.getcurrentstudentindex())<<" \\ "<<((quizzy[choice-1].getnumofquestions())+(quizzy[choice-1].getnumofsubj()*3))<<")"<<endl;
									cout<<"Your attendace has been marked as present. Good bye :)"<<endl;
									quizzy[choice-1].setattendance(stud.getcurrentstudentindex());
									lmao2:
									char temp;
									cout<<"Enter 1 to continue"<<endl;
									cin>>temp;
									if(temp=='1')
									{
										goto studentportal;
									}
									else
									{
										cout<<"You have to press 1 to continue :) "<<endl;
										goto lmao2;
									}
								}
								else
								{
									cout<<"Quiz has not been created yet. Please wait for your teacher to create the quiz first. Thank you."<<endl;
									goto studentportal;
								}
							}
							else
							{
								cout<<"Please choose a quiz of a course which you are registered in. Thank you."<<endl;
								cout<<"Taking you back to student portal..."<<endl;
								goto studentportal;
							}
					}
					else
					{
						cout<<"Your time is not the same as your teacher. Please wait for the time your teacher instructed your quiz to start. Thank you."<<endl;
						goto studentportal;
					}
				}
				else if(choice==2)
				{
					stud.changepassword();
					stud.currentdetails();
					goto studentportal;
				}
				else if(choice==3)
				{
					cout<<"Personal Information"<<endl;
					stud.currentdetails();
					goto studentportal;
				}
				else if(choice==4)
				{
					cout<<"Taking you back to student portal..."<<endl;
					goto studentportalting;
				}
				else if(choice==5)
				{
					cout<<"Taking you back to login portal..."<<endl;
					goto y;
				}
				else
				{
					cout<<"Choose a valid option please."<<endl;
					goto studentportal;
				}
			}
			else
			{
				cout<<"Incorrect password. Please try again."<<endl;
				goto beginningstudent;
			}
		}
		else
		{
			cout<<"Incorrect username. Please try again."<<endl;
			goto beginningstudent;
		}
	}
	else if(choice==2)
	{
		cout << "╔═══════════════════════════════════════════════╗" << endl;
		cout << "║                                               ║" << endl;
		cout << "║       GOOD BYE HOPE TO SEE U AGAIN :)         ║" << endl;
		cout << "║                                               ║" << endl;
		cout << "╚═══════════════════════════════════════════════╝" << endl;
		return;
	}
	else
	{
		cout<<"Invalid Input. Please enter a valid choice."<<endl;
		goto y;
	}
}