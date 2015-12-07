#include <cstdio>

class A {
public:
    A() {}
    ~A() {}
    void set(int i) {
        a_ = i;
    }
    int get() const {
        return a_;
    }
private:
    int a_;
};

class B {
public:
    B() {
        a_.set(145);
    }
    ~B() {}
    const A& get() {
        return a_;
    }
private:
    A a_;
};

int main() {
    B* b = new B();
    const A* a = &(b->get());
    printf("get %d\n", a->get());

    int sa = 10;
    int& sb = sa;
    printf("a=%d, b=%d\n", sa, sb);
    sb = 5;
    printf("a=%d, b=%d\n", sa, sb);
    int sc = 30;
    &sb = sc;
    sb = 1;
    printf("a=%d, b=%d, c=%d\n", sa, sb, sc);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
