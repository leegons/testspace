#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int param) {
    FILE * fp = fopen("testmode.log", "aw+");
    fprintf(fp, "get signal %d\n", param);
    fclose(fp);
    exit(0);
}

int main(int argc, char **argv) {
    signal(SIGINT, handler);
    signal(SIGTERM, handler);

    int idx = 0;
    while (true) {
        FILE * fp = fopen("testrunning.log", "aw+");
        fprintf(fp, "running...%d\n", idx++);
        fclose(fp);
        sleep(1);
    }
    return 0;
}

