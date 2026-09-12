// Lionheart C++
// by RevoLC-Hiuga

#include <iostream>
#include <string>
#include <vector>
#include "include/version.h"
#include "include/str.h"

#ifdef _WIN32
#include <windows.h>
#endif

void init_codepage();
void print_version();
void print_help();

int main() {
    init_codepage();
    print_version();

    while(true) {
        std::string command;

        std::cout << "> ";
        std::getline(std::cin, command);

        command = trim(command);
        if(command == "ver") {
            print_version();
        } else if(command == "help") {
            print_help();
        } else if(command == "quit") {
            break;
        } else if(command == "") {
            continue;
        } else {
            std::vector<std::string> str_array = split(command);

            for(std::string s : str_array) {
                std::cout << s << " ";
            }
            std::cout << "\n";
        }
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

void print_help() {
    std::cout << "【可用命令】\n";
    std::cout << "ver\t\t显示当前版本\n";
    std::cout << "help\t\t显示帮助信息\n";
    std::cout << "quit\t\t退出程序\n";
    std::cout << "如果输入的内容不是上述命令之一，将会将其视为表达式计算。\n\n";
}
