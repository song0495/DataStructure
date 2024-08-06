#include <iostream>
#include <stack>
#include <string>
using namespace std;

double EvaluatePostfix(string exp)
{
    stack<double> Stack;
    string Empty = "."; // 数字和操作符的分隔
    string str = "0123456789+-*/";
    int start, end;
    double result, op1, op2;
    for (int i = 0; i < exp.length(); i = end + 1)
    {
        start = exp.find_first_of(str, i);
        end = exp.find_first_of(Empty, i);
        if (end == -1)
            end = exp.length();
        
        string temp = exp.substr(start, end - start);
        if ((temp == "+") || (temp == "-") || (temp == "*") || (temp == "/"))
        {
            op2 = Stack.top();
            Stack.pop();
            op1 = Stack.top();
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
    cout << EvaluatePostfix(exp) << endl;
}