#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;

long queueTime(std::vector<int> customers, int n) {
    long sumCustom = std::accumulate(customers.begin(), customers.end(), 0);
    if (sumCustom == 0) return 0;
    else if (n == 1) return sumCustom;
    else
    {
        std::vector<int> arr(n);
        int resso = 0;

        for (int i = 0; i < n; ++i) arr[i] = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (i % n < n && n >= 2)
                arr[std::distance(arr.begin(), std::min_element(arr.begin(), arr.end()))] += customers[i];
        }

        while (*std::max_element(arr.begin(), arr.end()) != 0) {
            for (int i = 0; i < n; ++i) --arr[i];
            ++resso;
        }

        return resso;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << queueTime(std::vector<int>{}, 1) << endl;
    cout << queueTime(std::vector<int>{1, 2, 3, 4}, 1) << endl;
    cout << queueTime(std::vector<int>{2, 2, 3, 3, 4, 4}, 2) << endl;
    cout << queueTime(std::vector<int>{1, 2, 3, 4, 5}, 100) << endl;
    cout << queueTime(std::vector<int>{5, 3, 4}, 1) << endl;
    cout << queueTime(std::vector<int>{10, 2, 2, 3}, 2) << endl;
    cout << queueTime(std::vector<int>{2, 3, 10}, 2) << endl;

    /* Output should be:
     * 0
     * 10
     * 9
     * 5
     * 12
     * 10
     * 12
     */
}