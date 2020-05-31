#pragma once
#include "Date.h"
#include "Hour.h"
#include <string.h>
class Activity
{
private:

	char* name;
	char* note;
	Date dateOfActivity;
	Hour startTime;
	Hour endTime;
public:
	Activity();
	~Activity();
	Activity(const char*, const char*, Date, Hour, Hour);
	Activity(const Activity&);
	Activity& operator=(const Activity&);
	const char* getName()const;
	const char* getNote()const;
	Date getDate()const;
	Hour getStartTime()const;
	Hour getEndTime()const;
	void setName(const char*);
	void setNote(const char*);
	void setDateOfActivity(const Date);
	void setStartTime(const Hour);
	void setEndTime(const Hour);
	friend  std::ostream& operator<<(std::ostream& os, const  Activity& oth);
};

