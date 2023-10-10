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

        // While current position where delimiter is found starting from the beginning
        // of the string is not equal to the end of the string 
        while((pos = line.find_first_of(delimiters, prev)) != std::string::npos){ 
            // if current position is greater than the previous position
            // add the substring between previous and current position to vector        
            if(pos > prev) tokens.push_back(line.substr(prev, pos-prev));
            // previous is now one more than current position
            prev = pos+1;
        }
        if(prev < line.length()) tokens.push_back(line.substr(prev, std::string::npos));    
    }

    return tokens;
}

bool isDigit(const std::string& str){
    return std::all_of(str.begin(), str.end(), [](char c){return std::isdigit(c);});
}