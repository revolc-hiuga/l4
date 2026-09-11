// Lionheart C++
// by RevoLC-Hiuga

#include <iostream>
#include "include/version.h"

#ifdef _WIN32
#include <windows.h>
#endif

void init_codepage();
void print_version();

int main() {
    init_codepage();
    print_version();
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
