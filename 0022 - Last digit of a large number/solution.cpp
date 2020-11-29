#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;

int last_digit(std::string str1, std::string str2) {
    if (str1.length() == 1 && str1[0] == '0' &&
        str2.length() == 1 && str2[0] == '0')
        return 1;

    if (str2.length() == 1 && str2[0] == '0')
        return 1;

    if (str1.length() == 1 && str1[0] == '0')
        return 0;

    int last_digit_a = (int)str1[str1.length() - 1] - '0';

    if (last_digit_a == 0) return 0;
    if (last_digit_a == 1) return 1;
    else if (last_digit_a == 5) return 5;
    else if (last_digit_a == 6) return 6;

    int lastTwo_b;

    if (str2.length() >= 2)
        lastTwo_b = ((int)str2[str2.length() - 1] - '0') + (((int)str2[str2.length() - 2] - '0') * 10);
    else
        lastTwo_b = ((int)str2[str2.length() - 1] - '0');

    return ((int)pow(last_digit_a, (lastTwo_b % 4 == 0) ? 4 : (lastTwo_b % 4)) % 10);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << last_digit("97", "1");
}