#include <iostream>
#include <string>
#include <cassert>
#include <map>

using std::cin;
using std::cout;
using std::endl;

std::string duplicate_encoder(std::string word)
{
    std::string ss = "";
    for (int i = 0; i < word.length(); ++i)
    {
        if (((int)word[i] >= 97 && (int)word[i] <= 122) || ((int)word[i] >= 65 && (int)word[i] <= 90))
        {
            if (std::count(word.begin(), word.end(), toupper(word[i])) + std::count(word.begin(), word.end(), tolower(word[i])) <= 1)
                ss += "(";
            else
                ss += ")";
        }
        else if (std::count(word.begin(), word.end(), word[i]) == 1)
            ss += "(";
        else
            ss += ")";
    }

    return ss;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << duplicate_encoder("Success");
}





/* FUNCTION BASE FOR EVERY CODE

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}


*/