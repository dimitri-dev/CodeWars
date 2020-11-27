#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;
    return num <= 1 ? false : true;
}

unsigned long long numPrimorial(unsigned short int number)
{
    int primeCounter = 0;
    int i = 2;
    unsigned long long resultant = 1;
    while (primeCounter != number)
    {
        if (!isPrime(i))
            ++i;
        else {
            resultant *= i;
            ++i;
            ++primeCounter;
        }
    }
    return resultant;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << numPrimorial(9) << endl;
}