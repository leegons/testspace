#include <cstdio>

struct strct {
    int x;
    void init() {
        x = 0;
    }
};

class clss {
public:
    clss() {x = 0;}
    ~clss() {}
    void func() {printf("clss.func=%d\n", x);}
private:
    int x;
};

__attribute__((constructor))
void my_init() {
    printf("my init\n");
}

void my_function() {
    printf("my function\n");
}

int main() {
    printf("my main\n");
    my_function();

    strct u;
    u.init();

    clss a;
    a.func();

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
