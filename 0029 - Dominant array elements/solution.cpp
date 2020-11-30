#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::vector<int> solve(std::vector<int> array) {
    std::vector<int> better;
    for (int i = 0; i < array.size(); ++i)
        if (array[i] >= *std::max_element(array.begin() + i, array.end()))
            if (std::count(better.begin(), better.end(), array[i]) == 0)
                better.push_back(array[i]);

    return better;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    auto x = solve({ 92,52,93,31,89,87,77,105 });
    for (auto k : x)
        cout << k << endl;
}