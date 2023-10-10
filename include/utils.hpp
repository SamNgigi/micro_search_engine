#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>

std::vector<std::string> tokenize(const std::string input_string, std::string delimiters);
bool isDigit(const std::string& str);


#endif //UTILS_H