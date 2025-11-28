#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for(int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.w < b.w;
    });

    DSU dsu(V);

    int cost = 0;
    cout << "Edges in MST:\n";
    for(auto &e : edges) {
        if(dsu.unite(e.u, e.v)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            cost += e.w;
        }
    }

    cout << "Total Cost = " << cost;
}
