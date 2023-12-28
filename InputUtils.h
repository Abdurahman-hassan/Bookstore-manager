#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

// get a valid number input (integer or float)
template <typename T>
T getValidNumber(const std::string &prompt);

#include "InputUtils.tpp"

#endif // INPUT_UTILS_H
