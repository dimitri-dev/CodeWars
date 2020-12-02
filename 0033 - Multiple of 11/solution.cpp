#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

bool eleven(std::string input) {
    // Alternating sum
    bool c = false;
    long long sum = 0;

    // Iterate every character, if !alternate is true + sign, if !alternate is false - sign <3
    for (auto x : input) {
        if (!c) { sum += (x - '0'); c = !c; }
        else { sum -= (x - '0'); c = !c; }
    }

    // If alternating sum is divisible by 11, then number itself is too
    return (sum % 11 == 0) ? true : false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // Output should be
    // T F T T F T
    cout << eleven("11") << endl;
    cout << eleven("3800") << endl;
    cout << eleven("323455693") << endl;
    cout << eleven("30800") << endl;
    cout << eleven("654986546516") << endl;
    cout << eleven("22") << endl;
}