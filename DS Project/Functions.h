#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;


class Tasks
{
public:
	int NumberOfTasks = 0;
	void Enter_Task_Data(priority_queue<pair<int, pair<string, string> > >& myQ);
    void Display_Task_Data(priority_queue<pair<int, pair<string, string> > > myQ,int y);
    void Task_Done(priority_queue<pair<int, pair<string, string> > >& myQ);
    void Edit_Task(priority_queue<pair<int, pair<string, string> > >& myQ);
    void Display_Next(priority_queue<pair<int, pair<string, string> > > myQ);
	//void Assign(priority_queue<pair<int, pair<string, string> > >& myQ);
	//void SaveText(priority_queue<pair<int, pair<string, string> > >& myQ);
};
void menu();
void end(priority_queue<pair<int, pair<string, string> > > myQ);
void select();
