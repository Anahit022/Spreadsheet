#pragma once
#include "Color.h"
#include <string>
#include "Date.h"
#include <vector>

class Cell
{
private:
	std::string m_value;
	Color m_color;
public:
	Cell();
	Cell(const std::string&, const Color&);

	void setValue(const std::string& value);
	std::string getValue() const;
	void setColor(const Color& color);
	Color getColor() const;
	int toInt();
	double toDouble();
	Date toDate();
	void reset();

	Cell& operator=(const Cell&);

private:
	bool validNumber();
	bool validDate();
	std::vector<std::string>* analyze(const std::string&);

};

