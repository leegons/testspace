#include <vector>
#include <memory>
#include <cstdio>

class Impl {
public:
    virtual int find(int x) = 0;
    virtual int get(int x) = 0;
    virtual ~Impl();
};

Impl::~Impl() {
    printf("-");
}

class ObjA : public Impl {
public:
    ObjA() {
        a_ = new int[1000];
        for (int i = 0; i < 1000; ++i) {
            a_[i] = i + 3;
        }
    }

    ~ObjA() {
        printf(".");
        delete []a_;
    }

    int find(int x) {
        int i;
        for (i = 0; i < 1000; ++i) {
            if (x < a_[i])
                break;
        }
        return i;
    }

    int get(int x) {
        return a_[x];
    }
private:
    int* a_;
};

int main() {
    for (int i = 0; i < 1000; ++i) {
        Impl* a = new ObjA();
        delete a;
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
