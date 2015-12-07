#include <cstdio>
#include <typeinfo>

class A {
public:
    A() {}
    void print() {
        printf("%s\n", typeid(*this).name());
    }
};

class B : public A {
public:
    B() {}
};

template <typename T>
void print_type_name(const char* name) {
    T x;
    printf("%s is %s\n", name, typeid(x).name());
}

int main() {
    print_type_name<A>("a");
    print_type_name<B>("b");
    print_type_name<int>("int");
    print_type_name<float>("float");
    print_type_name<bool>("bool");

    A a;
    B b;
    a.print();
    b.print();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
