#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::vector<std::string> towerBuilder(int nFloors)
{
    std::vector<std::string> arrSol;

    if (nFloors > 1)
    {
        int i = 0;
        int stars = nFloors * 2 - 1;
        int spaces = 0;
        while (i != nFloors)
        {
            std::string s = "";

            for (int k = 0; k < spaces; ++k)
                s += " ";

            for (int k = 0; k < stars; ++k)
                s += "*";

            for (int k = 0; k < spaces; ++k)
                s += " ";

            stars -= 2;
            if (stars % 2 == 1) spaces++;
            else spaces += 2;
            arrSol.push_back(s);
            ++i;
        }

        std::reverse(arrSol.begin(), arrSol.end());
    }
    else
        arrSol.push_back("*");

    return arrSol;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<std::string> solution = towerBuilder(3);
    for (auto i : solution)
        cout << ">" <<  i << "<" << endl;
}