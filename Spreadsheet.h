#pragma once
#include <string>
#include "Cell.h"

class Spreadsheet
{
private:
	Cell** m_cells;
	int m_col;
	int m_row;
public:
	Spreadsheet() = delete;
	Spreadsheet(int,int, Cell**);
	~Spreadsheet();

	int getRow()const;
	int getCol()const;
	void setRow(int);
	void setCol(int);
	void setCellAt(int row, int column, const Cell&);
	void setCellAt(int row, int column,const std::string& cell);
	Cell getCellAt(int row, int column);
	void addRow(int row);
	void addColumn(int column);
	void removeRow(int row);
	void removeColumn(int column);
	void swapRows(int row1, int row2);
	void swapColumns(int column1, int column2);

private: 
	void alloc_init(Cell**);
	bool test_indexes(int, int)const;
	void dealloc();
};
