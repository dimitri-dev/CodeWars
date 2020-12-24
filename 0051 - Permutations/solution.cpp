#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> permutations(string s) {
  vector<string> retVal;
  sort(s.begin(), s.end());
  do {  
    retVal.push_back(s); 
  } while(next_permutation(s.begin(), s.end()));  
  return retVal;
}