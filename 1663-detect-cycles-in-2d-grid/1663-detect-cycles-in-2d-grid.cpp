class Solution {
public:
    bool bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int sr, int sc) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> dr = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{sr, sc}, {-1, -1}});
        vis[sr][sc] = 1;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int pr = q.front().second.first;
            int pc = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i].first;
                int nc = c + dr[i].second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == grid[r][c]) {
                    if (!vis[nr][nc]) {
                        q.push({{nr, nc}, {r, c}});
                        vis[nr][nc] = 1;
                    } else if (nr != pr || nc != pc) {
                        return true;  
                    }
                }
            }
        }
        return false; 
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (bfs(grid, vis, i, j)) return true;
                }
            }
        }

        return false;
    }
};
