#include <iostream>
#include <vector>
#include <cmath>

#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;

std::vector<std::string> solution(const std::string& a) {
    std::string s = a;

    if (s.length() % 2 == 1) s += "_";
    std::vector<std::string> res;

    for (size_t i = 0; i < s.length(); ++++i)
        res.push_back(s.substr(i, 2));

    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    auto res = solution("abcde");
    for (auto x : res)
        cout << x << endl;
}