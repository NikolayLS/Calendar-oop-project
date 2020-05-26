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
	const char* getName();
	const char* getNote();
	Date getDate();
	Hour getStartTime();
	Hour getEndTime();
	void setName(char*);
	void setNote(char*);
	void setDateOfActivity(Date);
	void setStartTime(Hour);
	void setEndTime(Hour);
	friend  std::ostream& operator<<(std::ostream& os, const  Activity& oth);
};

