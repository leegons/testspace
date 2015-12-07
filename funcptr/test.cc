#include <cstdio>

class A;
typedef int (A::* pFuncType)(int size);

class A {
public:
    A(int size) : i_(size) {}
    pFuncType exe;
    int x2(int size) {
        return size * i_ * 2;
    }
    int x3(int size) {
        return size * i_ * 3;
    }
    int xx(int size) {
        return 0;
    }
    void init(int d) {
        switch(d) {
        case 2:
            exe = &A::x2;
            break;
        case 3:
            exe = &A::x3;
            break;
        default:
            exe = &A::xx;
            break;
        }
    }
private:
    int i_;
};

int main() {
    A a(2);
    a.init(2);
    printf("test=%d\n", (a.*(a.exe))(5));
    a.init(3);
    printf("test=%d\n", (a.*(a.exe))(5));
    a.init(9);
    printf("test=%d\n", (a.*(a.exe))(5));
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
