#include <iostream>

using std::cin;
using std::cout;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;
    return num <= 1 ? false : true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}
