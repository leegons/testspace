#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

template <typename T>
T min(T& a, T& b) {
    return a < b ? a : b;
}

int main () {
    // test map and vector
    std::map<std::string, std::vector<int> > map;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    map["one"] = v;

    for(const auto& kvp : map) {
        std::cout << kvp.first << std::endl;
        for(auto v : kvp.second)
            std::cout << v << std::endl;
    }
    // E use & in for
    int arr[] = {1,2,3,4,5};
    for(int& e : arr)
        e = e*e;
    for(int& e : arr)
        std::cout << e << std::endl;

    // ###
    int a = 13, b = 5;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "min is " << min(a, b) << std::endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
