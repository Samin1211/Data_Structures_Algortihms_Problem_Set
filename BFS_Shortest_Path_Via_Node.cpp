#include <bits/stdc++.h>
using namespace std;

int BFS(vector<vector<int>> &graph, int source, int destination)
{
    vector<int> dist(graph.size(), -1);
    queue<int> q;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (v == destination)
        {
            return dist[v];
        }
        for (int w : graph[v])
        {
            if (dist[w] == -1)
            {
                dist[w] = 1 + dist[v];
                q.push(w);
            }
        }
    }
    return -1;
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
    int source, via, destination;
    cin >> source >> via >> destination;
    int d1 = BFS(graph, source, via);
    int d2 = BFS(graph, via, destination);
    if (d1 == -1 || d2 == -1)
    {
        cout << "Path doesn't exist" << endl;
        return 0;
    }
    cout << "Shortest path: " << d1 + d2 << endl;
    return 0;
}