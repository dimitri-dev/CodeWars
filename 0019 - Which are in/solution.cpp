#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

static std::vector<std::string> inArray(std::vector<std::string> array1, std::vector<std::string> array2) {
    std::vector<std::string> result;

    for (auto x : array2)
        for (auto y : array1)
            if (x.find(y) != std::string::npos) {
                if (std::count(result.begin(), result.end(), y) == 0)
                    result.push_back(y);
            }
                

    std::sort(result.begin(), result.end());
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<std::string> arr1 = { "arp", "live", "strong" };
    std::vector<std::string> arr2 = { "lively", "alive", "harp", "sharp", "armstrong" };

    std::vector<std::string> sol = inArray(arr1, arr2);
    for (auto x : sol)
        cout << x << endl;
}