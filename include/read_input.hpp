#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <fstream>

#include "MyMap.hpp"

int read_sizes(int *lineCounter, int *maxLength, std::string docFile);
int read_input(std::unique_ptr<MyMap> &mymap, std::string docFile);
