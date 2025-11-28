#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    cout << node << " ";

    for(int nbr : adj[node]) {
        if(!vis[nbr])
            DFS(nbr, adj, vis);
    }
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Start vertex: ";
    cin >> start;

    vector<bool> visited(V, false);
    DFS(start, adj, visited);
}
