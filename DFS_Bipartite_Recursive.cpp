#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> &graph, int v, vector<int> &color)
{
    for (int w : graph[v])
    {
        if (color[w] == -1)
        {
            color[w] = 1 - color[v];
            if (!DFS(graph, w, color))
            {
                return false;
            }
        }
        else if (color[w] == color[v])
        {
            return false;
        }
    }
    return true;
}

bool Bipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1);
    for (int s = 1; s < graph.size(); s++)
    {
        if (color[s] == -1)
        {
            color[s] = 0;
            if (!DFS(graph, s, color))
            {
                return false;
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
    if (Bipartite(graph))
    {
        cout << "Bi-Partite" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}