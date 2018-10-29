#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <fstream>
#include "Call.h"
class Journal
{
private:
	vector<Call> calls;
	char filename[20];
public:
	Journal();
	void Print();
	void Read();
	void Write();
	void Delete(int index);
	void Add(Call call);
	void Sort();
	void FindFROM(char* from);
	void FindTO(char* to);
	void FindDURATION(int min, int max);
	void FindDATE(char* min, char* max);
	~Journal();
};

