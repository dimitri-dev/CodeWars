#include <list>
#include <cmath>
#include <iostream>

using namespace std;
int last_digit(list<int> array) {
    int64_t p = 1;
    auto it = array.rbegin();
    while( it != array.rend()) {
        int a = (p >= 4) ? 4 + (p % 4) : p;
        int b = (*it >= 20) ? 20 + (*it % 20) : *it;
        p = pow(b,a);
        ++it;
    }
    return p % 10;
}