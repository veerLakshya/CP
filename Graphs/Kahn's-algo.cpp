// Course Schedule CSES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> ans, indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (!indegree[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for (auto nbr : adj[cur]) {
            indegree[nbr]--;
            if (!indegree[nbr]) q.push(nbr);
        }
    }
    if (ans.size() != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (auto i : ans) cout << i << " ";
    return 0;
}
