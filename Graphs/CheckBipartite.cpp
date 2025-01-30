#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, -1);
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (vis[st] == -1) {
            q.push(st);
            vis[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : graph[v]) {
                    if (vis[u] == -1) {
                        vis[u] = vis[v] ^ 1;
                        q.push(u);
                    } 
                    else if (vis[u] == vis[v]) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<vector<int>> graph(n);
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if (isBipartite(graph)) {
        cout << "The graph is bipartite.\n";
    } else {
        cout << "The graph is not bipartite.\n";
    }
    
    return 0;
}
