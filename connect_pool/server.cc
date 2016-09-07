#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <pthread.h>

#include <signal.h>
#include <unistd.h>
#include <vector>
#include "lib/log.h"

typedef struct {
    int user_fd;
    std::string user_name;
} user_t;

bool g_is_stop = false;
std::vector<pthread_t> g_threads;
std::set<user_t> g_user_list;

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

void* worker(void* arg) {
    int* cli_fd = (int*)arg;
    char buf[] = "do not answer!";
    for (int i = 0 ; i < 10; ++i) {
        send(*cli_fd, buf, sizeof(buf), 0);
        usleep(1000000);
    }
    close(*cli_fd);
    delete cli_fd;
    return nullptr;
}

void async_deal(int cli_fd) {
    LOG("try deal client fd: %d", cli_fd);
    pthread_t pid;
    pthread_create(&pid, nullptr, worker, new int(cli_fd));
    g_threads.push_back(pid);
}

int main() {
    signal(SIGTERM, signal_handler);

    // socket
    int soc_fd = socket(AF_INET, SOCK_STREAM, 0);
    LOG("new socket fd %d", soc_fd);

    sockaddr_in soc_addr;
    soc_addr.sin_family = AF_INET;
    soc_addr.sin_port = htons(9938);
    soc_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind
    int ret = bind(soc_fd, (sockaddr*)&soc_addr, sizeof(soc_addr));
    LOG("bind ret: %d", ret);
    if (ret == -1) {
        perror("bind");
        return ret;
    }

    //listen
    ret = listen(soc_fd, 20);
    LOG("listen ret: %d", ret);
    if (ret == -1) {
        perror("listen");
        return ret;
    }

    // try accept
    int idx = 0;
    sockaddr_in cli_addr;
    while (!g_is_stop) {
        socklen_t len = sizeof(cli_addr);
        int cli_fd = accept(soc_fd, (sockaddr*)&cli_addr, &len);
        LOG("accept client fd: %d(%d)", cli_fd, len);
        if (cli_fd < 0) {
            perror("accept");
            return cli_fd;
        }
        async_deal(cli_fd);
    }
    close(soc_fd);
    LOG("wait for socket down");
    for (auto pid : g_threads) {
        pthread_join(pid, nullptr);
    }
    LOG("exit");
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
