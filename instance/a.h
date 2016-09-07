#ifndef _A_H_
#define _A_H_

class A {
public:
    static A* getInstance();

    void print();

protected:
    A() {}
    ~A() {}
    A(const A&) {}
    A operator=(const A&) {}
};

#endif  //_A_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
