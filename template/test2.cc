#include <cstdio>

class CallBack {
public:
    virtual ~CallBack() {}
};

template <class T1>
class CallBack1 : public CallBack {
public:
    CallBack1(T1 t) : t_(t){
    }
    virtual ~CallBack1() {}
    T1 get() { return t_; }

private:
    T1 t_;
};

template<class T1>
inline CallBack1<T1>* NewCallBack(T1 t1) {
    return new CallBack1<T1>(t1);
}

int main() {
    {
        auto t = NewCallBack(12);
        printf("get from t:%d\n", t->get());
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
