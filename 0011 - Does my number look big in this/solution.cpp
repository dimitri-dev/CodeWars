#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

bool narcissistic(int value)
{
    std::vector<int> intVector;
    
    for (const auto digit : std::to_string(value))
        intVector.push_back(digit - '0');

    int base = intVector.size();
    long sum = 0;

    for (auto digit : intVector)
        sum += pow(digit, base);

    return (sum == value) ? true : false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << narcissistic(153) << endl;
    cout << narcissistic(1652) << endl;
}