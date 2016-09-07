void test1() {
    int x = 0;
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j)
            for (int l = 0; l < 1000; ++l)
            {
                x = 1024 + 1024;
            }
}

int main() {
    test1();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
