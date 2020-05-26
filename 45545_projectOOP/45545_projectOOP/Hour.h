#pragma once
#include <iostream>
class Hour
{
private:
	int hours;
	int minutes;
public:
	Hour();
	Hour(int, int);
	friend std::ostream& operator<<(std::ostream& os, const Hour& othHour);
	int getHours();
	int getMinutes();
	void setHours(int);
	void setMinutes(int);
	bool operator==(const Hour&);
	bool operator <(const Hour&);
	bool operator >(const Hour&);
	void operator+=(const Hour&);
	void operator-=(const Hour&);
};

