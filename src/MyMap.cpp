#include "MyMap.hpp"

int MyMap::insert(const std::string& line, int i) {
/*     int curr;
    std::string token = line.substr(0, line.find("\t")); // first token separated by "\t"
    curr = std::stoi(token);
    if (curr != i) return -1;

    token = line.substr(line.find("\t") + 1);
    token = token.substr(0, token.find("\n"));
    token.erase(0, token.find_first_not_of(' '));
    token.erase(token.find_last_not_of(' ') + 1);

    documents[i] = token;
*/
    std::istringstream iss(line);
    int current;
    std::string id;
    std::string token;

    std::getline(iss, id, ' ');
    current = std::stoi(id);
    if(current != i) return -1;

    std::getline(iss >> std::ws, token);
    documents[i] = token;

    return 1;
}
