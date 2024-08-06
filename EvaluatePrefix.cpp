#include <iostream>
#include <stack>
#include <string>
using namespace std;

double EvaluatePrefix(string exp)
{
    stack<double> Stack;
    string Empty = "."; // 数字和操作符的分隔
    string str = "0123456789+-*/";
    int start, end;
    double result, op1, op2;
    for (int i = 0; i < exp.length(); i = exp.length() - end + 2)
    {
        start = exp.find_first_of(str, exp.length() - i - 1); // 从表达式末尾开始找
        end = exp.find_first_of(Empty, exp.length() - i - 1);
        if (end == -1)
            end = exp.length();

        string temp = exp.substr(start, end - start);
        if ((temp == "+") || (temp == "-") || (temp == "*") || (temp == "/"))
        {
            op1 = Stack.top(); // 操作数取出顺序与后缀相反
            Stack.pop();
            op2 = Stack.top();
            Stack.pop();

            if (temp == "+")
            {
                result = op1 + op2;
                Stack.push(result);
            }
            else if (temp == "-")
            {
                result = op1 - op2;
                Stack.push(result);
            }
            else if (temp == "*")
            {
                result = op1 * op2;
                Stack.push(result);
            }
            else
            {
                result = op1 / op2;
                Stack.push(result);
            }
        }
        else
        {
            double num = stod(temp);
            Stack.push(num);
        }
    }

    return Stack.top();
}

int main()
{
    string exp;
    cout << "enter the exp" << endl;
    cin >> exp;
    cout << "result: " << endl;
    cout << EvaluatePrefix(exp) << endl;
}