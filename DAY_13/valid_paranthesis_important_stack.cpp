#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
bool isValid(string expression)
{
    stack<char> arr;
    if (expression.length() == 1 or expression.length() == 0)
        return false;
    else
    {
        for (int i = 0; i < expression.length(); i++)
        {
            if (arr.empty())
            {
                arr.push(expression[i]);
                continue;
            }
            if (expression[i] == '(' or expression[i] == '[' or expression[i] == '{')
            {
                arr.push(expression[i]);
            }
            else if (expression[i] == ')' or expression[i] == ']' or expression[i] == '}')
            {
                if (!arr.empty())
                {
                    if (expression[i] == ')' and arr.top() == '(')
                        arr.pop();
                    else if (expression[i] == '}' and arr.top() == '{')
                        arr.pop();
                    else if (expression[i] == ']' and arr.top() == '[')
                        arr.pop();
                    else
                        return false;
                }
            }
        }
    }
    if (arr.empty())
        return true;
    else
        return false;
}    
int main()
{
    string expression;
    cin>>expression;
    isValid(expression) == true ? cout << "True"<< "\n": cout << "False"<< "\n" ;
    return 0;
}

/*
https://leetcode.com/problems/valid-parentheses/
https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104
*/