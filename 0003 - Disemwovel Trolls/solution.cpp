#include <iostream>
#include <string>

using std::cin;
using std::cout;

std::string funcRemove(std::string ss)
{
    std::string s = "";

    for (int i = 0; i < ss.length(); ++i)
    {
        if (ss[i] != 'a' && ss[i] != 'A' &&
            ss[i] != 'e' && ss[i] != 'E' &&
            ss[i] != 'i' && ss[i] != 'I' &&
            ss[i] != 'o' && ss[i] != 'O' &&
            ss[i] != 'u' && ss[i] != 'U')
            s += ss[i];
    }

    return s;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    getline(cin, s);

    cout << funcRemove(s);
}
