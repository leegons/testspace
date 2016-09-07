#include <cstdio>

class A {
public:
    static void b(int x) {
        printf("static b(%d) in A\n", x);
    }
    void a(int x) {
        printf("obj a(%d) in A. a_=%d\n", x, a_);
    }
    A(int x):a_(x) {}
    ~A(){}
private:
    int a_;
};

void printx(int, int a, int b) {
    printf("get printx(*, %d, %d)\n", a, b);
}

void test1() {
    printx(432, 34, 32);
}

void test2() {
    printf("A::b=%x\n", &A::b);
    printf("A::a=%x\n", &A::a);
}

int main() {
    test2();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
