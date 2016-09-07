#include <cstdio>

void print(int* a, int len) {
    for (int i = 0; i < len; ++i){
        print("\t%d", a[i]);
    }
    printf("\n");
}

void ksort(int* a, int l, int r) {
    int* pl = a + l;
    int* pr = a + r;
	//TODO
}

int main() {
    int a[] = {3, 23, 45, 12, 35, 2, 6, 25, 3, 92, 221, 39, 13};
    ksort(a, 0, 12);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
