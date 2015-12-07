#include <string>
#include <cstdio>
#include <cstdlib>

int main() {
    std::string str = "Content-Type";
    /*
    for (int i = 0; i < str.size(); ++i) {
        str[i] = tolower(str[i]);
    }
    */
    for (auto& it: str)
        it = tolower(it);
    puts(str.c_str());
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
