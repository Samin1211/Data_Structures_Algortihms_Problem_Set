#include <bits/stdc++.h>
using namespace std;

void DFS_VISIT(vector<vector<int>> &graph, int v, vector<bool> &visited, stack<int> &st)
{
    visited[v] = true;
    for (int u : graph[v])
    {
        if (!visited[u])
        {
            DFS_VISIT(graph, u, visited, st);
        }
    }
    st.push(v);
}

void TOPOLOGICAL_SORT(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    stack<int> st;
    for (int v = 1; v < graph.size(); v++)
    {
        if (!visited[v])
        {
            DFS_VISIT(graph, v, visited, st);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    TOPOLOGICAL_SORT(graph);
    return 0;
}