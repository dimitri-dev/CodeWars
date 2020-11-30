#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::string cleanString(std::string s) {
    std::vector<char> ss(s.begin(), s.end());

    while (std::count(ss.begin(), ss.end(), '#') != 0) {
        std::vector<char>::iterator i = std::find(ss.begin(), ss.end(), '#');
        std::vector<char>::iterator s = ss.begin();
        ss.erase(i);
        if (i > s) ss.erase(--i);
    }

    std::string a(ss.begin(), ss.end());
    return a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << cleanString("##########") << endl;
}