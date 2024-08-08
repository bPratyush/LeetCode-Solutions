class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;
        int n = grid.size(), m = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 'O' && !vis[nrow][ncol]) dfs(grid, vis, nrow, ncol);
        }
    }

    void solve(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            if (!vis[i][0] && grid[i][0] == 'O') dfs(grid, vis, i, 0);
            if (!vis[i][m-1] && grid[i][m-1] == 'O') dfs(grid, vis, i, m-1);
        }
        for (int j = 0; j < m; ++j) {
            if (!vis[0][j] && grid[0][j] == 'O') dfs(grid, vis, 0, j);
            if (!vis[n-1][j] && grid[n-1][j] == 'O') dfs(grid, vis, n-1, j);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == 'O') grid[i][j] = 'X';
            }
        }
    }
};