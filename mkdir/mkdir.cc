#include <sys/stat.h>

int main() {
    mkdir("test", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    return 0;
}
