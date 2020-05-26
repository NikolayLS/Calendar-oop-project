#include "Hour.h"


Hour::Hour()
{
	this->hours = 0;
	this->minutes = 0;
}
void Hour:: operator-= (const Hour& oth)
{
	this->hours = this->hours - oth.hours;
	this->minutes = this->minutes - oth.minutes;
	while (minutes < 0)
	{
		minutes = minutes + 60;
		hours--;
	}
}
void Hour:: operator+= (const Hour& oth)
{
	hours = hours + oth.hours;
	minutes = minutes + oth.minutes;
	if (minutes > 59)
	{
		hours = hours + minutes / 59;
		minutes = minutes % 60;
	}
}
bool Hour::operator==(const Hour& oth)
{
	if (this->hours == oth.hours && this->minutes == oth.minutes)return true;
	else return false;
}
bool Hour::operator >(const Hour& oth)
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
bool Hour::operator <(const Hour& oth)
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
	os << "(" << othHour.hours << ":" << othHour.minutes << ")";
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
int Hour::getHours()
{
	return this->hours;
}
int Hour::getMinutes()
{
	return this->minutes;
}
