#include <iostream>
#include "Date.h"

Year::Year(int year) :year_(1970)
{
	if (test_year(year)) {
		year_ = year;
	}
	else {
		throw std::invalid_argument("Invalid year.");
	}
}

bool Year::test_year(int year)const {
	if (year < 1970 || year > 2050) {
		return false;
	}
	return true;
}

Month::Month(int month) :month_(1)
{
	if (test_month(month)) {
		month_ = month;
	}
	else {
		throw std::invalid_argument("Invalid month.");
	}
}

bool Month::test_month(int month)const {
	if (month < 1 || month  > 12) {
		return false;
	}
	return true;
}

Day::Day(int day) :day_(1)
{
	if (test_day(day)) {
		day_ = day;
	}
	else {
		throw std::invalid_argument("Invalid day.");
	}
}

bool Day::test_day(int day)const {
	if (day < 1 || day  > 31) {
		return false;
	}
	return true;
}

Year Date::GetYear()const { return m_year; }
void Date::SetYear(int year) {m_year = year;}

Month Date::GetMonth()const { return m_month; }
void Date::SetMonth(int month) {m_month = month;}

Day Date::GetDay()const {return m_day;}
void Date::SetDay(int day) {m_day = day;}

bool Date::is_valid()const {
	if (m_month.month_ == 2) {
		if (m_year.year_ / 4) {
			if (m_day.day_ > 28) {
				return false;
			}
		}
		else if (m_day.day_ > 29) {
			return false;
		}
	}
	return true;
}
