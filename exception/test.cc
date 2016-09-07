#include <exception>
#include <cstdio>
#include <string>
#include <memory>
#include <stdarg.h>

class MyException : public std::exception {
public:
    MyException() : std::exception(), msg_("") {}
    MyException(const std::string& fmt, ...) {
        char buff[2048];
        va_list va;
        va_start(va, fmt);
        int ret = vsnprintf(buff, 2048, fmt.c_str(), va);
        va_end(va);
        if (ret < 0) {
            msg_ = "the error msg too long to store :( ";
        } else {
            msg_.assign((char *)buff, ret);
        }
    }
    ~MyException() {}
    const char* what() const throw(){
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class A {
public:
    A() {}
    ~A() {}
    void query(int x) throw (MyException);
};

void A::query(int x) throw (MyException) {
    if (x > 10) {
        throw MyException("x(%d) must less than 10", x);
    } else {
        printf ("get a number:%d\n", x);
    }
}

std::shared_ptr<A> createA() {
    throw MyException("some exception");
}

int main() {
    A a;
    try {
        a.query(3);
        a.query(13);
    } catch (std::exception& e) {
        printf("catch:%s\n", e.what());
    }

    std::shared_ptr<A> ptr;
    try {
        ptr = createA();
    } catch (std::exception& e) {
        printf("catch:%s\n", e.what());
    }
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
