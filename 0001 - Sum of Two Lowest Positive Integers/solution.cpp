#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;

int stupidFunction(std::vector<int> vEnt)
{
    std::sort(vEnt.begin(), vEnt.end());
    return (vEnt.at(0) + vEnt.at(1));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;

    std::vector<int> vEnt;

    for (int i = 0; i < n; ++i)
    {
        int nt;
        cin >> nt;
        if (nt >= 0)
            vEnt.push_back(nt);
    }

    cout << stupidFunction(vEnt);
}