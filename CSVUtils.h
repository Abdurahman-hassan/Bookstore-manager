#ifndef CSV_UTILS_H
#define CSV_UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>


const int MAX_ROWS = 20;
const int USER_MAX_COLS = 3; // username, password, job_title
const int BOOK_MAX_COLS = 9; // name, category, price, author

template<size_t MAX_COLS>
void writeCSV(const std::string&filename, const std::string data[][MAX_COLS], int rowCount, int colCount);

template<size_t MAX_COLS>
void readCSV(const std::string&filename, std::string data[][MAX_COLS], int&rowCount, int&colCount);

#include "CSVUtils.tpp"

#endif // CSV_UTILS_H
