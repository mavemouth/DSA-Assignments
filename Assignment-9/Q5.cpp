#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int src;
    cin >> src;

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for(auto &p : adj[u]) {
            int w = p.first;
            int v = p.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 0; i < V; i++)
        cout << "Node " << i << " Distance = " << dist[i] << endl;
}
