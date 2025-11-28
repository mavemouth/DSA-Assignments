#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pii>> adj(V+1);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    int k;
    cin >> k;

    vector<int> dist(V+1, 1e9);
    dist[k] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, k});

    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        for(auto &it : adj[node]) {
            int w = it.first;
            int v = it.second;

            if(d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= V; i++)
        ans = max(ans, dist[i]);

    if(ans >= 1e9) cout << "Not reachable";
    else cout << "Network Delay = " << ans;
}
