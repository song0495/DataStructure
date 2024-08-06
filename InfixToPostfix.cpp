#include<iostream>
#include<stack>
#include<string>
using namespace std;

string InfixToPostfix(string expression);
int HasHigherPrecedence(char operator1, char operator2); 
bool IsOperator(char C);
bool IsOperand(char C);

string InfixToPostfix(string expression)
{
    stack<char> S;
    string postfix = "";
    for (int i = 0;i < expression.length(); i++) {
        if (expression[i] == ' ' || expression[i] == ',') continue; // 遇到分隔符' '或者','
        else if (IsOperator(expression[i]))
        {
            while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
            // 1. 栈不为空 2. 栈顶不为'(' 3. 栈顶操作符有更高的优先级
            // 则将栈顶的操作符写入postfix并pop出栈
            {
                postfix += S.top();
                S.pop();
            }
            S.push(expression[i]); // 常规操作符则直接push进栈
        }
        else if (IsOperand(expression[i])) // 操作数直接push进栈
        {
            postfix += expression[i];
        }

        else if (expression[i] == '(') // '('直接push进栈
        {
            S.push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            while (!S.empty() && S.top() != '(') {
            // 如果是')', 栈不为空且栈顶不为'(', 则将栈顶的操作符写入postfix
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }

    while (!S.empty()) { // 栈中剩余操作符
        postfix += S.top();
        S.pop();
    }

    return postfix;
}

bool IsOperand(char C)
{
    if (C >= '0' && C <= '9') return true;
    if (C >= 'a' && C <= 'z') return true;
    if (C >= 'A' && C <= 'Z') return true;
    return false;
}

bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return true;

    return false;
}

int IsRightAssociative(char op)
{
    if (op == '$') return true;
    return false;
}

int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
    case '*':
    case '/':
        weight = 2;
    case '$':
        weight = 3;
    }
    return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    if (op1Weight == op2Weight) 
    // 操作符优先级相同, 则关注操作符的进栈先后, 先进栈的优先级高, 可以直接pop出栈
    // 操作符优先级相同的话, 表达式计算顺序从左到右
    {
        if (IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ? true : false;
}

int main()
{
    string expression;
    cout << "Enter Infix Expression \n";
    getline(cin, expression);
    string postfix = InfixToPostfix(expression);
    cout << "Output = " << postfix << "\n";
}