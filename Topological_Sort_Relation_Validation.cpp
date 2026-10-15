#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char relation;

        cin >> a >> relation >> b;

        if (relation == '<')
        {
            graph[a].push_back(b);
            indegree[b]++;
        }
        else if (relation == '>')
        {
            graph[b].push_back(a);
            indegree[a]++;
        }
    }
    queue<int> q;
    for (int i = 1; i < graph.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        count++;
        for (int w : graph[v])
        {
            indegree[w]--;
            if (indegree[w] == 0)
            {
                q.push(w);
            }
        }
    }
    if (count == n)
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}