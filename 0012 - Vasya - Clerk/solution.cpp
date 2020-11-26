#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;

std::string tickets(std::vector<int> peopleInLine)
{
    std::map<int, long> moneyMap = { {25 , 0}, {50, 0}, {100, 0} };

    for (auto i : peopleInLine)
    {
        switch (i)
        {
        case 50:
            ++moneyMap[i];
            if (moneyMap[25] < 1) return "NO";
            else --moneyMap[25];
            break;
        case 100:
            ++moneyMap[100];
            if (moneyMap[25] >= 1 && moneyMap[50] >= 1)
            {
                --moneyMap[25];
                --moneyMap[50];
            }
            else if (moneyMap[25] >= 3 && moneyMap[50] == 0)
                ------moneyMap[25];
            else
                return "NO";
            break;
        default:
            ++moneyMap[i];
            break;
        }
    }
    return "YES";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << tickets({ 25, 25, 50 }) << endl;
    cout << tickets({ 25, 100 }) << endl;
    cout << tickets({ 25, 25, 50, 50, 100 }) << endl;
}