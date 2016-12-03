#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<fstream>
#include"Functions.h"
#include <conio.h> 
#include <windows.h>
#include <mmsystem.h>
#include<sstream>

using namespace std;

char line[1000];
fstream fTasks;

priority_queue<pair<int, pair<string, string> > > myQ;
	Tasks MyTasks;

void select()
{
	char select;
	select = _getch();
	if (select == '1')
		MyTasks.Enter_Task_Data(myQ);
	else if (select == '2')
		MyTasks.Display_Task_Data(myQ,0);
	else if (select == '3')
		MyTasks.Display_Next(myQ);
	else if (select == '4')
		MyTasks.Edit_Task(myQ);
	else if (select == '5')
		MyTasks.Task_Done(myQ);
	else if (select == '6')
		end(myQ);
	end(myQ);
}


int main() 
{
	fTasks.open("tasks.txt");
	while (true) {
		int Prio, co = 0;
		stringstream ss;
		string Description, Date, Priority;
		if (!fTasks)
			break;
		if (fTasks.getline(line, 1000)) {
			Priority = line;
			ss << Priority;
			ss >> Prio;
			co++;
		}
		if (fTasks.getline(line, 1000)) {
			Description = line;
			co++;
		}
		if (fTasks.getline(line, 1000)) {
			co++;
			Date = line;
		}
		if (co == 3)
		{
			myQ.push(make_pair(Prio, make_pair(Date, Description)));
		    MyTasks.NumberOfTasks++;
		}
	}

	fTasks.close();
	menu();
	return 0;
}