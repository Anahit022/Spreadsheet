#include "Cell.h"
#include <iostream>
#include <string>
#include "Color.h"
#include <ctime>

Cell::Cell():m_value(" "),
m_color(Color::black){}


Cell::Cell(const std::string& value,const Color& color) :
	m_color(color),m_value(value) {}

Cell& Cell::operator=(const Cell& ob) {
	if (&ob != this) {
		setColor(ob.getColor());
		setValue(ob.getValue());
	}
	return *this;
}

void Cell::setValue(const std::string& value) {
	m_value = value;
}
std::string Cell::getValue()const {
	return m_value;
}

void Cell::setColor(const Color& color) {
	m_color = color;
}
Color Cell::getColor()const {
	return m_color;
}

void Cell::reset() {
	m_value = " ",
	m_color = Color::black;
}

int Cell::toInt()
{
	if (!validNumber()) {
		throw std::invalid_argument("The value can't be converted to int");
	}
	return std::stoi(m_value);
}

double Cell::toDouble()
{ 
	if (!validNumber()) {
		throw std::invalid_argument("The value can't be converted to double");
	}
	return std::stod(m_value); 
}

Date Cell::toDate() {
	if (!validDate()) {
		throw std::invalid_argument("Invalide date");
	}
	std::vector<std::string>* parsed = analyze(m_value);
	Year year(stoi((*parsed)[0]));
	Month month(stoi((*parsed)[1]));
	Day day(stoi((*parsed)[2]));
	Date date(year, month, day);
	return date;
}

void Cell::reset(){
	m_value = "";
	m_color = Color::white;
}

bool Cell::validNumber() {
	bool number_see = false;
	bool dot_see = false;
	for (int i = 0; i < m_value.size(); ++i) {
		if (m_value[i] >= '0' && m_value[i] <= '9') {
			number_see = true;
		}
		else if (m_value[i] == '.') {
			if (dot_see || !number_see) {
				return false;
			}
			dot_see = true;
		}
		else {
			return false;
		}
	}
	return true;
}

bool Cell::validDate() {
	std::tm t = {};
	if (strptime(m_value.c_str(), "%Y-%m-%d", &t) != nullptr) {
		return true;
	}
	return false;
}

std::vector<std::string>* Cell::analyze(const std::string& line) {
	std::vector<std::string>* result = new std::vector<std::string>();
	unsigned start = 0;
	for (unsigned end = 0; end < line.size() + 1; ++end) {
		if ((end != line.size() - 1 && line[end] == '-') || line[end] == '\0') {
			std::string current = line.substr(start, end - start);
			result->push_back(current);
			start = end + 1;
		}
		else if (end == line.size() - 1 && line[end] == '-') {
			continue;
		}
	}
	return result;
}