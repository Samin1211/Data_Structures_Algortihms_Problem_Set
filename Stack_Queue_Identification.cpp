#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> st;
    queue<int> q;

    bool isStack = true;
    bool isQueue = true;

    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            st.push(x);
            q.push(x);
        }
        else
        {
            int x;
            cin >> x;
            if (st.empty())
            {
                isStack = false;
            }
            else
            {
                if (st.top() != x)
                {
                    isStack = false;
                }
                st.pop();
            }
            if (q.empty())
            {
                isQueue = false;
            }
            else
            {
                if (q.front() != x)
                {
                    isQueue = false;
                }
                q.pop();
            }
        }
    }
    if (isStack && !isQueue)
    {
        cout << "Stack" << endl;
    }
    else if (!isStack && isQueue)
    {
        cout << "Queue" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}