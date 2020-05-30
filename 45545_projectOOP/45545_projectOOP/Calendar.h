#pragma once
#include<iostream>
#include<vector>
#include"Activity.h"
class Calendar
{
private:
	int size;
	int capacity;
	Activity* array;
	void expand();

public:
	Calendar();
	~Calendar();
	void merge(char*);
	void findSlotWith(char*, Date, Hour);
	Calendar& operator=(const Calendar&);
	Calendar(const Calendar&);
	bool canIBook(Activity toAdd);
	bool addActivity(Activity toAdd);
	void showAll();
	void unbook(Date, Hour, Hour);
	void agenda(Date);
	void change(Date, Hour, char*);
	void find(char*);
	void holiday(Date);
	Hour busyOnDate(Date);
	void busyDays(Date, Date);
	void findSlot(Date, Hour);
	std::vector<Activity> readFromFile(char* fileName);
	void saveAs(char* fileName);
};

