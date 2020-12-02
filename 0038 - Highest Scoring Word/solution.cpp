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

std::string highestScoringWord(std::string str)
{
    std::istringstream iss(str);
    std::vector<std::string> splitString((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    std::string maxW = "";
    for (auto s : splitString)
        if (std::accumulate(maxW.begin(), maxW.end(), 0ll) - (maxW.length() * 96) < std::accumulate(s.begin(), s.end(), 0ll) - (s.length() * 96))
            maxW = s;

    return maxW;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << highestScoringWord("man i need a taxi up to ubud") << endl;
    cout << highestScoringWord("what time are we climbing up the volcano") << endl;
    cout << highestScoringWord("take me to semynak") << endl;
    cout << highestScoringWord("massage yes massage yes massage") << endl;
    cout << highestScoringWord("take two bintang and a dance please") << endl;
}