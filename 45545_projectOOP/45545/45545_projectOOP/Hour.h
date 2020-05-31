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
	int getHours() const;
	int getMinutes() const;
	void setHours(int);
	void setMinutes(int);
	bool operator==(const Hour&)const;
	bool operator <(const Hour&)const;
	bool operator >(const Hour&)const;
	Hour& operator+=(const Hour&);
	Hour& operator-=(const Hour&);
};

