#include <iostream>
#include <vector>
#include <cmath>

#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;

std::string decodeMorse(std::string morseCode) {
    std::map<char, std::string> encodeMorseMap = 
       {{ 'A', ".-"},
        { 'B', "-..."},
        { 'C', "-.-."},
        { 'D', "-.."},
        { 'E', "."},
        { 'F', "..-."},
        { 'G', "--."},
        { 'H', "...."},
        { 'I', ".."},
        { 'J', ".---"},
        { 'K', "-.-"},
        { 'L', ".-.."},
        { 'M', "--"},
        { 'N', "-."},
        { 'O', "---"},
        { 'P', ".--."},
        { 'R', ".-."},
        { 'S', "..."},
        { 'T', "-"},
        { 'U', "..-"},
        { 'V', "...-"},
        { 'Y', "-.--"},
        { 'X', "-..-"},
        { 'Q', "--.-"},
        { 'W', ".--"},
        { 'Z', "--.." },
        {' ', "   "}};

    std::cout << ">" << morseCode << "<" << std::endl;
    std::map<std::string, char> decodeMorseMap =
       { { ".-", 'A'},
      { "-...", 'B'},
      { "-.-.", 'C'},
      { "-..", 'D'},
      { ".", 'E'},
      { "..-.", 'F'},
      { "--.", 'G'},
      { "....", 'H'},
      { "..", 'I'},
      { ".---", 'J'},
      { "-.-", 'K'},
      { ".-..", 'L'},
      { "--", 'M'},
      { "-.", 'N'},
      { "---", 'O'},
      { ".--.", 'P'},
      { ".-.", 'R'},
      { "...", 'S'},
      { "-", 'T'},
      { "..-", 'U'},
      { "...-", 'V'},
      { "-.--", 'Y'},
      { "-..-", 'X'},
      { "--.-", 'Q'},
      { ".--", 'W'},
      { "--..", 'Z'},
      { "-.-.--", '!'},
      { ".-.-.-", '.'} };

    while (morseCode[0] == ' ')
        morseCode.erase(morseCode.begin());

    for (int32_t x = morseCode.length(); x > 0; --x) {
        if (morseCode[x - 1] == ' ') { morseCode.erase(morseCode.begin() + (x - 1)); }
        else break;
    }

    morseCode += " "; // Adding a little space on the end

    std::string resultant = "";
    std::string substr = "";
    int spaceInRow = 0;

    for (int32_t i = 0; i < morseCode.length(); ++i) {
        if (morseCode[i] == ' ') {
            if (spaceInRow == 0)
                resultant += decodeMorseMap[substr];

            ++spaceInRow;

            if (spaceInRow > 2)
                resultant += ' ';


            if (substr == "...---...") resultant += "SOS";
            substr = "";
        }
        else {
            substr += morseCode[i];
            if (spaceInRow != 0) spaceInRow = 0;
        }
    }
    if (resultant[0] == '\0')
        resultant.erase(resultant.begin());
    std::cout << ">" << resultant << "<" << std::endl;
    return resultant;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << decodeMorse("      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-     ") << "<" << endl;
}