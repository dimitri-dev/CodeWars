#include <cmath>

long long rectangle_rotation(int a, int b)
{
    long long k = floor(a / 1.41421) + 1;
    long long p = floor(b / 1.41421) * 2 + 1;
    return (p % 4 == 1 == k % 2 == 1) ? (k + (k - 1)) * (p / 2) + k : (k + (k - 1)) * (p / 2) + (k - 1);
}