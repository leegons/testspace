#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include <unistd.h>

class Pid {
public:
    std::shared_ptr<Pid>  static Read(int pid): {
        char buf[10240];
        assert(sprintf(buf, "/proc/%d/status", pid) > 0);
        auto fp = fopen(buf, "r");
        if (!fp) {
            return nullptr;
        }
        auto* info = new std::map<std::string, std::string>();
        while (fgets(buf, 10240, fp) != nullptr) {
            std::string key;
            std::string value;
            // split buf to k->v
            // buf: "key:   value"
            info->insert(std::map<std::string, std::string>::value_type(key, value));
        }
        fclose(fp);
    }

private:
    Pid(std::map<std::string, std::string>* info):info_(info) {
        assert(info_ != nullptr);
    }
    ~Pid() {
        delete info_;
    }

    std::map<std::string, std::string>* info_;
};

bool checkpid(int pid) {
}

int main() {
    auto pid = fork();
    if (pid < 0) {
        printf("failed");
    } else if (pid == 0) {
        for (int i = 0; i < 10; ++i) {
            //printf("child:%d\n", pid);
            sleep(1);
        }
    } else {
        while (checkpid(pid)) {
            printf("child:%d exists\n", pid);
            sleep(1);
        }
        printf("child:%d dead\n", pid);
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
