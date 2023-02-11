#pragma once
class Date
{
private:
	Year m_year;
	Month m_month;
	Day m_day;
public:
	Date(const Year&, const Month&, const Day&);

	void SetYear(int year);
	Year GetYear() const;
	void SetMonth(int month);
	Month GetMonth() const;
	void SetDay(int day);
	Day GetDay() const;
	bool is_valid()const;
};
struct Year {
	Year(int year);
public:
	int year_;
private:
	bool test_year(int)const;
};

struct Month {
	Month(int month);
public:
	int month_;
private:
	bool test_month(int)const;
};

struct Day {
	Day(int day);
public:
	int day_;
private:
	bool test_day(int)const;
};