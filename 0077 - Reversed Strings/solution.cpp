#include <string>
#include <numeric>
using namespace std; 

string reverseString (string str ) {
  return std::accumulate(str.rbegin(), str.rend(), string{""}, [&](string s, char c){return s + c;});
}