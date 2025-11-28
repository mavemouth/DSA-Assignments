#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<char>>& grid) {
    if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()) return;
    if(grid[r][c] == '0') return;

    grid[r][c] = '0';

    dfs(r+1, c, grid);
    dfs(r-1, c, grid);
    dfs(r, c+1, grid);
    dfs(r, c-1, grid);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int count = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == '1') {
                dfs(i, j, grid);
                count++;
            }

    cout << "Number of islands = " << count;
}
