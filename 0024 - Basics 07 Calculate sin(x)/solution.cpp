#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Yes this is a solution I submitted
// No I don't feel good about it
// Yes I could've recalculated "rad" every time too :)
double sin(double angl) {
    double rad = (angl * 3.14159265358979323846264338327950288 / 180.0);
    return (rad - (rad * rad * rad) / 6 + (rad * rad * rad * rad * rad) / 120 - (rad * rad * rad * rad * rad * rad * rad) / 5040 + (rad * rad * rad * rad * rad * rad * rad * rad * rad) / 362880 - (rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad) / 39916800 + (rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad) / 6227020800 - (rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad * rad) / 1307674368000);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << sin(60) << endl;
}