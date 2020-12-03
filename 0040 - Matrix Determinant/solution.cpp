#include <iostream>
#include <vector>
#include <cmath>

#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

long long determinant(std::vector<std::vector<long long>> m)
{
    long long matrixSize = m.size();
    if (matrixSize > 2)
    {
        int32_t det = 0;
        for (int32_t p = 0; p < matrixSize; ++p) {
            std::vector<std::vector<long long>> s_m;
            for (int32_t i = 1; i < matrixSize; ++i) {
                std::vector<long long> s_m_row;
                for (int j = 0; j < matrixSize; ++j) {
                    if (j != p) s_m_row.push_back(m[i][j]);
                }
                s_m.push_back(s_m_row);
            }
            det += m[0][p] * pow(-1, p) * determinant(s_m);
        }
        return det;
    }
    else if (matrixSize == 2)
    {
        return (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
    }
    else if (matrixSize == 1)
    {
        return m[0][0];
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << determinant({ { 1, 3 }, {2, 5 } }) << endl;
    cout << determinant({ {2, 5, 3}, {1, -2, -1}, {1, 3, 4} }) << endl;
}