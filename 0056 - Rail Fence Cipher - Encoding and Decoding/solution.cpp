#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

std::string encode_rail_fence_cipher(std::string str, int n) {
    if (str == "") return "";

    std::vector<std::string> arr(n, "");
    int strLength = 0;
    int stringIter = 0;
    bool down = true;

    while (stringIter < str.length()) {
        arr[strLength] += str[stringIter];

        (down) ? ++strLength : --strLength;
        if (strLength == 0) { down = true; strLength = 0;}
        else if (strLength % n == 0) { down = false; ----strLength;}

        ++stringIter;
    }

    string throwback = "";
    for (auto x : arr)
        throwback += x;

    return throwback;
}

std::string decode_rail_fence_cipher(std::string str, int n) {
    if (str == "") return "";

    std::vector<std::string> arr(n, "");
    int strLength = 0;
    
    for (int i = 0; i < n; ++i)
        for (int ii = 0; ii < str.length(); ++ii)
            arr[i] += '\n';

    bool down = false;

    int row = 0, col = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (row == 0 || row == n - 1) down = !down;
        arr[row][col++] = '*';
        (down) ? ++row : --row;
    }

    int idx = 0;
    for (int i = 0; i < n; ++i)
        for (int ii = 0; ii < str.length(); ++ii)
            if (arr[i][ii] == '*' && idx < str.length())
                arr[i][ii] = str[idx++];


    string throwback = "";

    row = 0; col = 0;
    for (int stringIter = 0; stringIter < str.length(); ++stringIter) {
        if (row == 0) down = true;
        else if (row == n - 1) down = false;
        
        if (arr[row][col] != '*')
            throwback += arr[row][col++];

        (down) ? ++row : --row;
    }

    return throwback;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << encode_rail_fence_cipher("WEAREDISCOVEREDFLEEATONCE", 3) << " " << "WECRLTEERDSOEEFEAOCAIVDEN" << endl;
    cout << encode_rail_fence_cipher("Hello, World!", 3) << " " << "Hoo!el,Wrdl l" << endl;
    cout << encode_rail_fence_cipher("Hello, World!", 4) << " " << "H !e,Wdloollr" << endl;
    cout << encode_rail_fence_cipher("", 3) << " " << "" << endl;

    cout << "Encryption works" << endl;
    cout << decode_rail_fence_cipher("H !e,Wdloollr", 4) << " " << "Hello, World!" << endl;
    cout << decode_rail_fence_cipher("WECRLTEERDSOEEFEAOCAIVDEN", 3) << " " << "WEAREDISCOVEREDFLEEATONCE" << endl;
    cout << decode_rail_fence_cipher("", 3) << " " << "" << endl;
    return 0;
}