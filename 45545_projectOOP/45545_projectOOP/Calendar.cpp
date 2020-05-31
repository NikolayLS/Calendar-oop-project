#include "Calendar.h"
#include "helpFunctions.h"
#include <fstream>
std::vector<Activity> Calendar::readFromFile(char* fileName)
{
	std::vector<Activity> vectorHelper;
	char stringHelper[50];
	char stringHelper2[50];

	char yearHelper[50];int years;
	char mothHelper[50];int months;
	char dayHelper[50];int days;

	char sHourHelper1[50];int sHours;
	char sHourHelper2[50];int sMinutes;

	char eHourHelper1[50];int eHours;
	char eHourHelper2[50];int eMinutes;

	Calendar tempCalendar;
	int number;

	std::ifstream oFileName;
	if (oFileName) {
		oFileName.open(fileName, std::ios::in | std::ios::binary); //check
		oFileName.read((char*)&number, sizeof(number));
		tempCalendar.size = number;
		oFileName.read((char*)&number, sizeof(number));
		tempCalendar.capacity = number;
		for (int i = 0;i < tempCalendar.size;i++)
		{
			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&stringHelper, number);
			stringHelper[number] = '\0';

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&stringHelper2, number);
			stringHelper2[number] = '\0';

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&yearHelper, number);
			yearHelper[number] = '\0';
			years = fromCharToInt(yearHelper);

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&mothHelper, number);
			mothHelper[number] = '\0';
			months = fromCharToInt(mothHelper);

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&dayHelper, number);
			dayHelper[number] = '\0';
			days = fromCharToInt(dayHelper);

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&sHourHelper1, number);
			sHourHelper1[number] = '\0';
			sHours = fromCharToInt(sHourHelper1);

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&sHourHelper2, number);
			sHourHelper2[number] = '\0';
			sMinutes = fromCharToInt(sHourHelper2);

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&eHourHelper1, number);
			eHourHelper1[number] = '\0';
			eHours = fromCharToInt(eHourHelper1);

			oFileName.read((char*)&number, sizeof(number));
			oFileName.read((char*)&eHourHelper2, number);
			eHourHelper2[number] = '\0';
			eMinutes = fromCharToInt(eHourHelper2);
			Date date(years, months, days);
			Hour startHour(sHours, sMinutes);
			Hour endHour(eHours, eMinutes);
			Activity tempActivity(stringHelper, stringHelper2, date, startHour, endHour);
			vectorHelper.push_back(tempActivity);
		}
	}
	return vectorHelper;
}
void Calendar::saveAs(char* fileName)
{
	Calendar temp = *this;
	char* intHelper;
	int len;

	std::ofstream oFileName;
	oFileName.open(fileName, std::ios::out | std::ios::binary); //check
	if (oFileName) {

		oFileName.write((char*)&temp.size, sizeof(int));
		oFileName.write((char*)&temp.capacity, sizeof(int));

		for (int i = 0; i < size; i++)
		{
			len = strlen(temp.array[i].getName());
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)temp.array[i].getName(), len);

			len = strlen(temp.array[i].getNote());
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)temp.array[i].getNote(), len);

			len = array[i].getDate().getYear();
			intHelper = fromIntToChar(len);
			len = strlen(intHelper);
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)intHelper, len);

			len = array[i].getDate().getMonth();
			intHelper = fromIntToChar(len);
			len = strlen(intHelper);
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)intHelper, len);

			len = array[i].getDate().getDay();
			intHelper = fromIntToChar(len);
			len = strlen(intHelper);
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)intHelper, len);

			len = array[i].getStartTime().getHours();
			intHelper = fromIntToChar(len);
			len = strlen(intHelper);
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)intHelper, len);

			len = array[i].getStartTime().getMinutes();
			intHelper = fromIntToChar(len);
			len = strlen(intHelper);
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)intHelper, len);

			len = array[i].getEndTime().getHours();
			intHelper = fromIntToChar(len);
			len = strlen(intHelper);
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)intHelper, len);

			len = array[i].getEndTime().getMinutes();
			intHelper = fromIntToChar(len);
			len = strlen(intHelper);
			oFileName.write((char*)&len, sizeof(int));
			oFileName.write((char*)intHelper, len);
		}
	}
}
void Calendar::findSlot(Date othDate, Hour othHour)
{
	Activity checkHelper;
	char noteAndName_CH[4]="s";
	Date dateCheck=othDate;
	Hour startHourCheck(8,00);
	Hour endHourCheck=startHourCheck;
	endHourCheck += othHour;
	checkHelper.setName(noteAndName_CH);
	checkHelper.setNote(noteAndName_CH);
	checkHelper.setDateOfActivity(othDate);
	checkHelper.setStartTime(startHourCheck);
	checkHelper.setEndTime(endHourCheck);

	for (int i = 0;i < 1000;i++)
	{
		if (canIBook(checkHelper) == 1)
		{
			std::cout <<"date: "<< othDate <<std::endl<<"from: "<< startHourCheck << " to: " << endHourCheck << std::endl;
			return;
		}
		else
		{
			startHourCheck += Hour(1, 00);
			endHourCheck += Hour(1, 00);
			checkHelper.setStartTime(startHourCheck);
			checkHelper.setEndTime(endHourCheck);
			if (endHourCheck > Hour(17, 00))
			{
				othDate += Date(0, 0, 1);
				findSlot(othDate, othHour);
				return;
			}
		}
	}
}
void Calendar::busyDays(Date from, Date to)
{
	Date arr[100];
	int br = 0;
	Date plus(0, 0, 1);
	to += plus;
	while (!(from == to))
	{
		arr[br] = from;
		from += plus;
		br++;
	}
	//soriting
	Date sortHelper;
	for (int i = 0;i < br;i++)
	{
		for (int j = 0;j < br - 1;j++)
		{
			if (busyOnDate(arr[j]) < busyOnDate(arr[j + 1]))
			{
				sortHelper = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = sortHelper;
			}
		}
	}
	//cout-ing
	for (int i = 0;i < br;i++)
	{
		std::cout << "on date: " << arr[i]<< " your work time is: " << busyOnDate(arr[i])<<std::endl;
	}
}
Hour Calendar::busyOnDate(Date oth)
{
	Hour plus;

	for (int i = 0;i < size;i++)
	{
		if (array[i].getDate() == oth)
		{
			plus += array[i].getEndTime();
			plus -= array[i].getStartTime();
		}
	}
	return plus;
}
void Calendar::holiday(Date oth)
{
	int temp = size;
	for (int i = 0;i < temp;i++)
	{
		if (array[i].getDate() == oth)
		{
			unbook(array[i].getDate(), array[i].getStartTime(), array[i].getEndTime());
			i = 0;
			temp--;
		}
	}
	Hour sTime(00, 00);
	Hour eTime(23, 59);
	Activity holidayHelper("holiday","holiday",oth,sTime,eTime);
	addActivity(holidayHelper);
}
bool Calendar::canIBook(Activity oth)
{
	for (int i = 0;i < size;i++)
	{
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() == oth.getStartTime()) { ; return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getEndTime() == oth.getEndTime()) { return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() < oth.getStartTime() && array[i].getEndTime() > oth.getStartTime()) { return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() < oth.getEndTime() && array[i].getEndTime() > oth.getEndTime()) { return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() > oth.getStartTime() && array[i].getEndTime() < oth.getEndTime()) { return 0; }
	}
	return 1;
}
void Calendar::find(char* oth)
{
	std::cout << "Activities with names that contains the keyword are:" << std::endl;
	for (int i = 0;i < size;i++)
	{
		if (cmpFunction(array[i].getName(), oth) == 1) std::cout << array[i];
	}
	std::cout << "Activities with notes that contains the keyword are:" << std::endl;
	for (int i = 0;i < size;i++)
	{
		if (cmpFunction(array[i].getNote(), oth) == 1) std::cout << array[i];
	}
}
void Calendar::change(Date othDate, Hour othHour, char* changeStr)
{
	Activity temp;
	for (int i = 0;i < size;i++)
	{
		if (array[i].getDate() == othDate && array[i].getStartTime() == othHour)
		{
			temp = array[i];
		}
	}
	if (!strcmp(changeStr, "name"))
	{
		unbook(temp.getDate(), temp.getStartTime(), temp.getEndTime());
		char nextName[100];
		std::cout << "input next name: " << std::endl;
		std::cin >> nextName;
		temp.setName(nextName);
		addActivity(temp);
	}
	if (!strcmp(changeStr, "note"))
	{
		unbook(temp.getDate(), temp.getStartTime(), temp.getEndTime());
		char nextNote[100];
		std::cout << "input next note: " << std::endl;
		std::cin >> nextNote;
		temp.setNote(nextNote);
		addActivity(temp);
	}

	if (!strcmp(changeStr, "when"))
	{
		unbook(temp.getDate(), temp.getStartTime(), temp.getEndTime());
		int new_hours;
		int new_minutes;

		int new_year;
		int new_month;
		int new_day;
		for (int i = 0;i < 100;i++)
		{
		std::cout << "input next date: " << std::endl;
		std::cin >> new_year >> new_month >> new_day;
		temp.setDateOfActivity(Date(new_year, new_month, new_day));
		
		std::cout<<"input next start hour: " << std::endl;
		std::cin >> new_hours >> new_minutes;
		temp.setStartTime(Hour(new_hours,new_minutes));

		std::cout << "input next ent hour: " << std::endl;
		std::cin >> new_hours >> new_minutes;
		temp.setEndTime(Hour(new_hours, new_minutes));
		if (canIBook(temp) == 1) { addActivity(temp); return; }
		else { std::cout << "you can not book activiry with this date or time"; }
		}
	}
}
void Calendar::agenda(Date oth)
{
	int j = 0;
	Activity* temp;
	temp = new Activity[capacity];
	for (int i = 0;i < size;i++)
	{
		if (array[i].getDate() == oth)
		{
			temp[j] = array[i];
			j++;
		}
	}
	Activity swapHelper;
	// sortirane
	for (int i = 0;i < j;i++)
	{
		for (int k = 0;k < j - 1;k++)
		{
			if (temp[k].getEndTime() > temp[k + 1].getEndTime())
			{
				swapHelper = temp[k];
				temp[k] = temp[k + 1];
				temp[k + 1] = swapHelper;
			}
		}
	}
	for (int h = 0;h < j;h++)
	{
		std::cout << temp[h];
	}
}
void Calendar::showAll()
{
	for (int i = 0;i < size;i++)
	{
		if (strcmp(array[i].getName(), "holiday"))
		{
			std::cout << array[i];
		}
	}
}
void Calendar::expand()
{
	if (capacity == 0) capacity = 8;
	else capacity *= 2;
	Activity* tmp = new Activity[capacity];
	for (int i = 0; i < size; i++) {
		tmp[i] = array[i];
	}
	delete[] array;
	array = tmp;
}
Calendar::Calendar()
{
	size = 0;
	capacity = 8;
	array = new Activity[capacity];
}
Calendar::Calendar(const Calendar& oth)
{
	size = oth.size;
	capacity = oth.capacity;
	array = new Activity[capacity];
	for (int i = 0; i < size; i++)
	{
		array[i] = oth.array[i];
	}
}
Calendar& Calendar::operator=(const Calendar& oth)
{
	if (this != &oth)
	{
		delete[]this->array;
		size = oth.size;
		capacity = oth.capacity;
		array = new Activity[capacity];
		for (int i = 0; i < size; i++)
		{
			array[i] = oth.array[i];
		}
	}
	return *this;
}
Calendar::~Calendar()
{
	delete[]array;
}
bool Calendar::addActivity(Activity oth)
{
	for (int i = 0;i < size;i++)
	{
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() == oth.getStartTime()) { return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getEndTime() == oth.getEndTime()) { return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() < oth.getStartTime() && array[i].getEndTime() > oth.getStartTime()) { return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() < oth.getEndTime() && array[i].getEndTime() > oth.getEndTime()) { return 0; }
		if (array[i].getDate() == oth.getDate() && array[i].getStartTime() > oth.getStartTime() && array[i].getEndTime() < oth.getEndTime()) { return 0; }
	}

	array[size] = oth;
	size++;
	if (this->size == this->capacity) this->expand();
	return 1;
}
void Calendar::unbook(Date othDate, Hour othStartHour, Hour othEndHour)
{
	int j = 0;
	Activity* temp = new Activity[this->capacity];
	for (int i = 0;i < size;i++)
	{
		if (array[i].getDate() == othDate && array[i].getStartTime() == othStartHour && array[i].getEndTime() == othEndHour)
		{
			continue;
		}
		else
		{
			temp[j] = array[i];
			j++;
		}
	}
	delete[]array;
	array = new Activity[capacity];
	size--;
	for (int i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	delete[] temp;
}
void Calendar::findSlotWith(char* nameOfCalendar, Date fromDate, Hour hours)
{
	Calendar tempCalendar;
	std::vector<Activity> tempCalendarHelper;

	tempCalendarHelper = tempCalendar.readFromFile(nameOfCalendar);

	Activity helper;
	for (int i = 0;i < tempCalendarHelper.size();i++)
	{
		 helper= tempCalendarHelper[i];
		 tempCalendar.addActivity(helper);
	}
	std::cout << "In inputed calendar: " << std::endl;
	tempCalendar.findSlot(fromDate, hours);
	std::cout << "In temporary calendar: " << std::endl;
	findSlot(fromDate, hours);
}
void Calendar::merge(char* otherCalendar)
{
	Calendar tempCalendar;
	std::vector<Activity> tempCalendarHelper;

	tempCalendarHelper = tempCalendar.readFromFile(otherCalendar);
	Activity helper;
	for (int i = 0;i < tempCalendarHelper.size();i++)
	{
		helper = tempCalendarHelper[i];
		tempCalendar.addActivity(helper);
	}
	for (int i = 0;i < tempCalendar.size;i++)
	{
		if (strcmp(tempCalendar.array[i].getName(), "holiday"))
		{
			if (canIBook(tempCalendar.array[i]) == 1)
			{
				addActivity(tempCalendar.array[i]);
			}
			else
			{
				std::cout << "error 404 you cant add activity: " << tempCalendar.array[i] << std::endl;
					std::cout << "choose another date and time" << std::endl;
					int new_hours;
					int new_minutes;

				int new_year;
				int new_month;
				int new_day;
				for (int i = 0;i < 100;i++)
				{
					std::cout << "input next date: " << std::endl;
					std::cin >> new_year >> new_month >> new_day;
					tempCalendar.array[i].setDateOfActivity(Date(new_year, new_month, new_day));

					std::cout << "input next start hour: " << std::endl;
					std::cin >> new_hours >> new_minutes;
					tempCalendar.array[i].setStartTime(Hour(new_hours, new_minutes));

					std::cout << "input next ent hour: " << std::endl;
					std::cin >> new_hours >> new_minutes;
					tempCalendar.array[i].setEndTime(Hour(new_hours, new_minutes));
					if (canIBook(tempCalendar.array[i]) == 1) { addActivity(tempCalendar.array[i]);break; }
					else { std::cout << "you can not book activiry with this date or time"; }
				}
			}

		}
	}
}