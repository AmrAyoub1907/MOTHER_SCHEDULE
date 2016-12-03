#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<deque>
#include<string>
#include<fstream>
#include"Functions.h"
#include <conio.h> 
#include<sstream>
using namespace std;
void menu()
{
	
	system("cls");
	
	
	cout << "                             ::M E N U::    " << endl << endl;
	cout << "                            1: Enter task " << endl << endl;
	cout << "                            2: Display all tasks " << endl << endl;
	cout << "                            3: Display next task " << endl << endl;
	cout << "                            4: Edit task    " << endl << endl;
	cout << "                            5: Delete finished task     " << endl << endl;
	cout << "                            6: Exit     " << endl << endl;
	select();

}
void Tasks::Enter_Task_Data(priority_queue<pair<int, pair<string, string> > >& myQ)
{
	system("cls");
	int x;
	while (true)
	{

		cout << "Enter The Priority of The Task ? 1-->10 : ";
		int Priority;
		cin >> Priority;
		string Description, Date;
		cout << "Enter The Description Of The Task : ";
		cin.get();
		getline(cin, Description);
		cout << "Enter The Date Of The Task in the following format YYYY/MM/DD  : ";
		cin >> Date;
		cout << "\nTo continue entering tasks enter [0] or press anykey to go back :";
		x = _getch();
		myQ.push(make_pair(Priority, make_pair(Date, Description)));
		NumberOfTasks++;
		if (x != '0')
			break;
		cout << "\n";
	}
	menu();
}

void Tasks::Display_Task_Data(priority_queue<pair<int, pair<string, string> > > myQ, int y)
{
	system("cls");
	pair< int, pair<string, string> > temp;
	int TaskNumber = 1;
	char select;
	cout << "Total number of tasks : " << NumberOfTasks << endl << endl;
	while (!myQ.empty())
	{
		temp=myQ.top();
		myQ.pop();
		cout << "Task number : " << TaskNumber << endl;
		cout << "Task priority : " << temp.first<<endl;
		cout << "The task description : " << temp.second.second << endl;
		cout << "Task date : " << temp.second.first << endl;
		cout << "                             -----------------------------------" << endl;
		
		TaskNumber++;
	}

	if (y != 1) {
		cout << "                                         Press [B] to back" << endl;
		select = _getch();
		if (select == 'b' || select == 'B')
			menu();
	}
}

void Tasks::Task_Done(priority_queue<pair<int, pair<string, string> > >& myQ)
{
	system("cls");
	int Finished,counter=1;
	//Display_Task_Data(myQ);
	priority_queue<pair<int, pair<string, string> > > Temp;
	Display_Task_Data(myQ,1);
	cout << "Enter the number of the task you already finished : ";
	cin >> Finished;
	int looper = myQ.size();
	while (looper--)
	{
		if (counter != Finished)
			Temp.emplace(myQ.top());
		myQ.pop();
		counter++;
	}
	myQ = Temp;
	NumberOfTasks--;
	if (NumberOfTasks == 0)
		cout << "\n   ***** All tasks are finished that GREAT !  ******\n\n";
	menu();
}

void Tasks::Edit_Task(priority_queue<pair<int, pair<string, string> > >& myQ)
{
	system("cls");
	int EditNumber,counter=1;
	char choice;
	priority_queue<pair<int, pair<string, string> > > Temp;
	pair<int, pair<string, string> > TEnter;
	Display_Task_Data(myQ,1);
	cout << "Enter the number of the task you want to Edit : ";
	cin >> EditNumber;
	cout << "Enter 1 to edit the priority \nEnter 2 to edit the description\nEnter 3 to edit the date\n";
	choice = _getch();
	int looper = myQ.size();
	while (looper--)
	{
		if (counter != EditNumber)
			Temp.emplace(myQ.top());
		else
		{
			if (choice == '1')
			{
				system("cls");
				int TempPriority;
				cout << "Enter the new priority you want for this task: ";
				cin >> TempPriority;
				TEnter.first=TempPriority;
				TEnter.second.first = myQ.top().second.second;
				TEnter.second.second = myQ.top().second.first;
			}
			else if (choice == '2')
			{
				system("cls");
				string DescTemp;
				cout << "Enter the new description you want for this task: ";
				cin >> DescTemp;
				TEnter.first = myQ.top().first;
				TEnter.second.second = DescTemp;
				TEnter.second.first = myQ.top().second.first;

			}
			else if (choice == '3')
			{
				system("cls");
				string TempDate;
				cout << "Enter the new date you want for this task : ";
				cin >> TempDate;
				TEnter.first = myQ.top().first;
				TEnter.second.second = myQ.top().second.second;
				TEnter.second.first = TempDate;
			}
			else
			{ }
			Temp.emplace(TEnter);
		}
		myQ.pop();
		counter++;
	}
	myQ = Temp;
	menu();
}

void Tasks::Display_Next(priority_queue<pair<int, pair<string, string> > > myQ)
{
	system("cls");
	char ss;
	priority_queue<pair<string, pair<string, int> > > Temp;
	
	while (!myQ.empty())
	{
		Temp.push(make_pair(myQ.top().second.first,make_pair(myQ.top().second.second, myQ.top().first)));
		myQ.pop();
	}

	while (Temp.size()>1)
	{
		Temp.pop();
	}
	cout << "The next task to be done in you task list is : \n\n";
	cout << "Task priority : " << Temp.top().second.second << endl;
	cout << "The task description : " << Temp.top().second.first << endl;
	cout << "Task date : " << Temp.top().first << endl;
	cout << "-----------------------------------" << endl;
	cout << "Press [B] to back" << endl;
	ss = _getch();
	if (ss == 'b' || ss == 'B')
		menu();
}

void end(priority_queue<pair<int, pair<string, string> > > myQ)
{
	ofstream fTasks("tasks.txt");
	while (!myQ.empty())
	{
		fTasks << myQ.top().first << endl;
		fTasks << myQ.top().second.second << endl;
		fTasks << myQ.top().second.first << endl;
		myQ.pop();
	}
	fTasks.close();
}
