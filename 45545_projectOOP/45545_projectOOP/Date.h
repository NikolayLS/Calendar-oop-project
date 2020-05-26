#pragma once
#include<iostream>

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int, int, int);

	friend std::ostream& operator<<(std::ostream& os, const  Date& othDate);
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	bool operator ==(const Date&);
	bool operator >(const Date&);
	bool operator <(const Date&);
	void operator+= (const Date&);

};

