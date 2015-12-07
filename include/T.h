#include "S.h"

#ifndef _LIJIANTEST_TESTINCLUDE_T_H_
#define _LIJIANTEST_TESTINCLUDE_T_H_

namespace lijiantest {
namespace testinclude {

class S;

class T {
public:
    T();
    ~T();
    int start();
private:
    S* s_;
};

} // end testinclude
} // end lijiantest

#endif  //_LIJIANTEST_TESTINCLUDE_T_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
