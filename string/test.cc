#include <string>
#include <cstdio>
#include <cstdlib>
#include <string.h>

int test_find() {
    std::string a = "kfdafdasjkfdafdsa";
    std::string b = "ksdfda";
    int c = a.find(b);
    printf ("get %d = '%s'.find('%s')\n", c, a.c_str(), b.c_str());
    return 0;
}

void test_assgin() {
    unsigned char ucs[5] = {255, 231, 42, 129, 67};
    for (int i = 0; i < 5; ++i) {
        printf("%d", ucs[i]);
    }
    puts("");

    std::string ucstr;
    ucstr.assign((char *)&ucs, 5);

    unsigned char ucbuff[5];
    memcpy(ucbuff, &ucstr[0], 5);
    unsigned char* pucstr = (unsigned char*)&ucstr[0];
    for (int i = 0; i < ucstr.size(); ++i) {
        printf("%d", pucstr[i]);
    }
    puts("");

    for (int i = 0; i < 5; ++i) {
        printf("%d", ucbuff[i]);
    }
    puts("");
}

void test_substr() {
    std::string str = "test:1236e2";
    int pos = str.find('#', 1);
    const std::string& t = str.substr(pos + 1);
    puts(t.c_str());
}

int main() {
    //test_find();
    //test_assgin();
    test_substr();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
