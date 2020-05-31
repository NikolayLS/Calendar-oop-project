#include <iostream>
#include "Activity.h"
#include"Date.h"
#include"Hour.h"
#include<cstring>


std::ostream& operator<< (std::ostream& os, const Activity& oth)
{
	os << "Name:" << oth.name << "  Note:" << oth.note << "  Date:" << oth.dateOfActivity << "  from:" << oth.startTime << "  to:" << oth.endTime << std::endl;
	return os;
}
const char* Activity::getName()const
{
	return this->name;
}
const char* Activity::getNote()const
{
	return this->note;
}
Date Activity::getDate()const
{
	return dateOfActivity;
}
Hour Activity::getStartTime()const
{
	return startTime;
}
Hour Activity::getEndTime()const
{
	return endTime;
}
void Activity::setName(const char* oth)
{
	delete[] this->name;
	this->name = new char[strlen(oth) + 1];
	strcpy_s(name, strlen(oth) + 1, oth);
}
void Activity::setNote(const char* oth)
{
	delete[] this->note;
	this->note = new char[strlen(oth) + 1];
	strcpy_s(note, strlen(oth) + 1, oth);
}
void Activity::setDateOfActivity(const Date oth)
{
	this->dateOfActivity = oth;
}
void Activity::setStartTime(const Hour oth)
{
	this->startTime = oth;
}
void Activity::setEndTime(const Hour oth)
{
	this->endTime = oth;
}
Activity::Activity()
{
	this->name = NULL;
	this->note = NULL;
	this->dateOfActivity = Date(0, 0, 0);
	this->startTime = Hour(0, 0);
	this->endTime = Hour(0, 0);
}
Activity::~Activity()
{
	delete[]name;
	delete[]note;
}
Activity::Activity(const char* one, const char* two, Date three, Hour four, Hour five)
{

	this->name = new char[strlen(one) + 1];
	this->note = new char[strlen(two) + 1];

	strcpy_s(name, strlen(one) + 1, one);
	strcpy_s(note, strlen(two) + 1, two);

	this->dateOfActivity = three;
	this->startTime = four;
	this->endTime = five;

}
Activity::Activity(const Activity& other)
{
	this->name = new char[strlen(other.name) + 1];
	this->note = new char[strlen(other.note) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	strcpy_s(this->note, strlen(other.note) + 1, other.note);

	this->dateOfActivity = other.dateOfActivity;
	this->startTime = other.startTime;
	this->endTime = other.endTime;

}
Activity& Activity::operator=(const Activity& other)
{
	if (this != &other)
	{
		delete[]this->name;
		delete[]this->note;

		this->name = new char[strlen(other.name) + 1];
		this->note = new char[strlen(other.note) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		strcpy_s(this->note, strlen(other.note) + 1, other.note);

		this->dateOfActivity = other.dateOfActivity;
		this->startTime = other.startTime;
		this->endTime = other.endTime;
	}
	return *this;
}