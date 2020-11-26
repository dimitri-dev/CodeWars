#include <iostream>
#include <string>

using std::cin;
using std::cout;

int digPow(int n, int p)
{
    long sum = 0;
    std::string num = std::to_string(n);

    for (int i = 0; i < num.length(); ++i)
    {
        sum += pow(((int)num[i] - 48), p);
        ++p;
    }

    if (sum/(double)n == sum/n)
        return (sum / n);
    else
        return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << digPow(89, 1);
    cout << digPow(92, 1);
    cout << digPow(46288, 3);
    cout << digPow(114, 3);
}