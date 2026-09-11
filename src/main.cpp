// Lionheart C++
// by RevoLC-Hiuga

#include <iostream>
#include <string>
#include "include/version.h"
#include "include/str.h"

#ifdef _WIN32
#include <windows.h>
#endif

void init_codepage();
void print_version();

int main() {
    init_codepage();
    print_version();

    while(true) {
        std::string command;

        std::cout << "> ";
        std::getline(std::cin, command);
        command = trim(command);

        std::cout << "您输入的表达式是：" << command;
        break;
    }
}

void init_codepage() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

void print_version() {
    std::cout << "狮心L4计算器 作者：日向 2026.9\n";
    std::cout << "版本：" << VersionNumber << "." << SubverNumber \
              << " build: " << BuildNumber << "\n\n";
}
