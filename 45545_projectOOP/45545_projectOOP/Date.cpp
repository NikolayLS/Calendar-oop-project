#include "Date.h"


Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;

}
void Date:: operator+= (const Date& oth)
{
	day = oth.day + day;
	month = oth.month + month;
	year = year + oth.year;
	if (day > 30)
	{
		month = month + day / 30;
		day = day % 30;

	}
	if (month > 12)
	{
		year = year + month / 12;
		month = month % 12;

	}
}
bool Date::operator <(const Date& oth)
{

	if (this->year < oth.year)
	{
		return true;
	}
	else
	{
		if (this->month < oth.month && this->year == oth.year)
		{
			return true;
		}
		else
		{
			if (this->month == oth.month && this->day < oth.day)
			{
				return true;
			}
		}

	}
	return false;
}
bool Date::operator>(const Date& oth)
{
	if (this->year > oth.year)
	{
		return true;
	}
	else
	{
		if (this->month > oth.month&& this->year == oth.year)
		{
			return true;
		}
		else
		{
			if (this->month == oth.month && this->day > oth.day)
			{
				return true;
			}
		}

	}
	return false;
}
bool Date::operator==(const Date& oth)
{
	if (this->day == oth.day && this->month == oth.month && this->year == oth.year) return true;
	else return false;
}
Date::Date(int a = 0, int b = 0, int c = 0)
{
	this->year = a;
	this->month = b;
	this->day = c;
}
std::ostream& operator<<(std::ostream& os, const Date& othDate)
{
	os << "(" << othDate.year << " ";
	if (othDate.month > 9)
	{
		os << othDate.month << " ";
	}
	else
	{
		os << "0" << othDate.month<<" ";
	}
	if (othDate.day > 9)
	{
		os << othDate.day << ")";
	}
	else
	{
		os << "0" << othDate.day << ")";
	}

	return os;
}

int Date::getYear() 
{
	return this->year;
}
int Date::getMonth() 
{
	return this->month;
}
int Date::getDay()
{
	return this->day;
}
void Date::setYear(int oth)
{
	this->year = oth;
}
void Date::setMonth(int oth)
{
	this->month = oth;
}
void Date::setDay(int oth)
{
	this->day = oth;
}