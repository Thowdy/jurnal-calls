#include "Journal.h"


Journal::Journal()
{
	strcpy(filename, "data.txt");
}
void Print_Title()
{
	cout << setw(10) << left << "ID" << setw(15) << "FROM" << setw(15) << "TO" << setw(15) << "DATE" << setw(15) << "TIME" << setw(15) << "DURATION" << endl;
}
void Journal::Print()
{
	Print_Title();
	for each (Call call in calls)
	{
		call.Print();
	}
}
void Journal::Sort()
{
	for (int i = 0; i < calls.size(); i++)
	{
		for (int j = 0; j < calls.size(); j++)
		{
			if (calls[i].getDURATION() > calls[j].getDURATION())
			{
				swap(calls[i], calls[j]);
			}
		}
	}
}
void Journal::FindFROM(char* from)
{
	Print_Title();
	for each (Call call in calls)
	{
		if (!strcmp(call.getFROM(), from))
		{
			call.Print();
		}
	}
}
bool CompareDATE(char *date_1, char *date_2)
{
	int a[3], b[3];
	char date1[20], date2[20];
	strcpy(date1, date_1);
	strcpy(date2, date_2);
	char * pch = strtok(date1, ".");
	a[0] = atoi(pch);
	pch = strtok(NULL, ".");
	a[1] = atoi(pch);
	pch = strtok(NULL, "");
	a[2] = atoi(pch);
	char * pch2 = strtok(date2, ".");
	b[0] = atoi(pch2);
	pch = strtok(NULL, ".");
	b[1] = atoi(pch2);
	pch = strtok(NULL, "");
	b[2] = atoi(pch2);
	if (a[2] > b[2])
	{
		return true;
	}
	else if (a[2] < b[2])
	{
		return false;
	}
	else
	{
		if (a[1] > b[1])
		{
			return true;
		}
		else if (a[1] < b[1])
		{
			return false;
		}
		else
		{
			if (a[0] >= b[0])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
void Journal::FindDATE(char* min, char* max)
{
	Print_Title();
	for each (Call call in calls)
	{
		if (CompareDATE(max, call.getDATE()) && CompareDATE(call.getDATE(), min));
		{
			call.Print();
		}
	}
}
void Journal::FindDURATION(int min, int max)
{
	Print_Title();
	for each (Call call in calls)
	{
		if (call.getDURATION() >= min && call.getDURATION() <= max)
		{
			call.Print();
		}
	}
}
void Journal::FindTO(char* to)
{
	Print_Title();
	for each (Call call in calls)
	{
		if (!strcmp(call.getTO(), to))
		{
			call.Print();
		}
	}
}
void Journal::Add(Call call)
{
	calls.push_back(call);
}
void Journal::Delete(int index)
{
	calls.erase(calls.begin() + index, calls.begin() + index + 1);
}
Call parse_string(char *str)
{
	int id;
	char from[20];
	char to[20];
	char date[20];
	char time[20];
	int duration;
	char * pch = strtok(str, " ");
	id = atoi(pch);
	pch = strtok(NULL, " ");
	strcpy(from, pch);
	pch = strtok(NULL, " ");
	strcpy(to, pch);
	pch = strtok(NULL, " ");
	strcpy(date, pch);
	pch = strtok(NULL, " ");
	strcpy(time, pch);
	pch = strtok(NULL, " ");
	duration = atoi(pch);
	return Call(id, from, to, date, time, duration);
}
void Journal::Read()
{
	calls.clear();
	ifstream fin(filename);
	char str[255];
	while (!fin.eof())
	{
		fin.getline(str, 255);
		calls.push_back(parse_string(str));
	}
	fin.close();
}

void Journal::Write()
{
	ofstream fout(filename);
	for (int i = 0; i < calls.size(); i++)
	{
		if (i == calls.size() - 1)
		{
			fout << calls[i].getID() << " " << calls[i].getFROM() << " " << calls[i].getTO() << " " << calls[i].getDATE() << " " << calls[i].getTIME() << " " << calls[i].getDURATION();
		}
		else
		{
			fout << calls[i].getID() << " " << calls[i].getFROM() << " " << calls[i].getTO() << " " << calls[i].getDATE() << " " << calls[i].getTIME() << " " << calls[i].getDURATION() << endl;
		}
	}
	fout.close();
}

Journal::~Journal()
{
}
