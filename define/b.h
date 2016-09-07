#ifndef _MOCK_H_
#define _MOCK_H_

#define private public
#include "a.h"

class B : public A {
public:
    B() : A() {}
    ~B() {}

    void set_x(int x) {
        set_a(x);
    }
};

#endif  //_MOCK_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
