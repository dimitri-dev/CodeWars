#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::string pig_it(std::string str)
{
    std::istringstream iss(str);
    std::vector<std::string> splitString((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    std::string result = "";

    for (auto s : splitString)
    {
        result += s.substr(1) + s[0];
        if (s.find('!') == std::string::npos && s.find('?') == std::string::npos && s.find('.') == std::string::npos && s.find(',') == std::string::npos)
            result += "ay ";
        else
            result += " ";
    }
    result.erase(result.end() - 1);

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // This was for testing blank/whitespaces - line 25 was added.
    cout << ">" << pig_it("Pig latin is cool") << "<" << endl;

    cout << pig_it("Hello world !") << endl;
    cout << pig_it("This is my string") << endl;
}