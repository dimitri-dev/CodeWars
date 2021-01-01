#include <stack>

bool valid_braces(std::string s) {
  std::stack<char> stk;
  for (long i = 0; i < s.length(); ++i) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') stk.push(s[i]);
        else if (stk.empty() == false) {
          if ((s[i] == '}' && stk.top() == '{') ||
             (s[i] == ']' && stk.top() == '[') ||
             (s[i] == ')' && stk.top() == '(')) stk.pop();
          else
            return false;
        }
        else
            return false;
  }
  return stk.size() == 0;
}