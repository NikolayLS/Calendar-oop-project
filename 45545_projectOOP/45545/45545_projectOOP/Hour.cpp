#include "Hour.h"


Hour::Hour()
{
	this->hours = 0;
	this->minutes = 0;
}
Hour& Hour:: operator-= (const Hour& oth)
{
	this->hours = this->hours - oth.hours;
	this->minutes = this->minutes - oth.minutes;
	while (minutes < 0)
	{
		minutes = minutes + 60;
		hours--;
	}
	return *this;
}
Hour& Hour:: operator+= (const Hour& oth)
{
	hours = hours + oth.hours;
	minutes = minutes + oth.minutes;
	if (minutes > 59)
	{
		hours = hours + minutes / 59;
		minutes = minutes % 60;
	}
	return *this;
}
bool Hour::operator==(const Hour& oth) const
{
	if (this->hours == oth.hours && this->minutes == oth.minutes)return true;
	else return false;
}
bool Hour::operator >(const Hour& oth) const
{
	if (this->hours > oth.hours)
	{
		return true;
	}
	if (this->hours == oth.hours && this->minutes > oth.minutes)
	{
		return true;
	}
	return false;
}
bool Hour::operator <(const Hour& oth) const
{
	if (this->hours < oth.hours)
	{
		return true;
	}
	if (this->hours == oth.hours && this->minutes < oth.minutes)
	{
		return true;
	}
	return false;
}
Hour::Hour(int a = 0, int b = 0)
{
	this->hours = a;
	this->minutes = b;
}
std::ostream& operator<<(std::ostream& os, const  Hour& othHour)
{
	os << "(";
	if (othHour.hours > 9)
	{
		os << othHour.hours << " ";
	}
	else
	{
		os <<"0"<< othHour.hours << " ";
	}
	if (othHour.minutes > 9)
	{
		os << othHour.minutes << ")";
	}
	else
	{
		os << "0" << othHour.minutes << ")";
	}

	return os;
}
void Hour::setHours(int oth)
{
	this->hours = oth;
}
void Hour::setMinutes(int oth)
{
	this->minutes = oth;
}
int Hour::getHours() const
{
	return this->hours;
}
int Hour::getMinutes() const
{
	return this->minutes;
}
