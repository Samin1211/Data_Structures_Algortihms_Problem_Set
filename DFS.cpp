#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[], int start, int n)
{
    vector<bool> marked(n + 1, false);
    stack<int> st;
    st.push(start);
    while (!st.empty())
    {
        int v = st.top();
        st.pop();
        if (!marked[v])
        {
            cout << v << " ";
            marked[v] = true;
            for (int w : graph[v])
            {
                if (!marked[w])
                {
                    st.push(w);
                }
            }
        }
    }
}

vector<int> V[11];

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        V[nodeA].push_back(nodeB);
        V[nodeB].push_back(nodeA);
    }

    cout << endl;

    DFS(V, 1, n);

    return 0;
}