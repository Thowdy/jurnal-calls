#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
class Call
{
private:
	int id;
	char from[20];
	char to[20];
	char date[20];
	char time[20];
	int duration;
public:
	Call();
	Call(int id, char from[20], char to[20], char date[20], char time[20], int duration);
	void Print();
	int getID();
	char* getFROM();
	char* getTO();
	char* getDATE();
	char* getTIME();
	int getDURATION();
	~Call();
};

