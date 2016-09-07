#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "lib/log.h"

bool g_is_stop = false;

void signal_handler(int signal) {
    LOG("signal: %d", signal);
    switch (signal) {
        case SIGTERM:
            g_is_stop = true;
            break;
        default:
            break;
    }
}

void* recv_handler(void* arg) {

}

int main() {
    signal(SIGTERM, signal_handler);

    int soc_fd = socket(AF_INET, SOCK_STREAM, 0);
    LOG("new socket fd %d", soc_fd);

    sockaddr_in soc_addr;
    memset(&soc_addr, 0, sizeof(soc_addr));
    soc_addr.sin_family = AF_INET;
    soc_addr.sin_port = htons(9938);
    soc_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ret = connect(soc_fd, (sockaddr*)&soc_addr, sizeof(soc_addr));
    LOG("connect: %d", ret);
    if (ret < 0) {
        perror("connect");
        return ret;
    }

    char s[1024];
    while (!g_is_stop && scanf("%s", s) != EOF) {
        send(soc_fd, s, strlen(s), 0);
    }
    LOG("exit");
    close(soc_fd);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
