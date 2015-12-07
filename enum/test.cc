#include <cstdio>

enum TestResultCode {
    kInclude,
    kSkip,
};

enum class TestCode {
    kOk,
    kException,
    kError,
};

TestResultCode getRet() {
    return TestResultCode::kSkip;
}

void getValue(int& result) {
    result = 123;
}

int main() {
    TestCode status;
    status = TestCode::kOk;
    printf("kException:%d\n", static_cast<int>(TestCode::kException));
    status = static_cast<TestCode>(2);
    printf("isEqual:%s", status==TestCode::kError ? "yes\n" : "no\n");

    int result = 12;
    printf("Value is :%d\n", result);
    getValue(result);
    printf("Value is now:%d\n", result);

    int resultcode = getRet();
    printf("Value return:%d\n", resultcode);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
