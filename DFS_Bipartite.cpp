#include <bits/stdc++.h>
using namespace std;

bool DFS_Bipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1);
    stack<int> st;
    for (int s = 1; s < graph.size(); s++)
    {
        if (color[s] == -1)
        {
            color[s] = 0;
            st.push(s);
            while (!st.empty())
            {
                int v = st.top();
                st.pop();
                for (int w : graph[v])
                {
                    if (color[w] == -1)
                    {
                        color[w] = 1 - color[v];
                        st.push(w);
                    }
                    else if (color[w] == color[v])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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
        graph[b].push_back(a);
    }
    if (DFS_Bipartite(graph))
    {
        cout << "Bi-Partite" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}