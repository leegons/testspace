#include <cstdio>

class A {
public:
    A(int i): i_(i) {}
    ~A(){}
    void Print(bool bigger=false);
private:
    int i_;
};

void A::Print(bool bigger) {
    if (bigger)
        printf("%d\n", i_ + 1);
    else
        printf("%d\n", i_);
}

int main() {
    A a(3);
    a.Print();
    a.Print(false);
    a.Print(true);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
