#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
constexpr int inf = 1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> g(n, vector<vector<int>>('z' - 'a' + 1));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--, b--;
        g[a][c - 'a'].emplace_back(b);
        g[b][c - 'a'].emplace_back(a);
    }

    vector<vector<int>> dist(n, vector<int>(n, inf));
    queue<pair<int, int>> que;

    que.emplace(0, n - 1);
    dist[0][n - 1] = 0;
    while (que.size())
    {
        int u, v;
        tie(u, v) = que.front();
        que.pop();

        for (int c = 0; c <= 'z' - 'a'; c++)
            for (auto &nu : g[u][c])
                for (auto &nv : g[v][c])
                {
                    if (dist[nu][nv] != inf)
                        continue;
                    dist[nu][nv] = dist[u][v] + 1;

                    que.emplace(nu, nv);
                }
    }

    int ans = inf;
    for (int v = 0; v < n; v++)
    {
        ans = min(ans, dist[v][v] << 1);
    }

    for (int v = 0; v < n; v++)
        for (int c = 0; c <= 'z' - 'a'; c++)
            for (auto &u : g[v][c])
            {
                ans = min(ans, (dist[v][u] << 1) + 1);
            }
    cout << (ans >= inf ? -1 : ans) << '\n';
}