#include "doctest.h"
#include "..\include\str.h"
#include <vector>

TEST_CASE("check_split_string") {
    std::vector<std::string> cases = {
        "0",
        "123",
        "123+123",
        "123+",
        "   123+   ",
        " 12 34 ",
        "+123+123+",
        "+-12 -  + 12",
        "123.456",
        "-123.456.789"
    };

    std::vector<std::vector<std::string>> accept = {
        {"0"},
        {"123"},
        {"123", "+", "123"},
        {"123", "+"},
        {"123", "+"},
        {"12", "34"},
        {"+", "123", "+", "123", "+"},
        {"+", "-", "12", "-", "+", "12"},
        {"123.456"},
        {"-", "123.456.789"}
    };

    int cases_len = cases.size();
    for(int i = 0; i < cases_len; i++) {
        CHECK(split(cases[i]) == accept[i]);
    }
}
