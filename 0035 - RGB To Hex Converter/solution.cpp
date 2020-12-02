#include <iostream>
#include <vector>
#include <cmath>

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b)
    {
        std::string sol = "";

        if (r < 0) r = 0;
        else if (r > 255) r = 255;

        if (g < 0) g = 0;
        else if (g > 255) g = 255;

        if (b < 0) b = 0;
        else if (b > 255) b = 255;

        std::stringstream a;
        a << std::setfill('0') << std::setw(2) << std::hex << r;
        a << std::setfill('0') << std::setw(2) << std::hex << g;
        a << std::setfill('0') << std::setw(2) << std::hex << b;
        a >> sol;

        std::transform(sol.begin(), sol.end(), sol.begin(), ::toupper);
        return sol;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << RGBToHex::rgb(0, 0, 0) << endl;
    cout << RGBToHex::rgb(1, 2, 3) << endl;
    cout << RGBToHex::rgb(255, 255, 255) << endl;
    cout << RGBToHex::rgb(254, 253, 252) << endl;
    cout << RGBToHex::rgb(-20, 253, 125) << endl;
}