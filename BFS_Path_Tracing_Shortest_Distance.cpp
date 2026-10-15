#include <bits/stdc++.h>
using namespace std;

int BFS(vector<vector<int>> &graph, int source, int destination)
{
    vector<int> dist(graph.size(), -1);
    vector<int> parent(graph.size(), -1);
    queue<int> q;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : graph[v])
        {
            if (dist[w] == -1)
            {
                dist[w] = 1 + dist[v];
                parent[w] = v;
                q.push(w);
            }
        }
    }
    if (dist[destination] == -1)
    {
        cout << "Path doesn't exist" << endl;
        return 0;
    }

    cout << "Shortest Distance: " << dist[destination] << endl;

    vector<int> path;
    int current = destination;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;
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
    int source, destination;
    cin >> source >> destination;
    BFS(graph, source, destination);
    return 0;
}