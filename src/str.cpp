#include "include/str.h"

std::string trim(std::string s) {
    size_t start = s.find_first_not_of(" ");
    size_t end = s.find_last_not_of(" ");
    
    if (start == std::string::npos) {
        return "";
    }else {
        return s.substr(start, end-start+1);
    }
}
