#include <ctype.h>
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

enum class SplitState {
    Start,
    Number,
    Other
};

std::vector<std::string> split(std::string s) {
    SplitState state = SplitState::Start;
    std::string num_str = "";
    std::vector<std::string> result;

    for(char c : s) {
        if(state == SplitState::Start) {
            if(isdigit(c) || c == '.') {
                num_str += c;
                state = SplitState::Number;
            } else {
                if(c != ' ') {
                    std::string single_char;
                    single_char = c;
                    result.push_back(single_char);
                }
                state = SplitState::Other;
            }
        } else if(state == SplitState::Number) {
            if(isdigit(c) || c == '.') {
                num_str += c;
            } else {
                result.push_back(num_str);
                num_str = "";

                if(c != ' ') {
                    std::string single_char;
                    single_char = c;
                    result.push_back(single_char);
                }
                state = SplitState::Other;
            }
        } else {        // SPLIT_STR_STARE_OTHER
            if(isdigit(c) || c == '.') {
                num_str += c;
                state = SplitState::Number;
            } else {
                if(c != ' ') {
                    std::string single_char;
                    single_char = c;
                    result.push_back(single_char);
                }
            }
        }
    }

    if(num_str != "") {
        result.push_back(num_str);
    }
    return result;
}
