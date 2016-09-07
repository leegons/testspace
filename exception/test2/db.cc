#include "db.h"
#include <exception>
#include <stdarg.h>
#include <string>

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

void testException() {
    throw MyException("just test Exception");
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
