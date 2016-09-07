#include <cstdio>
#include <memory>

class A {
public:
    A(int x): a_(x) { printf("construct(%d)\n", a_); }
    ~A() { printf("destruct(%d)\n", a_); }
    void set_a(int x) { a_ = x; }
    void print() const {
        printf("I has %d\n", a_);
    }
private:
    int a_;
};

int main() {
    A* a = new A(100);
    {
        std::unique_ptr<A> up1(a);
        std::unique_ptr<A> up2(a);
        up2->print();
        up1->set_a(23);
        up1->print();
    }
    a->print();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
