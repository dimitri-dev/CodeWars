#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::vector<unsigned long long> partsSum(std::vector<unsigned long long> ls) {
    std::vector<unsigned long long> resultant;
    unsigned long long resMain = 0;

    for (auto k : ls)
        resMain += k;

    for (size_t i = 0; i < ls.size(); ++i) {
        resultant.push_back(resMain);
        resMain -= ls[i];
    }

    resultant.push_back(0);
    return resultant;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<unsigned long long> res = partsSum({ 0, 1, 3, 6, 10 });
    for (auto ck : res)
        cout << ck << " ";
}