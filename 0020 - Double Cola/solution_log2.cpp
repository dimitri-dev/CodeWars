#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::string who_is_next2(std::vector<std::string> v, long long n) {
    long long l = pow(2, floor(log2(ceil((double)n-- / v.size()))));
    return v[(n - (l - 1) * v.size()) / l];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<std::string> names1 = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
    std::vector<std::string> names2 = { "Sheldon", "Leonard"};
    std::vector<std::string> names3 = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard", "Daisuke", "Motoko"};

    cout << who_is_next(names1, 7) << endl;
    /// Leonard

    cout << who_is_next(names2, 7) << endl;
    /// Sheldon

    cout << who_is_next(names3, 9) << endl;
    /// Sheldon

    cout << who_is_next(names1, 1) << endl;
    /// Sheldon

    cout << who_is_next(names1, 52) << endl;
    /// Penny

    cout << who_is_next(names1, 1) << endl;
    /// Sheldon

    cout << who_is_next(names1, 10010) << endl;
    /// Howard

    cout << who_is_next(names1, 7230702951) << endl;
    // Leonard
}