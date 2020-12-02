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

std::string to_camel_case(std::string text) {
    for (std::string::iterator i = text.begin(); i < text.end(); ++i){
        if (*i == '_' || *i == '-') {
            text.erase(i);
            *(i) = std::toupper(*(i));
        }
    }
    return text;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << to_camel_case("the_stealth_warrior");
}