#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int file_desc;
    int save_errno;

    const char * lckfile = "./test.lock";
    /*
    if (file_desc == -1) {
        file_desc = open(lckfile, O_RDWR | O_CREAT | O_EXCL, 0444);
        save_errno = errno;
        printf("Open failed with error %d\n", save_errno);
    }
    */
    //create file lock
    int fd = open(lckfile, O_CREAT | O_WRONLY, 0444);
    if (lockf(fd, F_TLOCK, 0)) {
        fprintf(stderr, "cannot start multi processes in the same directory.\n");
        return -1;
    } else {
        printf("Open succeeded\n");
    }
    while (true) {
        printf(".");
        sleep(3);
    }
    exit(EXIT_SUCCESS);
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
