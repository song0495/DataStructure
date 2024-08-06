#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void Reverse(char* Str, int n)
{
    stack<char> StackArray;
    for (int i = 0; i < n; ++i) {
        StackArray.push(Str[i]);
    }
    for (int i = 0; i < n; ++i) {
        Str[i] = StackArray.top();
        StackArray.pop();
    }
}

int main()
{
    char Str[51];
    cout << "Enter a string" << endl;
    cin >> Str;
    Reverse(Str, strlen(Str));
    cout << Str << endl;
}