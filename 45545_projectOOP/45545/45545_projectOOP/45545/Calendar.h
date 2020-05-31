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
	void merge(const char*);
	void findSlotWith(const char*, Date, Hour);
	Calendar& operator=(const Calendar&);
	Calendar(const Calendar&);
	bool canIBook(Activity toAdd)const;
	bool addActivity(Activity toAdd);
	void showAll()const;
	void unbook(Date, Hour, Hour);
	void agenda(Date)const;
	void change(Date, Hour, const char*);
	void find(const char*)const;
	void holiday(Date);
	Hour busyOnDate(Date)const;
	void busyDays(Date, Date)const;
	void findSlot(Date, Hour)const;
	std::vector<Activity> readFromFile(const char* fileName);
	void saveAs(const char* fileName)const;
};

