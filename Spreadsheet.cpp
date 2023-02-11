#include "SpreadSheet.h"
#include <iostream>

Spreadsheet::Spreadsheet(int row, int col, Cell** cell) {
	setRow(row);
	setCol(col);
	alloc_init(cell);
}

Spreadsheet::~Spreadsheet() {
	dealloc();
}

int Spreadsheet::getRow()const {
	return m_row;
}

int Spreadsheet::getRow()const {
	return m_row;
}

void Spreadsheet::setRow(int row) {
	if (row < 0) {
		throw std::invalid_argument("Invalit row value");
	}
	m_row = row;
}

void Spreadsheet::setCol(int col) {
	if (col < 0) {
		throw std::invalid_argument("Invalit col value");
	}
	m_col = col;
}

void Spreadsheet::setCellAt(int row, int col, const Cell& cell) {
	if (!test_indexes(row, col)) {
		throw std::invalid_argument("Index is out of sheets ");
	}
	m_cells[row][col] = cell;
}

void Spreadsheet::setCellAt(int row, int col, const std::string& value) {
	if (!test_indexes(row, col)) {
		throw std::invalid_argument("Index is out of sheets ");
	}
	m_cells[row][col].setValue(value);
}

Cell Spreadsheet::getCellAt(int row, int col) {
	if (test_indexes(row, col)) {
		throw std::invalid_argument("Index is out of sheets ");
	}
	return m_cells[row][col];
}

void Spreadsheet::addRow(int row) {
	if (row < -1 || row > m_row) {
		throw std::invalid_argument("Index is out of sheets ");
	}
	Cell** cells = new Cell * [m_row + 1]{};
	for (int i = 0; i < m_row + 1; ++i) {
		cells[i] = new Cell[m_col]{};
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
	cells[row + 1] = new Cell[m_col]{};
	for (int i = row + 2; i <= m_row; ++i) {
		for (int j= 0; j < m_col; ++j) {
			cells[i][j] = m_cells[i - 1][j];
		}
	}
	dealloc();
	m_cells = cells;
	++m_row;
}

void Spreadsheet::removeRow(int row) {
	if (row < 0 || row >= m_row) {
		throw std::invalid_argument("Index is out of sheets.");
	}
	Cell** cells = new Cell * [m_row - 1]{};
	for (int i = 0; i < m_row - 1; ++i) {
		cells[i] = new Cell[m_col]{};
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
	for (int i = row + 1; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i - 1][j] = m_cells[i][j];
		}
	}
	dealloc();
	m_cells = cells;
	--m_row;
}

void Spreadsheet::addColumn(int col) {
	if (col < -1 || col >= m_col) {
		throw std::invalid_argument("Index is out of sheets ");
	}
	Cell** cells = new Cell * [m_row ]{};
	for (int i = 0; i < m_row; ++i) {
		cells[i] = new Cell[m_col + 1]{};
	}
	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j <= col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
	for (int i = 0; i <= m_row; ++i) {
		for (int j = col + 2; j < m_col; ++j) {
			cells[i][j] = m_cells[i][j - 1];
		}
	}
	dealloc();
	m_cells = cells;
	++m_col;
}

void Spreadsheet::removeColumn(int col) {
	if (col < 0 || col >= m_col) {
		throw std::invalid_argument("Index is out of sheets.");
	}
	Cell** cells = new Cell * [m_row]{};
	for (int i = 0; i < m_row; ++i) {
		cells[i] = new Cell[m_col - 1]{};
	}
	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
	for (int i = 0; i < m_row; ++i) {
		for (int j = col + 1; j < m_col; ++j) {
			cells[i][j - 1] = m_cells[i][j];
		}
	}
	dealloc();
	m_cells = cells;
	--m_col;
}

void Spreadsheet::swapRows(int r1, int r2) {
	if (!test_indexes(r1, r2)) {
		throw std::invalid_argument("Index is out of sheets.");
	}
	if (r1 == r2) {
		return;
	} 
	Cell* tmp = m_cells[r1];
	m_cells[r1] = m_cells[r2];
	m_cells[r2] = tmp;
}

void Spreadsheet::swapColumns(int c1, int c2) {
	if (!test_indexes(c1, c2)) {
		throw std::invalid_argument("Index is out of sheets.");
	}
	if (c1 == c2) {
		return;
	}
	for (int i = 0; i < m_row; ++i) {
		Cell tmp = m_cells[i][c1];
		m_cells[i][c1] = m_cells[i][c2];
		m_cells[i][c2] = tmp;
	}
}

bool Spreadsheet::test_indexes(int i, int j)const {
	if (i < 0 || i >= m_row || j < 0 || j >= m_col) {
		return false;
	}
	return true;
}

void Spreadsheet::alloc_init(Cell** cell) {
	if (cell) {
		m_cells = new Cell * [m_row] {};
		for (int i = 0; i < m_row; ++i) {
			m_cells[i] = new Cell[m_col]{};
		}
		for (int i = 0; i < m_row; ++i) {
			for (int j = 0; i < m_col; ++j) {
				m_cells[i][j] = cell[i][j];
			}
		}
	}
}

void Spreadsheet::dealloc() {
	if (m_cells) {
		for (int i = 0; i < m_row; ++i) {
			delete[] m_cells[i];
		}
		delete[] m_cells;
	}
}