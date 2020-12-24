#include <iostream>
#include <string>

using namespace std;

string multiply(string a, string b) {
    if (a.size() == 0 || b.size() == 0) return "0"; 
  
    vector<int> result(a.size() + b.size(), 0); 
    int i1 = 0;  
    int i2 = 0;  
      
    for (int i = a.size() - 1; i >= 0; --i) { 
        int carry = 0; 
        int n1 = a[i] - '0'; 
  
        i2 = 0;  
                 
        for (int j = b.size() - 1; j >= 0; --j) { 
            int n2 = b[j] - '0'; 
            int sum = n1*n2 + result[i1 + i2] + carry; 
          
            carry = sum/10; 
            result[i1 + i2] = sum % 10; 
  
            ++i2; 
        } 
  
        if (carry > 0) result[i1 + i2] += carry; 
  
        ++i1; 
    } 
  
    int i = result.size() - 1; 
    while (i >= 0 && result[i] == 0) --i; 
  
    if (i == -1) return "0"; 
  
    string s = "";   
    while (i >= 0) s += std::to_string(result[i--]); 
    return s; 
}