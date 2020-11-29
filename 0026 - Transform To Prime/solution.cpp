#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;
    return num <= 1 ? false : true;
}

int minimumNumber(std::vector<int> numbers)
{
    long long elemSum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::pair<int, bool> goUp = std::make_pair(1, false);

    if (isPrime(elemSum))
        return 0;

    while (goUp.second != true)
    {
        if (isPrime(elemSum + goUp.first)) {
            goUp.second = true;
            break;
        }

        ++goUp.first;
    }

    return goUp.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << minimumNumber({ 2,12,8,4,6 }) << endl;
    cout << minimumNumber({ 50,39,49,6,17,28 }) << endl;
}