#pragma once
#include "Calendar.h"
bool dialog()
{
	std::cout << "Input name of the file that contains calendar!" << std::endl;
	char fileName[50];
	std::cin >> fileName;
	Calendar cal;
	std::stack<Activity> stackHelper;
	std::cout << "Your calendar was loaded , chose the oprion that you want!" << std::endl;

	stackHelper = cal.readFromFile(fileName);
	while (!stackHelper.empty())
	{
		Activity helper;
		helper = stackHelper.top();
		stackHelper.pop();
		cal.addActivity(helper);
	}
	cal.showAll();

	while (true)
	{

		std::cout << "Enter 'help' if you want to see your options! " << std::endl;
		std::cout << "Example for inputing  date: 2020 1 1" << std::endl;
		std::cout << "Example for inputing  hour: 13 30" << std::endl;
		char option[50];
		int optionInt = 10;
		std::cin >> option;
		if (!strcmp(option, "close")) { optionInt = 16; }
		if (!strcmp(option, "saveas")) { optionInt = 1; }
		if (!strcmp(option, "findslot")) { optionInt = 2; }
		if (!strcmp(option, "busydays")) { optionInt = 3; }
		if (!strcmp(option, "holiday")) { optionInt = 4; }
		if (!strcmp(option, "find")) { optionInt = 5; }
		if (!strcmp(option, "agenda")) { optionInt = 6; }
		if (!strcmp(option, "showall")) { optionInt = 7; }
		if (!strcmp(option, "unbook")) { optionInt = 8; }
		if (!strcmp(option, "book")) { optionInt = 9; }
		if (!strcmp(option, "help")) { optionInt = 10; }
		if (!strcmp(option, "exit")) { optionInt = 11; }
		if (!strcmp(option, "change")) { optionInt = 12; }
		if (!strcmp(option, "findslotwith")) { optionInt = 13; }
		if (!strcmp(option, "merge")) { optionInt = 14; }
		if (!strcmp(option, "save")) { optionInt = 15; }

		switch (optionInt)
		{
		case 16:
		{
			return 1;
		}
		case 15:
		{
			cal.saveAs(fileName);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}

		case 14:
		{
			std::cout << "input the name of the other file: " << std::endl;
			char fileForMerge[20];
			std::cin >> fileForMerge;
			cal.merge(fileForMerge);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 13:
		{
			int C13_hours;
			int C13_minutes;

			int C13_year;
			int C13_month;
			int C13_day;

			std::cout << "input date  " << std::endl;
			std::cin >> C13_year >> C13_month >> C13_day;
			std::cout << "input hour " << std::endl;
			std::cin >> C13_hours >> C13_minutes;
			Date C13_date(C13_year, C13_month, C13_day);
			Hour C13_hour(C13_hours, C13_minutes);

			char nameOfCalendar[20];
			std::cout << "input name of other calendar: " << std::endl;
			std::cin >> nameOfCalendar;
			cal.findSlotWith(nameOfCalendar, C13_date, C13_hour);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 12:
		{
			std::cout << "input date: " << std::endl;
			int C12_year;
			int C12_month;
			int C12_day;
			std::cin >> C12_year >> C12_month >> C12_day;
			Date DateOfChange(C12_year, C12_month, C12_day);

			std::cout << "input start Hour: " << std::endl;
			int C12_hours;
			int C12_minutes;
			std::cin >> C12_hours >> C12_minutes;
			Hour sHourOfChange(C12_hours, C12_minutes);

			std::cout << "input what do you want to be changed?:(name/note/when) " << std::endl;
			char whatToChange[20];
			std::cin >> whatToChange;
			cal.change(DateOfChange, sHourOfChange, whatToChange);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 1:
		{
			std::cout << "in which file would you like to save your calendar ?  " << std::endl;
			char C1_one[50];
			std::cin >> C1_one;

			cal.saveAs(C1_one);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 2:
		{
			int C2_hours;
			int C2_minutes;

			int C2_year;
			int C2_month;
			int C2_day;

			std::cout << "input date  " << std::endl;
			std::cin >> C2_year >> C2_month >> C2_day;
			std::cout << "input hour " << std::endl;
			std::cin >> C2_hours >> C2_minutes;
			Date C2_one(C2_year, C2_month, C2_day);
			Hour C2_two(C2_hours, C2_minutes);
			cal.findSlot(C2_one, C2_two);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 3:
		{
			int C3_year1;
			int C3_month1;
			int C3_day1;

			int C3_year2;
			int C3_month2;
			int C3_day2;
			std::cout << "input  fisrt date  " << std::endl;
			std::cin >> C3_year1 >> C3_month1 >> C3_day1;
			std::cout << "input secound date " << std::endl;
			std::cin >> C3_year2 >> C3_month2 >> C3_day2;
			Date C3_one(C3_year1, C3_month1, C3_day1);
			Date C3_two(C3_year2, C3_month2, C3_day2);
			cal.busyDays(C3_one, C3_two);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "input date that you want to become holiday !" << std::endl;
			int C4_year1;
			int C4_month1;
			int C4_day1;
			std::cin >> C4_year1 >> C4_month1 >> C4_day1;
			Date C4_one(C4_year1, C4_month1, C4_day1);
			cal.holiday(C4_one);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 5:
		{
			std::cout << "intput keyword : " << std::endl;
			char C5_keyword[50];
			std::cin >> C5_keyword;
			cal.find(C5_keyword);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 6:
		{

			std::cout << "date to agende: " << std::endl;
			int C6_year1;
			int C6_month1;
			int C6_day1;
			std::cin >> C6_year1 >> C6_month1 >> C6_day1;
			Date ag(C6_year1, C6_month1, C6_day1);
			cal.agenda(ag);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 7:
		{
			cal.showAll();
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}
		case 8:
		{
			std::cout << "input date : " << std::endl;
			int C8_year1;
			int C8_month1;
			int C8_day1;
			std::cin >> C8_year1 >> C8_month1 >> C8_day1;
			Date unDate(C8_year1, C8_month1, C8_day1);

			std::cout << "input start hour :" << std::endl;
			int C8_sHour1;
			int C8_sHour2;
			std::cin >> C8_sHour1 >> C8_sHour2;
			Hour C8_sH(C8_sHour1, C8_sHour2);


			std::cout << "input end hour :" << std::endl;
			int C8_eHour1;
			int C8_eHour2;
			std::cin >> C8_eHour1 >> C8_eHour2;
			Hour C8_eH(C8_eHour1, C8_eHour2);

			cal.unbook(unDate, C8_sH, C8_eH);
			std::cout << "The command was executed successfully!" << std::endl;
			break;
		}

		case 9:
		{
			std::cout << "input name : " << std::endl;
			char c9_name[50];
			std::cin >> c9_name;
			std::cout << "input note : " << std::endl;
			char c9_note[50];
			std::cin >> c9_note;

			std::cout << "input date : " << std::endl;
			int C9_year1;
			int C9_month1;
			int C9_day1;
			std::cin >> C9_year1 >> C9_month1 >> C9_day1;
			Date unDate(C9_year1, C9_month1, C9_day1);

			std::cout << "input start hour :" << std::endl;
			int C9_sHour1;
			int C9_sHour2;
			std::cin >> C9_sHour1 >> C9_sHour2;
			Hour C9_sH(C9_sHour1, C9_sHour2);

			std::cout << "input start hour :" << std::endl;
			int C9_eHour1;
			int C9_eHour2;
			std::cin >> C9_eHour1 >> C9_eHour2;
			Hour C9_eH(C9_eHour1, C9_eHour2);

			Activity c9_activity(c9_name, c9_note, unDate, C9_sH, C9_eH);
			if (cal.canIBook(c9_activity) == 0)
			{
				std::cout << "You cant book this activity!" << std::endl;
				break;
			}
			else
			{
				cal.addActivity(c9_activity);
				std::cout << "The command was executed successfully!" << std::endl;
				break;
			}
		}

		case 10:
		{
			std::cout << "comands are : ";
			std::cout << "saveas, ";
			std::cout << "findslot, ";
			std::cout << "busydays, ";
			std::cout << "holiday, ";
			std::cout << "find, ";
			std::cout << "agenda, ";
			std::cout << "showall, ";
			std::cout << "unbook, " << std::endl;
			std::cout << "save, ";
			std::cout << "addactivity, ";
			std::cout << "help, ";
			std::cout << "merge, ";
			std::cout << "findslotwith, ";
			std::cout << "change, ";
			std::cout << "exit, ";
			break;
		}
		case 11:
		{
			return 0;
		}
		}
	}
	

}

void realDialog()
{
	bool again;
	again = dialog();
	while (again)
	{
		again = dialog();
	}
	
}