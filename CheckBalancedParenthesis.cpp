#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool Pair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    return false;
}

bool CheckBalancedParenthesis(string& str)
{
    stack<char> Str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Str.push(str[i]);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (Str.empty() || !Pair(Str.top(), str[i])) // 栈中为空或者右括号和栈顶不匹配
                return false;
            else
                Str.pop();
        }
    }
    return Str.empty() ? true : false;
}

int main()
{
    string str;
    cout << "enter the str" << endl;
    cin >> str;
    if(CheckBalancedParenthesis(str))
        cout << "match" << endl;
    else
        cout << "do'nt match" << endl;
}