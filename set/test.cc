#include <set>
#include <string>
#include <cstdio>

int main() {
    std::set<int> myset;
    for (int i = 0; i < 10; ++i) {
        myset.insert(i);
    }
    for (auto it : myset) {
        printf ("set:%d\n", it);
    }
    myset.erase(8);
    for (auto it : myset) {
        printf ("in myset:%d\n", it);
    }

    std::set<std::string> strset;
    strset.insert("a");
    strset.insert("abcd");
    strset.insert("b");
    strset.insert("a");
    for (auto it : strset) {
        printf("in strset:%s\n", it.c_str());
    }
    strset.erase("b");
    printf("after remove b\n");
    for (auto it : strset) {
        printf("in strset:%s\n", it.c_str());
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
