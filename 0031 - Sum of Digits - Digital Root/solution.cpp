#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int digital_root(int n)
{
    std::string s = std::to_string(n);
    long long sumDig = 0;
    while (s.length() != 1) {
        sumDig = std::accumulate(s.begin(), s.end(), 0);
        s = std::to_string((sumDig - s.length() * '0'));
    }
    return (std::accumulate(s.begin(), s.end(), 0) - s.length() * '0');
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << digital_root(167346) << endl;
}