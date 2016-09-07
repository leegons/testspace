#include <string>
#include <cstdio>

int main() {
    std::string val="thix";
    switch (val) {
        case "that":
            printf("that is leegons\n");
            break;
        case "this":
            printf("this is leegons\n");
            break;
        case "thix":
            printf("what thix\n");
            break;
        default:
            printf("how?\n");
            break;
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
