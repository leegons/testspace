#ifndef _LIB_LOG_H_
#define _LIB_LOG_H_

#include <stdio.h>

namespace kylin {
namespace lib {

#define LOG(fmt, arg...) fprintf(stderr, fmt "\n", ##arg);

} // end lib
} // end kylin

#endif  //_LIB_LOG_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
