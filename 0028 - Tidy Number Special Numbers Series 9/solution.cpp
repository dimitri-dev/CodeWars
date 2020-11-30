#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

bool tidyNumber(int number)
{
    std::string n = std::to_string(number);
    char lastC = '0';
    for (auto c : n) {
        if (c < lastC) return false;
        else lastC = c;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << tidyNumber(1024) << endl;
}