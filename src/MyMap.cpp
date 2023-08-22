#include "MyMap.hpp"


/* int MyMap::insert(const std::string &line, int i){
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
} */

int MyMap::insert(const std::string& line, int i) {
    int curr;
    std::string token = line.substr(0, line.find("\t"));
    curr = std::stoi(token);
    if (curr != i) return -1;

    token = line.substr(line.find("\t") + 1);
    token = token.substr(0, token.find("\n"));
    token.erase(0, token.find_first_not_of(' '));
    token.erase(token.find_last_not_of(' ') + 1);

    documents[i] = token;
    return 1;
}
