#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> answers;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        queue<int> q;
        int largest = 0;
        for (int s = 1; s < graph.size(); s++)
        {
            if (!visited[s])
            {
                q.push(s);
                int count = 0;
                while (!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    if (!visited[v])
                    {
                        count++;
                        visited[v] = true;
                        for (int w : graph[v])
                        {
                            if (!visited[w])
                            {
                                q.push(w);
                            }
                        }
                    }
                }
                largest = max(largest, count);
            }
        }
        answers.push_back(largest);
    }
    for (int x : answers)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}