#include <cstdio>
#include <string>
#include <iostream>

int main() {
    std::string str = "hello";
    str[3] = '\0';
    puts(str.c_str());
    std::cout << str << std::endl;
    std::cout << str.size() << std::endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
