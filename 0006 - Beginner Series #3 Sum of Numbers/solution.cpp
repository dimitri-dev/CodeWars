#include <iostream>

using std::cin;
using std::cout;

int get_sum(int a, int b)
{
    int n = (a < b ? b - a : a - b) + 1;
    return n * (a + b) / 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}