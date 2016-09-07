#include <cstdio>
#include <vector>

class A {
public:
    A() {}
    ~A() {}
    std::vector<int>* servers() {
        return &servers_;
    }
    void add(int x) {
        servers_.push_back(x);
    }
    void print() {
        for (auto it: servers_) {
            printf("\t%d", it);
        }
        printf("\n");
    }
private:
    std::vector<int> servers_;
};

int main() {
    A a;
    a.add(1);
    a.add(2);
    a.add(1985);
    printf("get a[2]=%d\n", (*a.servers())[2]);
    a.print();

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
