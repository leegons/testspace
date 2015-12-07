#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <memory>
#include <set>

class A;
typedef std::shared_ptr<A> Aptr;

class A {
public:
    A(int size) : i_(size) {
        a_ = new char[size];
        printf("construction A[%d]\n", i_);
    }
    virtual ~A() {
        if (a_ != nullptr)
            delete a_;
    }

    virtual int get() {}

protected:
    int i_;
    char * a_;
};

class B : public A {
public:
    B(int size) : A(size) {
        printf("construction B[%d]\n", i_);
    }
    ~B() {
        printf("destruction B[%d]\n", i_);
    }
    int get() {
        return i_;
    }
};

int createA(int size, Aptr * d) {
    d->reset(new B(size));
    return 0;
}

void printa(A* a) {
    printf("In func: get a:%d\n", a->get());
}

int main() {
    std::shared_ptr<A> pnull;
    printf("start is null:%s\n", pnull == nullptr ? "yes" : "no");

    {
        Aptr a = nullptr;
        createA(100100, &a);
        sleep(3);
        printf("get a:%d\n", a->get());
    }
    sleep(3);
    printf("finish 1 now\n");

    {
        std::set<Aptr> alist;
        for (int i = 100; i < 107; ++i) {
            Aptr a = nullptr;
            createA(i, &a);
            alist.insert(a);
        }
        sleep(1);
        printa((*(alist.begin())).get());
        sleep(3);
    }
    sleep(3);
    printf("finish 2 now\n");
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
