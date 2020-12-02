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

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window)
    {
        if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h)
            return -1;
        
        int c = 1;
        double curr = h * bounce;
        while (curr > window) {
            ++++c;
            curr *= bounce;
        }
        return c;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << Bouncingball::bouncingBall(3, 0.66, 1.5) << endl;
    cout << Bouncingball::bouncingBall(30, 0.66, 1.5) << endl;
}