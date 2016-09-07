#include <cstdio>
#include "a.h"

class B {
protected:
    B() {}
    ~B() {}

public:
    static B* getInstance() {
        static B* s_ins = nullptr;
        if (s_ins == nullptr) {
            s_ins = new B();
        }
        return s_ins;
    }

    void print() {
        printf("B::print %d\n", ++inc);
    }
    static int inc;
};
int B::inc = 0;

int main() {
    // test in a mode
    A* a = A::getInstance();
    a->print();
    // test in b mode
    B* b = B::getInstance();
    b->print();
    B::getInstance()->print();
    auto b2 = B::getInstance();
    b2->print();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
