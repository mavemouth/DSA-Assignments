#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii; // (cost, index)

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0});

    int dr[] = {0,1,0,-1};
    int dc[] = {1,0,-1,0};

    while(!pq.empty()) {
        auto [d, idx] = pq.top(); pq.pop();
        int r = idx / n, c = idx % n;

        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n) {
                int nd = d + grid[nr][nc];
                if(nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr*n + nc});
                }
            }
        }
    }

    cout << "Minimum cost = " << dist[m-1][n-1];
}
