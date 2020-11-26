#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const std::string thousands[] = { "", "M", "MM", "MMM" };
const std::string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const std::string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const std::string units[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

std::string solution(int number)
{
    std::string sol = "";
    
    std::vector<int> intVector;

    for (const auto digit : std::to_string(number))
        intVector.push_back(digit - '0');

    if (intVector.size() == 4)
    {
        sol += thousands[(int)intVector[0]];

        intVector.erase(intVector.begin());
        number = 0;
        for (auto d : intVector)
            number = number * 10 + d;
    } 
    if (intVector.size() == 3)
    {
        sol += hundreds[(int)intVector[0]];
        
        intVector.erase(intVector.begin());
        number = 0;
        for (auto d : intVector)
            number = number * 10 + d;
    }
    if (intVector.size() == 2)
    {
        sol += tens[(int)intVector[0]];
        
        intVector.erase(intVector.begin());
        number = 0;
        for (auto d : intVector)
            number = number * 10 + d;
    }

    sol += units[(int)intVector[0]];

    return sol;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << solution(2008) << endl;
}