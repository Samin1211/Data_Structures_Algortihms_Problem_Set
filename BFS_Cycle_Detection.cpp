#include <bits/stdc++.h>
using namespace std;

bool Cycle_Detection(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    for (int i = 1; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1});
            visited[i] = true;
            while (!q.empty())
            {
                int u = q.front().first;
                int parent = q.front().second;
                q.pop();
                for (int v : graph[u])
                {
                    if (visited[v] && v != parent)
                    {
                        return true;
                    }
                    else if (!visited[v])
                    {
                        visited[v] = true;
                        q.push({v, u});
                    }
                }
            }
        }
    }
    return false;
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
    if (Cycle_Detection(graph))
    {
        cout << "Cycle" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}