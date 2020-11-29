#include <iostream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::string spinWords(std::string str) {
    std::istringstream iss(str);
    std::vector<std::string> splitString((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    std::string result = "";

    for (auto s : splitString)
    {
        if (s.length() >= 5)
            std::reverse(s.begin(), s.end());

        result += s + " ";
    }
    result.erase(result.end() - 1);
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << spinWords("This is a stupid example") << endl;
}