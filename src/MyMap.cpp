#include "MyMap.hpp"


int MyMap::insert(std::string line, int i){
    std::istringstream ss(line);
    int current;
    std::string token;
    ss >> current;
    if(current != i) return -1;
    std::getline(ss, token, '\n');
    token.erase(0, token.find_first_not_of(' ')); // Trim leading spaces;
    token.erase(0, token.find_last_not_of(' ')+1); // Trim trailing spaces;
    documents[i] = token;
    return -1;
}