#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii; // (weight, vertex)

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

    vector<bool> mst(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 0});
    int cost = 0;

    while(!pq.empty()) {
        auto [w, node] = pq.top();
        pq.pop();

        if(mst[node]) continue;
        mst[node] = true;
        cost += w;

        for(auto &edge : adj[node]) {
            int wt = edge.first;
            int v = edge.second;
            if(!mst[v]) pq.push({wt, v});
        }
    }

    cout << "Total cost = " << cost;
}
