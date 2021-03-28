#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <locale>

using namespace std;

int oper(char c)
{
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    else return 0;
}

string to_postfix(std::string infix)
{
    stack<char> nms;
    nms.push('$'); // null exception avoided in VS

    string postfix = "";

    for (auto c : infix)
    {
        if (isalnum(c)) postfix += c;
        else if (c == '(') nms.push('(');
        else if (c == '^') nms.push('^');
        else if (c == ')')
        {
            while (nms.top() != '$' && nms.top() != '(') { postfix += nms.top(); nms.pop(); }
            nms.pop();
        }
        else
        {
            while (nms.top() != '$' && oper(c) <= oper(nms.top())) { postfix += nms.top(); nms.pop(); }
            nms.push(c);
        }
    }

    while (nms.top() != '$') { postfix += nms.top(); nms.pop(); }

    return postfix;
}