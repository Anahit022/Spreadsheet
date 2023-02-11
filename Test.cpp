#include <iostream>
#include "Cell.h"
#include "Date.h"
#include "Spreadsheet.h"
#include "Test.h"

void Test::cellValues() {
    Cell cell1;
    cell1.setColor(Color::pink);
    cell1.setValue("53.875");
    if (cell1.toInt() == 53) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    Cell cell2("Heyy", Color::green);
    Cell cell3("45.76", Color::white);
    if (cell3.toDouble() + 1 == 45.76 + 1) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    Cell cell4("2014-11-27", Color::yellow);
    if (cell4.toDate().GetDay().day_ == 27) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

void Test::date() {
    Day d(15);
    Month m(8);
    Year y(2020);
    Date date(y, m, d);
    if (date.GetYear().year_ == 2020) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    
    if (date.GetMonth().month_ == 8) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (date.GetDay().day_ == 15) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

void Test::cellfunc() {
    int n = 2;
    int m = 2;
    Cell** data = new Cell * [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new Cell[m];
    }
    Cell cell1("1", Color::pink);
    Cell cell2("2", Color::yellow);
    Cell cell3("3", Color::green);
    Spreadsheet sh(n, m,data);
    sh.setCellAt(0, 0, cell1);
    sh.setCellAt(0, 1, cell2);
    sh.setCellAt(1, 0, cell3);
    sh.setCellAt(1, 1, "4");

    if (sh.getCellAt(0, 1).getValue() == "2") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sh.getCellAt(1, 1).getValue() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    sh.swapRows(0, 1);
    if (sh.getCellAt(0, 1).getValue() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sh.getCellAt(1, 1).getValue() == "2") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    sh.swapColumns(0, 1);
    if (sh.getCellAt(0, 1).getValue() == "3") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sh.getCellAt(1, 1).getValue() == "1") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

void Test::row_and_col_func() {
    int n = 2;
    int m = 2;
    Cell** data = new Cell * [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new Cell[m]{};
    }
    Cell cell1("1", Color::blue);
    Cell cell2("2", Color::green);
    Cell cell3("3", Color::pink);
    Spreadsheet sheet(n, m,data);
    sheet.setCellAt(0, 0, cell1);
    sheet.setCellAt(0, 1, cell2);
    sheet.setCellAt(1, 0, cell3);
    sheet.setCellAt(1, 1, "4");
    sheet.getCellAt(1, 1).setColor(Color::white);
    sheet.addRow(0);
    if (sheet.getCellAt(1, 0).getValue() == "") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sheet.getCellAt(0, 0).getValue() == "1") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sheet.getCellAt(2, 1).getValue() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    sheet.addColumn(0);
    if (sheet.getCellAt(1, 1).getValue() == "") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sheet.getCellAt(2, 2).getValue() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    sheet.removeRow(1);
    if (sheet.getCellAt(1, 1).getValue() == "") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sheet.getCellAt(1, 2).getValue() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    sheet.removeColumn(1);
    if (sheet.getCellAt(1, 1).getValue() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    if (sheet.getCellAt(0, 1).getValue() == "2") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}