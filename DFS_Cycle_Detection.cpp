#include <bits/stdc++.h>
using namespace std;

bool DFS(int v, int parent, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &parentNode, int &cycleStart, int &cycleEnd)
{
    visited[v] = true;
    for (int w : graph[v])
    {
        if (w == parent)
        {
            continue;
        }
        if (!visited[w])
        {
            parentNode[w] = v;
            if (DFS(w, v, graph, visited, parentNode, cycleStart, cycleEnd))
            {
                return true;
            }
        }
        else
        {
            cycleStart = w;
            cycleEnd = v;
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(graph.size(), 0);
    vector<int> parentNode(graph.size(), -1);
    int cycleStart = -1;
    int cycleEnds = -1;
    for (int s = 1; s < graph.size(); s++)
    {
        if (!visited[s])
        {
            if (DFS(s, -1, graph, visited, parentNode, cycleStart, cycleEnds))
            {
                break;
            }
        }
    }
    if (cycleStart == -1)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> cycle;
    cycle.push_back(cycleStart);
    int current = cycleEnds;

    while (current != cycleStart)
    {
        cycle.push_back(current);
        current = parentNode[current];
    }

    cycle.push_back(cycleStart);
    cout << cycle.size() << endl;
    for (int x : cycle)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}