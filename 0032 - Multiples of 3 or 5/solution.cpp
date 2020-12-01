#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int solution(int n) {
    return ((3 * ((n - 1) / 3) * ((n - 1) / 3 + 1) / 2) + (5 * ((n - 1) / 5) * ((n - 1) / 5 + 1) / 2) - (15 * ((n - 1) / 15) * ((n - 1) / 15 + 1) / 2));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << solution(10) << endl;
}