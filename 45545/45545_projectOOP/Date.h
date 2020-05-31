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

	int getYear()const;
	int getMonth()const;
	int getDay()const;
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	bool operator ==(const Date&)const;
	bool operator >(const Date&)const;
	bool operator <(const Date&)const;
	Date& operator+= (const Date&);
	friend std::ostream& operator<<(std::ostream& os, const  Date& othDate);

};

