#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;

std::vector <int> menFromBoys(std::vector<int> values)
{
    std::vector<int> evenValues, oddValues;
    evenValues.push_back(0); oddValues.push_back(0);
    for (auto x : values)
    {
        if (x % 2 == 0 && std::count(evenValues.begin(), evenValues.end(), x) == 0)
            evenValues.push_back(x);
        if (abs(x) % 2 == 1 && std::count(oddValues.begin(), oddValues.end(), x) == 0)
            oddValues.push_back(x);
    }
        
    std::sort(evenValues.begin(), evenValues.end());
    std::sort(oddValues.begin(), oddValues.end(), std::greater<int>());

    evenValues.insert(evenValues.end(), oddValues.begin(), oddValues.end());
    evenValues.erase(std::remove(evenValues.begin(), evenValues.end(), 0), evenValues.end());

    return evenValues;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<int> res = menFromBoys({ 49,818,-282,900,928,281,-282,-1 });
    for (auto x : res)
        cout << x << endl;
}