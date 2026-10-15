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
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i < graph.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> answer;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        answer.push_back(v);
        for (int w : graph[v])
        {
            indegree[w]--;
            if (indegree[w] == 0)
            {
                q.push(w);
            }
        }
    }
    if (answer.size() != n)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}