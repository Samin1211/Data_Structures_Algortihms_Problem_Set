#include <bits/stdc++.h>
using namespace std;

stack<char> S;

int priority(char s)
{
    if (s == '^')
        return 100;
    else if (s == '*' || s == '/')
        return 50;
    else if (s == '+' || s == '-')
        return 20;
    else
        return 0;
}

int evaluate(string postfix)
{
    stack<int> st;

    for (int i = 0; i < postfix.size(); i++)
    {

        if (postfix[i] == ' ')
            continue;

        if (isdigit(postfix[i]))
        {
            int num = 0;

            while (i < postfix.size() && isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }

            st.push(num);
            i--;
        }

        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int result;

            if (postfix[i] == '+')
                result = a + b;

            else if (postfix[i] == '-')
                result = a - b;

            else if (postfix[i] == '*')
                result = a * b;

            else if (postfix[i] == '/')
                result = a / b;

            else if (postfix[i] == '^')
                result = pow(a, b);

            st.push(result);
        }
    }

    return st.top();
}

int main()
{
    string infix, postfix = "";

    getline(cin, infix);

    for (int i = 0; i < infix.size(); i++)
    {

        char symbol = infix[i];

        if (symbol == ' ')
            continue;

        if (isdigit(symbol))
        {
            while (i < infix.size() && isdigit(infix[i]))
            {
                postfix += infix[i];
                i++;
            }

            postfix += ' ';
            i--;
        }

        else if (symbol == '(')
        {
            S.push(symbol);
        }

        else if (symbol == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                postfix += ' ';
                S.pop();
            }

            if (!S.empty())
                S.pop();
        }

        else if (symbol == '+' || symbol == '-' ||
                 symbol == '*' || symbol == '/' ||
                 symbol == '^')
        {

            while (!S.empty() &&
                   S.top() != '(' &&
                   priority(S.top()) >= priority(symbol))
            {

                postfix += S.top();
                postfix += ' ';
                S.pop();
            }

            S.push(symbol);
        }
    }

    while (!S.empty())
    {
        postfix += S.top();
        postfix += ' ';
        S.pop();
    }

    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluate(postfix) << endl;

    return 0;
}