#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

std::vector<long long> wheatFromChaff(std::vector<long long> values)
{
    // All values are positive
    if (*std::min_element(values.begin(), values.end()) > 0)
        return values;

    // All values are negative
    if (*std::max_element(values.begin(), values.end()) < 0)
        return values;

    std::vector<long long>::iterator one = values.begin(), two = values.end() - 1;
    while (one != two)
    {
        if (*one > 0) {
            if (*two < 0){ long long tmp = *two; *two = *one; *one = tmp; }
            else two--;
        } else one++;
    }
    return values;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    auto x = wheatFromChaff({ -16,44,-7,-31,9,-43,-44,-18,50,39,-46,-24,3,-34,-27 });
    for (auto k : x)
        cout << k << endl;
}