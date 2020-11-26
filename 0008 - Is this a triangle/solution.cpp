#include <iostream>

using std::cin;
using std::cout;

bool isTriangle(long a, long b, long c)
{
    if (a < 1 || b < 1 || c < 1)
        return false;
    else if (a + b > c && a + c > b && b + c > a)
        return true;
    else
        return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}