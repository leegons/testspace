#include <cstdio>

class A {
public:
    A() {
        a_ = 10;
        sprintf(s_, "hello");
    }
    void print() {
        printf("A::a = %d\n", a_);
        printf("A::s = '%s'\n", s_);
    }
private:
    int a_;
    char s_[10];
};

int main() {
    (new A)->print();
    (new A())->print();

    printf("new int:%d\n", *(new int));
    printf("new int():%d\n", *(new int()));
    return 0;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
