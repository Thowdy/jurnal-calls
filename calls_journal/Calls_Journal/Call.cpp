#include "Call.h"


Call::Call()
{
}

Call::Call(int id, char from[20], char to[20], char date[20], char time[20], int duration)
{
	this->id = id;
	strcpy(this->from, from);
	strcpy(this->to, to);
	strcpy(this->date, date);
	strcpy(this->time, time);
	this->duration = duration;
}
void Call::Print()
{
	cout << setw(10) << left << id << setw(15) << from << setw(15) << to << setw(15) << date << setw(15) << time << setw(15) << duration << endl;
}
char* Call::getDATE()
{
	return date;
}
char* Call::getFROM()
{
	return from;
}
char* Call::getTIME()
{
	return time;
}
char* Call::getTO()
{
	return to;
}
int Call::getDURATION()
{
	return duration;
}
int Call::getID()
{
	return id;
}
Call::~Call()
{
}
