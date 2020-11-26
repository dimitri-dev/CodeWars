#include <iostream>
#include <string>
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#endif


using std::cin;
using std::cout;
using std::endl;

unsigned int countBits(unsigned long long n)
{
    return __builtin_popcountll(n);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << countBits(4144922150334468) << endl;
}