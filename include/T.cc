#include "T.h"

namespace lijiantest{
namespace testinclude {

T::T() {
    s_ = new S();
}

T::~T() {
    delete s_;
}

int T::start() {
    s_->print();
    return 0;
}

}
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
