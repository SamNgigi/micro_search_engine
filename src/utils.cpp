#include "utils.hpp"


std::vector<std::string> tokenize(const std::string input_string, std::string delimiters){

    /**
     * @brief 
     * * Below implementation is meant to mimic tokenization achieve through C's strtok that can take a multiple delimiters
     * * eg...
     * * char str[] = "apple,banana:cherry;date";
     * * char *token = strtok(str, ",:;");
     * * while(token != NULL){
     * *    std::cout << "Token:: " << token << "\n";
     * *    token = strtok(NULL, ",:;");
     * *} 
     */

    std::vector<std::string> tokens;
    std::stringstream ss(input_string);
    std::string line;

    while(std::getline(ss, line)){
        size_t prev = 0, pos;
        while((pos = line.find_first_of(delimiters, prev)) != std::string::npos){ // if we aren't at the end of the string

            if(pos > prev) tokens.push_back(line.substr(prev, pos-prev));
            prev = pos+1;
        }
        if(prev < line.length()) tokens.push_back(line.substr(prev, std::string::npos));    
    }

    return tokens;
}