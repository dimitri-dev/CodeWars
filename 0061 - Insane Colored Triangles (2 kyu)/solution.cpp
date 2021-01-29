#include <bits/stdc++.h>

using namespace std;

char getNext(std::string temp)
{
    if (temp == "RG" || temp == "GR" || temp == "BB") return 'B';
    if (temp == "RB" || temp == "BR" || temp == "GG") return 'G';
    if (temp == "BG" || temp == "GB" || temp == "RR") return 'R';
    return ' ';
}

char triangle(std::string s)
{
    while (s.length() > 1) {
        long long cntr = 1;
        std::string newline = "";
      
        while (s.length() % (3 * cntr) == 1) cntr *= 3;
        for (long long i = 0; i < s.length() - 1; i += cntr) {
            newline += getNext(std::string() + s[i] + s[i + cntr]);
        }
      
        s = newline;
    }
    return s[0];
}